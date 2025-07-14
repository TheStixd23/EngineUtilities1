#pragma once

#include "../Utilities/EngineMath.h"

namespace EngineUtilities {

    class Matriz2x2 {
    public:
        double m00, m01, m10, m11;

        Matriz2x2()
            : m00(1.0), m01(0.0), m10(0.0), m11(1.0) {
        }

        Matriz2x2(double a, double b, double c, double d)
            : m00(a), m01(b), m10(c), m11(d) {
        }

        static Matriz2x2 Scale(double scaleX, double scaleY) {
            return Matriz2x2(scaleX, 0.0, 0.0, scaleY);
        }

        static Matriz2x2 Rotate(double angle) {
            double cosA = cos(angle);
            double sinA = sin(angle);
            return Matriz2x2(cosA, -sinA, sinA, cosA);
        }

        Matriz2x2 transpose() const {
            return Matriz2x2(m00, m10, m01, m11);
        }

        double determinant() const {
            return (m00 * m11) - (m01 * m10);
        }

        Matriz2x2 inverse() const {
            double det = determinant();
            if (fabs(det) < EPSILON) return Matriz2x2();  // fallback
            double invDet = 1.0 / det;
            return Matriz2x2(
                m11 * invDet, -m01 * invDet,
                -m10 * invDet, m00 * invDet
            );
        }

        Matriz2x2 operator*(const Matriz2x2& other) const {
            return Matriz2x2(
                m00 * other.m00 + m01 * other.m10,
                m00 * other.m01 + m01 * other.m11,
                m10 * other.m00 + m11 * other.m10,
                m10 * other.m01 + m11 * other.m11
            );
        }

        Matriz2x2 operator+(const Matriz2x2& other) const {
            return Matriz2x2(
                m00 + other.m00, m01 + other.m01,
                m10 + other.m10, m11 + other.m11
            );
        }

        Matriz2x2 operator-(const Matriz2x2& other) const {
            return Matriz2x2(
                m00 - other.m00, m01 - other.m01,
                m10 - other.m10, m11 - other.m11
            );
        }

        Matriz2x2 operator*(double scalar) const {
            return Matriz2x2(
                m00 * scalar, m01 * scalar,
                m10 * scalar, m11 * scalar
            );
        }

        Matriz2x2 operator/(double scalar) const {
            if (fabs(scalar) < EPSILON) return Matriz2x2();
            double inv = 1.0 / scalar;
            return (*this) * inv;
        }

        bool operator==(const Matriz2x2& other) const {
            return fabs(m00 - other.m00) < EPSILON &&
                fabs(m01 - other.m01) < EPSILON &&
                fabs(m10 - other.m10) < EPSILON &&
                fabs(m11 - other.m11) < EPSILON;
        }

        bool operator!=(const Matriz2x2& other) const {
            return !(*this == other);
        }
    };

}
