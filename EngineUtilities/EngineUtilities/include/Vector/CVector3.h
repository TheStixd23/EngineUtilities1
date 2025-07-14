#pragma once

#include "../Utilities/EngineMath.h"
#include <ostream>

namespace EngineUtilities {

    /**
     * @class CVector3
     * @brief Representa un vector de 3 dimensiones con componentes x, y, z.
     *
     * Proporciona operadores aritméticos, acceso por índice, operaciones vectoriales
     * como normalización, producto cruzado y producto punto.
     * También incluye funciones utilitarias como distancia y mezcla lineal.
     *
     * @author Hannin Abarca
     */
    class CVector3 {
    public:
        float x, y, z;

        /// @brief Constructor por defecto. Inicializa los componentes a 0.
        CVector3() : x(0), y(0), z(0) {}

        /**
         * @brief Constructor por componentes.
         */
        CVector3(float x, float y, float z) : x(x), y(y), z(z) {}

        /// @brief Suma de vectores.
        CVector3 operator+(const CVector3& other) const {
            return CVector3(x + other.x, y + other.y, z + other.z);
        }

        /// @brief Resta de vectores.
        CVector3 operator-(const CVector3& other) const {
            return CVector3(x - other.x, y - other.y, z - other.z);
        }

        /// @brief Multiplicación por escalar.
        CVector3 operator*(float scalar) const {
            return CVector3(x * scalar, y * scalar, z * scalar);
        }

        /// @brief División por escalar.
        CVector3 operator/(float scalar) const {
            return CVector3(x / scalar, y / scalar, z / scalar);
        }

        /// @brief Suma compuesta.
        CVector3& operator+=(const CVector3& other) {
            x += other.x; y += other.y; z += other.z;
            return *this;
        }

        /// @brief Resta compuesta.
        CVector3& operator-=(const CVector3& other) {
            x -= other.x; y -= other.y; z -= other.z;
            return *this;
        }

        /// @brief Multiplicación compuesta por escalar.
        CVector3& operator*=(float scalar) {
            x *= scalar; y *= scalar; z *= scalar;
            return *this;
        }

        /// @brief División compuesta por escalar.
        CVector3& operator/=(float scalar) {
            x /= scalar; y /= scalar; z /= scalar;
            return *this;
        }

        /// @brief Comparación por igualdad (con tolerancia).
        bool operator==(const CVector3& other) const {
            return EngineUtilities::approxEqual(x, other.x) &&
                EngineUtilities::approxEqual(y, other.y) &&
                EngineUtilities::approxEqual(z, other.z);
        }

        /// @brief Comparación por desigualdad.
        bool operator!=(const CVector3& other) const {
            return !(*this == other);
        }

        /// @brief Acceso a componente por índice (modificable).
        float& operator[](int index) {
            return (index == 0) ? x : (index == 1) ? y : z;
        }

        /// @brief Acceso a componente por índice (constante).
        const float& operator[](int index) const {
            return (index == 0) ? x : (index == 1) ? y : z;
        }

        /// @brief Magnitud al cuadrado del vector.
        float lengthSquare() const {
            return x * x + y * y + z * z;
        }

        /// @brief Magnitud (longitud) del vector.
        float length() const {
            return (float)EngineUtilities::sqrt(lengthSquare());
        }

        /// @brief Producto punto entre dos vectores.
        float dot(const CVector3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        /// @brief Producto cruzado entre dos vectores.
        CVector3 cross(const CVector3& other) const {
            return CVector3(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
            );
        }

        /// @brief Retorna una versión normalizada del vector.
        CVector3 normalized() const {
            float len = length();
            return (len == 0.f) ? CVector3(0.f, 0.f, 0.f) : (*this) / len;
        }

        /// @brief Normaliza el vector en sí mismo.
        void normalize() {
            float len = length();
            if (len != 0.f) {
                x /= len; y /= len; z /= len;
            }
            else {
                x = y = z = 0.f;
            }
        }

        /// @brief Calcula la distancia entre dos vectores.
        static float distance(const CVector3& a, const CVector3& b) {
            return (b - a).length();
        }

        /// @brief Interpolación lineal entre dos vectores.
        static CVector3 lerp(const CVector3& a, const CVector3& b, float t) {
            return a + (b - a) * t;
        }

        /// @brief Retorna un vector con componentes (0, 0, 0).
        static CVector3 zero() {
            return CVector3(0.f, 0.f, 0.f);
        }

        /// @brief Retorna un vector con componentes (1, 1, 1).
        static CVector3 one() {
            return CVector3(1.f, 1.f, 1.f);
        }

        /// @brief Imprime el vector en formato (x, y, z).
        friend std::ostream& operator<<(std::ostream& os, const CVector3& v) {
            os << "CVector3(" << v.x << ", " << v.y << ", " << v.z << ")";
            return os;
        }
    };

}
