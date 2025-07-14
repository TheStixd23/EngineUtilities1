#pragma once

#include "../Utilities/EngineMath.h"
#include <ostream>

namespace EngineUtilities {

    /**
     * @author Hannin Abarca
     * @class CVector4
     * @brief Representa un vector de 4 dimensiones con componentes x, y, z y w.
     *
     * Ofrece operaciones aritméticas, normalización, producto punto y utilidades
     * como interpolación lineal y distancia. Ideal para álgebra lineal en motores gráficos.
     */
    class CVector4 {
    public:
        float x, y, z, w;

        /**
         * @brief Constructor por defecto. Inicializa todos los componentes a 0.
         */
        CVector4() : x(0), y(0), z(0), w(0) {}

        /**
         * @brief Constructor por componentes.
         * @param x Componente X.
         * @param y Componente Y.
         * @param z Componente Z.
         * @param w Componente W.
         */
        CVector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        /// @name Operaciones aritméticas
        /// @{

        CVector4 operator+(const CVector4& other) const {
            return CVector4(x + other.x, y + other.y, z + other.z, w + other.w);
        }

        CVector4 operator-(const CVector4& other) const {
            return CVector4(x - other.x, y - other.y, z - other.z, w - other.w);
        }

        CVector4 operator*(float scalar) const {
            return CVector4(x * scalar, y * scalar, z * scalar, w * scalar);
        }

        CVector4 operator/(float scalar) const {
            return CVector4(x / scalar, y / scalar, z / scalar, w / scalar);
        }

        CVector4& operator+=(const CVector4& other) {
            x += other.x; y += other.y; z += other.z; w += other.w;
            return *this;
        }

        CVector4& operator-=(const CVector4& other) {
            x -= other.x; y -= other.y; z -= other.z; w -= other.w;
            return *this;
        }

        CVector4& operator*=(float scalar) {
            x *= scalar; y *= scalar; z *= scalar; w *= scalar;
            return *this;
        }

        CVector4& operator/=(float scalar) {
            x /= scalar; y /= scalar; z /= scalar; w /= scalar;
            return *this;
        }

        /// @}

        /// @name Comparación
        /// @{

        bool operator==(const CVector4& other) const {
            return EngineUtilities::approxEqual(x, other.x) &&
                EngineUtilities::approxEqual(y, other.y) &&
                EngineUtilities::approxEqual(z, other.z) &&
                EngineUtilities::approxEqual(w, other.w);
        }

        bool operator!=(const CVector4& other) const {
            return !(*this == other);
        }

        /// @}

        /// @name Acceso por índice
        /// @{

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

        /// @}

        /// @name Propiedades vectoriales
        /// @{

        float lengthSquare() const {
            return x * x + y * y + z * z + w * w;
        }

        float length() const {
            return (float)EngineUtilities::sqrt(lengthSquare());
        }

        float dot(const CVector4& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        CVector4 normalized() const {
            float len = length();
            return (len == 0.f) ? CVector4(0.f, 0.f, 0.f, 0.f) : (*this) / len;
        }

        void normalize() {
            float len = length();
            if (len != 0.f) {
                x /= len; y /= len; z /= len; w /= len;
            }
            else {
                x = y = z = w = 0.f;
            }
        }

        /// @}

        /// @name Funciones estáticas
        /// @{

        static float distance(const CVector4& a, const CVector4& b) {
            return (b - a).length();
        }

        static CVector4 lerp(const CVector4& a, const CVector4& b, float t) {
            return a + (b - a) * t;
        }

        static CVector4 zero() {
            return CVector4(0.f, 0.f, 0.f, 0.f);
        }

        static CVector4 one() {
            return CVector4(1.f, 1.f, 1.f, 1.f);
        }

        /// @}

        /**
         * @brief Imprime el vector en el formato "CVector4(x, y, z, w)".
         */
        friend std::ostream& operator<<(std::ostream& os, const CVector4& v) {
            os << "CVector4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
            return os;
        }
    };

}
