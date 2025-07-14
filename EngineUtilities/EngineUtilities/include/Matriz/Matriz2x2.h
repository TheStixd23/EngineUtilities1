#pragma once

#include "../Utilities/EngineMath.h"

namespace EngineUtilities {

    /**
     * @class Matriz2x2
     * @brief Representa una matriz 2x2 para transformaciones 2D.
     * @author Hannin Abarca
     */
    class Matriz2x2 {
    public:
        double m00, m01, m10, m11;

        /**
         * @brief Constructor por defecto. Inicializa como matriz identidad.
         */
        Matriz2x2()
            : m00(1.0), m01(0.0), m10(0.0), m11(1.0) {
        }

        /**
         * @brief Constructor con valores personalizados.
         * @param a Valor en fila 0, columna 0.
         * @param b Valor en fila 0, columna 1.
         * @param c Valor en fila 1, columna 0.
         * @param d Valor en fila 1, columna 1.
         */
        Matriz2x2(double a, double b, double c, double d)
            : m00(a), m01(b), m10(c), m11(d) {
        }

        /**
         * @brief Crea una matriz de escalado.
         * @param scaleX Escala en eje X.
         * @param scaleY Escala en eje Y.
         * @return Matriz escalada.
         */
        static Matriz2x2 Scale(double scaleX, double scaleY) {
            return Matriz2x2(scaleX, 0.0, 0.0, scaleY);
        }

        /**
         * @brief Crea una matriz de rotación 2D.
         * @param angle Ángulo en radianes.
         * @return Matriz rotada.
         */
        static Matriz2x2 Rotate(double angle) {
            double cosA = cos(angle);
            double sinA = sin(angle);
            return Matriz2x2(cosA, -sinA, sinA, cosA);
        }

        /**
         * @brief Retorna la transpuesta de la matriz.
         * @return Matriz transpuesta.
         */
        Matriz2x2 transpose() const {
            return Matriz2x2(m00, m10, m01, m11);
        }

        /**
         * @brief Calcula el determinante de la matriz.
         * @return Determinante.
         */
        double determinant() const {
            return (m00 * m11) - (m01 * m10);
        }

        /**
         * @brief Calcula la inversa de la matriz.
         * @return Matriz inversa o identidad si no es invertible.
         */
        Matriz2x2 inverse() const {
            double det = determinant();
            if (fabs(det) < EPSILON) return Matriz2x2();
            double invDet = 1.0 / det;
            return Matriz2x2(
                m11 * invDet, -m01 * invDet,
                -m10 * invDet, m00 * invDet
            );
        }

        /**
         * @brief Multiplicación de matrices.
         * @param other Matriz derecha.
         * @return Resultado de la multiplicación.
         */
        Matriz2x2 operator*(const Matriz2x2& other) const {
            return Matriz2x2(
                m00 * other.m00 + m01 * other.m10,
                m00 * other.m01 + m01 * other.m11,
                m10 * other.m00 + m11 * other.m10,
                m10 * other.m01 + m11 * other.m11
            );
        }

        /**
         * @brief Suma de matrices.
         * @param other Matriz a sumar.
         * @return Resultado de la suma.
         */
        Matriz2x2 operator+(const Matriz2x2& other) const {
            return Matriz2x2(
                m00 + other.m00, m01 + other.m01,
                m10 + other.m10, m11 + other.m11
            );
        }

        /**
         * @brief Resta de matrices.
         * @param other Matriz a restar.
         * @return Resultado de la resta.
         */
        Matriz2x2 operator-(const Matriz2x2& other) const {
            return Matriz2x2(
                m00 - other.m00, m01 - other.m01,
                m10 - other.m10, m11 - other.m11
            );
        }

        /**
         * @brief Multiplicación por escalar.
         * @param scalar Valor escalar.
         * @return Matriz escalada.
         */
        Matriz2x2 operator*(double scalar) const {
            return Matriz2x2(
                m00 * scalar, m01 * scalar,
                m10 * scalar, m11 * scalar
            );
        }

        /**
         * @brief División por escalar.
         * @param scalar Valor divisor.
         * @return Matriz resultante o identidad si el escalar es muy pequeño.
         */
        Matriz2x2 operator/(double scalar) const {
            if (fabs(scalar) < EPSILON) return Matriz2x2();
            double inv = 1.0 / scalar;
            return (*this) * inv;
        }

        /**
         * @brief Compara si dos matrices son aproximadamente iguales.
         * @param other Matriz a comparar.
         * @return true si son iguales, false si no.
         */
        bool operator==(const Matriz2x2& other) const {
            return fabs(m00 - other.m00) < EPSILON &&
                fabs(m01 - other.m01) < EPSILON &&
                fabs(m10 - other.m10) < EPSILON &&
                fabs(m11 - other.m11) < EPSILON;
        }

        /**
         * @brief Compara si dos matrices son diferentes.
         * @param other Matriz a comparar.
         * @return true si son diferentes, false si son iguales.
         */
        bool operator!=(const Matriz2x2& other) const {
            return !(*this == other);
        }
    };

}
