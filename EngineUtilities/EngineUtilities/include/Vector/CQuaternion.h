#pragma once

#include "../Utilities/EngineMath.h"
#include "../Vector/CVector3.h"
#include <ostream>

namespace EngineUtilities {

    /**
     * @brief Representa un cuaternión para rotaciones en 3D.
     * @author Hannin Abarca
     */
    class CQuaternion {
    public:
        float x, y, z, w;

        /** @brief Constructor por defecto. Inicializa como cuaternión identidad. */
        CQuaternion() : x(0), y(0), z(0), w(1) {}

        /**
         * @brief Constructor con componentes específicos.
         */
        CQuaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        /**
         * @brief Accede al componente por índice.
         */
        float& operator[](int index) {
            switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: return w;
            }
        }

        /**
         * @brief Acceso constante al componente por índice.
         */
        const float& operator[](int index) const {
            switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: return w;
            }
        }

        /**
         * @brief Compara si dos cuaterniones son iguales.
         */
        bool operator==(const CQuaternion& other) const {
            return EngineUtilities::approxEqual(x, other.x) &&
                EngineUtilities::approxEqual(y, other.y) &&
                EngineUtilities::approxEqual(z, other.z) &&
                EngineUtilities::approxEqual(w, other.w);
        }

        /**
         * @brief Compara si dos cuaterniones son distintos.
         */
        bool operator!=(const CQuaternion& other) const {
            return !(*this == other);
        }

        /**
         * @brief Suma dos cuaterniones.
         */
        CQuaternion operator+(const CQuaternion& q) const {
            return CQuaternion(x + q.x, y + q.y, z + q.z, w + q.w);
        }

        /**
         * @brief Resta dos cuaterniones.
         */
        CQuaternion operator-(const CQuaternion& q) const {
            return CQuaternion(x - q.x, y - q.y, z - q.z, w - q.w);
        }

        /**
         * @brief Multiplica dos cuaterniones.
         */
        CQuaternion operator*(const CQuaternion& q) const {
            return CQuaternion(
                w * q.x + x * q.w + y * q.z - z * q.y,
                w * q.y - x * q.z + y * q.w + z * q.x,
                w * q.z + x * q.y - y * q.x + z * q.w,
                w * q.w - x * q.x - y * q.y - z * q.z
            );
        }

        /**
         * @brief Multiplica el cuaternión por un escalar.
         */
        CQuaternion operator*(float scalar) const {
            return CQuaternion(x * scalar, y * scalar, z * scalar, w * scalar);
        }

        /**
         * @brief Retorna el cuadrado de la magnitud del cuaternión.
         */
        float lengthSquare() const {
            return x * x + y * y + z * z + w * w;
        }

        /**
         * @brief Retorna la magnitud del cuaternión.
         */
        float length() const {
            return static_cast<float>(EngineUtilities::sqrt(lengthSquare()));
        }

        /**
         * @brief Producto punto con otro cuaternión.
         */
        float dot(const CQuaternion& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        /**
         * @brief Normaliza el cuaternión (modifica el actual).
         */
        void normalize() {
            float mag = length();
            if (mag > 0.0f) {
                x /= mag; y /= mag; z /= mag; w /= mag;
            }
            else {
                x = y = z = w = 0.0f;
            }
        }

        /**
         * @brief Retorna una copia normalizada del cuaternión.
         */
        CQuaternion normalized() const {
            CQuaternion result = *this;
            result.normalize();
            return result;
        }

        /**
         * @brief Retorna el conjugado del cuaternión.
         */
        CQuaternion conjugate() const {
            return CQuaternion(-x, -y, -z, w);
        }

        /**
         * @brief Rota un vector utilizando el cuaternión.
         */
        CVector3 rotate(const CVector3& v) const {
            CQuaternion vec(v.x, v.y, v.z, 0.0f);
            CQuaternion resQuat = (*this) * vec * conjugate();
            return CVector3(resQuat.x, resQuat.y, resQuat.z);
        }

        /**
         * @brief Crea un cuaternión desde un eje y ángulo (en radianes).
         */
        static CQuaternion fromAxisAngle(const CVector3& axis, float angleRad) {
            float halfAngle = angleRad * 0.5f;
            float s = static_cast<float>(EngineUtilities::sin(halfAngle));
            float c = static_cast<float>(EngineUtilities::cos(halfAngle));
            return CQuaternion(axis.x * s, axis.y * s, axis.z * s, c);
        }

        /**
         * @brief Interpolación esférica entre dos cuaterniones.
         */
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

        /**
         * @brief Retorna el cuaternión identidad.
         */
        static CQuaternion identity() {
            return CQuaternion(0.0f, 0.0f, 0.0f, 1.0f);
        }

        /**
         * @brief Retorna un cuaternión nulo.
         */
        static CQuaternion zero() {
            return CQuaternion(0.0f, 0.0f, 0.0f, 0.0f);
        }
    };
}

/**
 * @brief Sobrecarga del operador << para imprimir un cuaternión.
 */
inline std::ostream& operator<<(std::ostream& os, const EngineUtilities::CQuaternion& q) {
    os << "CQuaternion(" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << ")";
    return os;
}
