#pragma once

#include "../Utilities/EngineMath.h"
#include "../Vector/CVector3.h"
#include <ostream>

namespace EngineUtilities {

    class CQuaternion {
    public:
        float x, y, z, w;

        CQuaternion() : x(0), y(0), z(0), w(1) {}
        CQuaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        CQuaternion operator+(const CQuaternion& q) const {
            return CQuaternion(x + q.x, y + q.y, z + q.z, w + q.w);
        }

        CQuaternion operator-(const CQuaternion& q) const {
            return CQuaternion(x - q.x, y - q.y, z - q.z, w - q.w);
        }

        CQuaternion operator*(const CQuaternion& q) const {
            return CQuaternion(
                w * q.x + x * q.w + y * q.z - z * q.y,
                w * q.y - x * q.z + y * q.w + z * q.x,
                w * q.z + x * q.y - y * q.x + z * q.w,
                w * q.w - x * q.x - y * q.y - z * q.z
            );
        }

        CQuaternion operator*(float scalar) const {
            return CQuaternion(x * scalar, y * scalar, z * scalar, w * scalar);
        }

        float& operator[](int index) {
            switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: return w;
            }
        }

        const float& operator[](int index) const {
            switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: return w;
            }
        }

        bool operator==(const CQuaternion& other) const {
            return EngineUtilities::approxEqual(x, other.x) &&
                EngineUtilities::approxEqual(y, other.y) &&
                EngineUtilities::approxEqual(z, other.z) &&
                EngineUtilities::approxEqual(w, other.w);
        }

        bool operator!=(const CQuaternion& other) const {
            return !(*this == other);
        }

        float lengthSquare() const {
            return x * x + y * y + z * z + w * w;
        }

        float length() const {
            return static_cast<float>(EngineUtilities::sqrt(lengthSquare()));
        }

        float dot(const CQuaternion& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        void normalize() {
            float mag = static_cast<float>(EngineUtilities::sqrt(lengthSquare()));
            if (mag > 0.0f) {
                x /= mag; y /= mag; z /= mag; w /= mag;
            }
            else {
                x = y = z = w = 0.0f;
            }
        }

        CQuaternion normalized() const {
            CQuaternion result = *this;
            result.normalize();
            return result;
        }

        CQuaternion conjugate() const {
            return CQuaternion(-x, -y, -z, w);
        }

        static CQuaternion fromAxisAngle(const CVector3& axis, float angleRad) {
            float halfAngle = angleRad * 0.5f;
            float s = static_cast<float>(EngineUtilities::sin(halfAngle));
            float c = static_cast<float>(EngineUtilities::cos(halfAngle));
            return CQuaternion(axis.x * s, axis.y * s, axis.z * s, c);
        }

        static CQuaternion slerp(const CQuaternion& a, const CQuaternion& b, float t) {
            float dot = a.dot(b);
            CQuaternion bAdjusted = b;

            if (dot < 0.0f) {
                dot = -dot;
                bAdjusted = b * -1.0f;
            }

            if (dot > 0.9995f) {
                return (a + (bAdjusted - a) * t).normalized();
            }

            float theta_0 = static_cast<float>(EngineUtilities::acos(dot));
            float theta = theta_0 * t;

            float sin_theta = static_cast<float>(EngineUtilities::sin(theta));
            float sin_theta_0 = static_cast<float>(EngineUtilities::sin(theta_0));

            float s0 = static_cast<float>(EngineUtilities::cos(theta)) - dot * sin_theta / sin_theta_0;
            float s1 = sin_theta / sin_theta_0;

            return (a * s0 + bAdjusted * s1).normalized();
        }

        static CQuaternion identity() {
            return CQuaternion(0.0f, 0.0f, 0.0f, 1.0f);
        }

        static CQuaternion zero() {
            return CQuaternion(0.0f, 0.0f, 0.0f, 0.0f);
        }

        CVector3 rotate(const CVector3& v) const {
            CQuaternion vec(v.x, v.y, v.z, 0.0f);
            CQuaternion resQuat = (*this) * vec * conjugate();
            return CVector3(resQuat.x, resQuat.y, resQuat.z);
        }
    };

}

inline std::ostream& operator<<(std::ostream& os, const EngineUtilities::CQuaternion& q) {
    os << "CQuaternion(" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << ")";
    return os;
}
