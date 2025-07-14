#pragma once

#include "../Utilities/EngineMath.h"

namespace EngineUtilities {

    /**
     * @class Matriz3x3
     * @brief Representa una matriz 3x3 con operaciones comunes como escala, rotación, transposición, inversa y más.
     * @author Hannin Abarca
     */
    class Matriz3x3 {
    public:
        double m00, m01, m02;
        double m10, m11, m12;
        double m20, m21, m22;

        /// Constructor por defecto (matriz identidad)
        Matriz3x3()
            : m00(1.0), m01(0.0), m02(0.0),
            m10(0.0), m11(1.0), m12(0.0),
            m20(0.0), m21(0.0), m22(1.0) {
        }

        /// Constructor con valores explícitos
        Matriz3x3(double a00, double a01, double a02,
            double a10, double a11, double a12,
            double a20, double a21, double a22)
            : m00(a00), m01(a01), m02(a02),
            m10(a10), m11(a11), m12(a12),
            m20(a20), m21(a21), m22(a22) {
        }

        /// Genera una matriz de escala homogénea
        static Matriz3x3 Scale(double sx, double sy) {
            return Matriz3x3(
                sx, 0.0, 0.0,
                0.0, sy, 0.0,
                0.0, 0.0, 1.0
            );
        }

        /// Genera una matriz de rotación homogénea (ángulo en radianes)
        static Matriz3x3 Rotate(double angle) {
            double cosA = cos(angle);
            double sinA = sin(angle);
            return Matriz3x3(
                cosA, -sinA, 0.0,
                sinA, cosA, 0.0,
                0.0, 0.0, 1.0
            );
        }

        /// Transpone la matriz
        Matriz3x3 transpose() const {
            return Matriz3x3(
                m00, m10, m20,
                m01, m11, m21,
                m02, m12, m22
            );
        }

        /// Calcula el determinante de la matriz
        double determinant() const {
            return m00 * (m11 * m22 - m12 * m21)
                - m01 * (m10 * m22 - m12 * m20)
                + m02 * (m10 * m21 - m11 * m20);
        }

        /// Retorna la inversa de la matriz (o matriz identidad si no es invertible)
        Matriz3x3 inverse() const {
            double det = determinant();
            if (fabs(det) < EPSILON) return Matriz3x3();

            double invDet = 1.0 / det;

            return Matriz3x3(
                (m11 * m22 - m12 * m21) * invDet,
                (m02 * m21 - m01 * m22) * invDet,
                (m01 * m12 - m02 * m11) * invDet,

                (m12 * m20 - m10 * m22) * invDet,
                (m00 * m22 - m02 * m20) * invDet,
                (m02 * m10 - m00 * m12) * invDet,

                (m10 * m21 - m11 * m20) * invDet,
                (m01 * m20 - m00 * m21) * invDet,
                (m00 * m11 - m01 * m10) * invDet
            );
        }

        /// Multiplicación entre matrices
        Matriz3x3 operator*(const Matriz3x3& o) const {
            return Matriz3x3(
                m00 * o.m00 + m01 * o.m10 + m02 * o.m20,
                m00 * o.m01 + m01 * o.m11 + m02 * o.m21,
                m00 * o.m02 + m01 * o.m12 + m02 * o.m22,

                m10 * o.m00 + m11 * o.m10 + m12 * o.m20,
                m10 * o.m01 + m11 * o.m11 + m12 * o.m21,
                m10 * o.m02 + m11 * o.m12 + m12 * o.m22,

                m20 * o.m00 + m21 * o.m10 + m22 * o.m20,
                m20 * o.m01 + m21 * o.m11 + m22 * o.m21,
                m20 * o.m02 + m21 * o.m12 + m22 * o.m22
            );
        }

        /// Suma entre matrices
        Matriz3x3 operator+(const Matriz3x3& o) const {
            return Matriz3x3(
                m00 + o.m00, m01 + o.m01, m02 + o.m02,
                m10 + o.m10, m11 + o.m11, m12 + o.m12,
                m20 + o.m20, m21 + o.m21, m22 + o.m22
            );
        }

        /// Resta entre matrices
        Matriz3x3 operator-(const Matriz3x3& o) const {
            return Matriz3x3(
                m00 - o.m00, m01 - o.m01, m02 - o.m02,
                m10 - o.m10, m11 - o.m11, m12 - o.m12,
                m20 - o.m20, m21 - o.m21, m22 - o.m22
            );
        }

        /// Multiplicación por escalar
        Matriz3x3 operator*(double scalar) const {
            return Matriz3x3(
                m00 * scalar, m01 * scalar, m02 * scalar,
                m10 * scalar, m11 * scalar, m12 * scalar,
                m20 * scalar, m21 * scalar, m22 * scalar
            );
        }

        /// División por escalar
        Matriz3x3 operator/(double scalar) const {
            if (fabs(scalar) < EPSILON) return Matriz3x3();
            return (*this) * (1.0 / scalar);
        }

        /// Comparación de igualdad
        bool operator==(const Matriz3x3& o) const {
            return fabs(m00 - o.m00) < EPSILON &&
                fabs(m01 - o.m01) < EPSILON &&
                fabs(m02 - o.m02) < EPSILON &&
                fabs(m10 - o.m10) < EPSILON &&
                fabs(m11 - o.m11) < EPSILON &&
                fabs(m12 - o.m12) < EPSILON &&
                fabs(m20 - o.m20) < EPSILON &&
                fabs(m21 - o.m21) < EPSILON &&
                fabs(m22 - o.m22) < EPSILON;
        }

        /// Comparación de desigualdad
        bool operator!=(const Matriz3x3& o) const {
            return !(*this == o);
        }
    };

}
