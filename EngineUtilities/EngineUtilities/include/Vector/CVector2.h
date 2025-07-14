#pragma once

#include "../Utilities/EngineMath.h"
#include <ostream>

namespace EngineUtilities {

    /**
     * @brief Representa un vector 2D con componentes x e y.
     */
    class CVector2 {
    public:
        float x, y; ///< Componentes del vector

        /// @brief Constructor por defecto. Inicializa en (0, 0).
        CVector2() : x(0), y(0) {}

        /**
         * @brief Constructor con valores específicos.
         * @param x Valor para la componente X.
         * @param y Valor para la componente Y.
         */
        CVector2(float x, float y) : x(x), y(y) {}

        /// @brief Suma de dos vectores.
        CVector2 operator+(const CVector2& other) const {
            return CVector2(x + other.x, y + other.y);
        }

        /// @brief Resta de dos vectores.
        CVector2 operator-(const CVector2& other) const {
            return CVector2(x - other.x, y - other.y);
        }

        /// @brief Multiplicación por escalar.
        CVector2 operator*(float scalar) const {
            return CVector2(x * scalar, y * scalar);
        }

        /// @brief División por escalar.
        CVector2 operator/(float scalar) const {
            return CVector2(x / scalar, y / scalar);
        }

        /// @brief Suma compuesta con otro vector.
        CVector2& operator+=(const CVector2& other) {
            x += other.x; y += other.y;
            return *this;
        }

        /// @brief Resta compuesta con otro vector.
        CVector2& operator-=(const CVector2& other) {
            x -= other.x; y -= other.y;
            return *this;
        }

        /// @brief Multiplicación compuesta por escalar.
        CVector2& operator*=(float scalar) {
            x *= scalar; y *= scalar;
            return *this;
        }

        /// @brief División compuesta por escalar.
        CVector2& operator/=(float scalar) {
            x /= scalar; y /= scalar;
            return *this;
        }

        /// @brief Comparación de igualdad entre vectores.
        bool operator==(const CVector2& other) const {
            return EngineUtilities::approxEqual(x, other.x) && EngineUtilities::approxEqual(y, other.y);
        }

        /// @brief Comparación de diferencia entre vectores.
        bool operator!=(const CVector2& other) const {
            return !(*this == other);
        }

        /**
         * @brief Acceso a los componentes mediante índice.
         * @param index 0 para X, 1 para Y.
         * @return Referencia al componente.
         */
        float& operator[](int index) {
            return (index == 0) ? x : y;
        }

        /**
         * @brief Acceso constante a los componentes mediante índice.
         * @param index 0 para X, 1 para Y.
         * @return Referencia constante al componente.
         */
        const float& operator[](int index) const {
            return (index == 0) ? x : y;
        }

        /// @brief Calcula el cuadrado de la longitud del vector.
        float lengthSquare() const {
            return x * x + y * y;
        }

        /// @brief Calcula la longitud del vector.
        float length() const {
            return (float)EngineUtilities::sqrt(lengthSquare());
        }

        /// @brief Producto punto con otro vector.
        float dot(const CVector2& other) const {
            return x * other.x + y * other.y;
        }

        /// @brief Producto cruzado con otro vector.
        float cross(const CVector2& other) const {
            return x * other.y - y * other.x;
        }

        /// @brief Devuelve una copia del vector normalizado.
        CVector2 normalized() const {
            float len = length();
            return (len == 0.f) ? CVector2(0.f, 0.f) : (*this) / len;
        }

        /// @brief Normaliza el vector actual.
        void normalize() {
            float len = length();
            if (len != 0.f) {
                x /= len; y /= len;
            }
            else {
                x = y = 0.f;
            }
        }

        /**
         * @brief Calcula la distancia entre dos vectores.
         * @param a Primer vector.
         * @param b Segundo vector.
         * @return Distancia flotante.
         */
        static float distance(const CVector2& a, const CVector2& b) {
            return (float)EngineUtilities::sqrt((b - a).lengthSquare());
        }

        /**
         * @brief Interpolación lineal entre dos vectores.
         * @param a Inicio.
         * @param b Fin.
         * @param t Factor de interpolación.
         */
        static CVector2 lerp(const CVector2& a, const CVector2& b, float t) {
            return a + (b - a) * t;
        }

        /// @brief Devuelve un vector (0, 0).
        static CVector2 zero() {
            return CVector2(0.f, 0.f);
        }

        /// @brief Devuelve un vector (1, 1).
        static CVector2 one() {
            return CVector2(1.f, 1.f);
        }

        /**
         * @brief Establece la posición del vector.
         * @param position Nueva posición.
         */
        void setPosition(const CVector2& position) {
            x = position.x;
            y = position.y;
        }

        /**
         * @brief Mueve el vector por un offset.
         * @param offset Desplazamiento a aplicar.
         */
        void move(const CVector2& offset) {
            x += offset.x;
            y += offset.y;
        }

        /**
         * @brief Establece el factor de escala.
         * @param factors Factores de escala a aplicar.
         */
        void setScale(const CVector2& factors) {
            x *= factors.x;
            y *= factors.y;
        }

        /**
         * @brief Escala el vector por los factores dados.
         * @param factors Valores por los que se multiplicará.
         */
        void scale(const CVector2& factors) {
            x *= factors.x;
            y *= factors.y;
        }

        /**
         * @brief Establece el origen del vector.
         * @param origin Valor que se asignará al vector.
         */
        void setOrigin(const CVector2& origin) {
            x = origin.x;
            y = origin.y;
        }

        /**
         * @brief Sobrecarga del operador de salida de flujo.
         * @param os Flujo de salida.
         * @param v Vector a imprimir.
         * @return Flujo con la información del vector.
         */
        friend std::ostream& operator<<(std::ostream& os, const CVector2& v) {
            os << "CVector2(" << v.x << ", " << v.y << ")";
            return os;
        }
    };

}
