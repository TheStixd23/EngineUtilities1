#pragma once
#include "../Utilities/EngineMath.h"
#include <ostream>

namespace EngineUtilities {

    class CVector2 {
    public:
        float x, y;

        CVector2() : x(0), y(0) {}
        CVector2(float x, float y) : x(x), y(y) {}

        CVector2 operator+(const CVector2& other) const {
            return CVector2(x + other.x, y + other.y);
        }

        CVector2 operator-(const CVector2& other) const {
            return CVector2(x - other.x, y - other.y);
        }

        CVector2 operator*(float scalar) const {
            return CVector2(x * scalar, y * scalar);
        }

        CVector2 operator/(float scalar) const {
            return CVector2(x / scalar, y / scalar);
        }

        CVector2& operator+=(const CVector2& other) {
            x += other.x; y += other.y;
            return *this;
        }

        CVector2& operator-=(const CVector2& other) {
            x -= other.x; y -= other.y;
            return *this;
        }

        CVector2& operator*=(float scalar) {
            x *= scalar; y *= scalar;
            return *this;
        }

        CVector2& operator/=(float scalar) {
            x /= scalar; y /= scalar;
            return *this;
        }

        bool operator==(const CVector2& other) const {
            return EngineUtilities::approxEqual(x, other.x) && EngineUtilities::approxEqual(y, other.y);
        }

        bool operator!=(const CVector2& other) const {
            return !(*this == other);
        }

        float& operator[](int index) {
            return (index == 0) ? x : y;
        }

        const float& operator[](int index) const {
            return (index == 0) ? x : y;
        }

        float lengthSquare() const {
            return x * x + y * y;
        }

        float length() const {
            return (float)EngineUtilities::sqrt(lengthSquare());
        }

        float dot(const CVector2& other) const {
            return x * other.x + y * other.y;
        }

        float cross(const CVector2& other) const {
            return x * other.y - y * other.x;
        }

        CVector2 normalized() const {
            float len = length();
            return (len == 0.f) ? CVector2(0.f, 0.f) : (*this) / len;
        }

        void normalize() {
            float len = length();
            if (len != 0.f) {
                x /= len; y /= len;
            }
            else {
                x = y = 0.f;
            }
        }

        inline static float distance(const CVector2& a, const CVector2& b) {
            return (float)EngineUtilities::sqrt((b - a).lengthSquare());
        }

        inline static CVector2 lerp(const CVector2& a, const CVector2& b, float t) {
            return a + (b - a) * t;
        }

        inline static CVector2 zero() {
            return CVector2(0.f, 0.f);
        }

        inline static CVector2 one() {
            return CVector2(1.f, 1.f);
        }

        void setPosition(const CVector2& position) {
            x = position.x;
            y = position.y;
        }

        void move(const CVector2& offset) {
            x += offset.x;
            y += offset.y;
        }

        void setScale(const CVector2& factors) {
            x *= factors.x;
            y *= factors.y;
        }

        void scale(const CVector2& factors) {
            x *= factors.x;
            y *= factors.y;
        }

        void setOrigin(const CVector2& origin) {
            x = origin.x;
            y = origin.y;
        }

        friend std::ostream& operator<<(std::ostream& os, const CVector2& v) {
            os << "CVector2(" << v.x << ", " << v.y << ")";
            return os;
        }
    };

}
