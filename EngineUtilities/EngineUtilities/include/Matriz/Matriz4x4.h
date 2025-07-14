/**
 * @file Matriz4x4.h
 * @brief Implementación de una matriz 4x4 para transformaciones en 3D.
 * @author Hannin Abarca
 */

#pragma once

#include "../Utilities/EngineMath.h"

namespace EngineUtilities {

    /**
     * @class Matriz4x4
     * @brief Representa una matriz 4x4 con operaciones comunes para transformaciones 3D.
     */
    class Matriz4x4 {
    public:
        double m[4][4]; ///< Elementos de la matriz

        /** Constructor identidad */
        Matriz4x4() {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    m[i][j] = (i == j) ? 1.0 : 0.0;
        }

        /** Constructor con valores */
        Matriz4x4(double m00, double m01, double m02, double m03,
            double m10, double m11, double m12, double m13,
            double m20, double m21, double m22, double m23,
            double m30, double m31, double m32, double m33) {
            m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
            m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
            m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
            m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
        }

        /** Escalado */
        static Matriz4x4 Scale(double sx, double sy, double sz) {
            return Matriz4x4(
                sx, 0.0, 0.0, 0.0,
                0.0, sy, 0.0, 0.0,
                0.0, 0.0, sz, 0.0,
                0.0, 0.0, 0.0, 1.0
            );
        }

        /** Traslación */
        static Matriz4x4 Translate(double tx, double ty, double tz) {
            return Matriz4x4(
                1.0, 0.0, 0.0, tx,
                0.0, 1.0, 0.0, ty,
                0.0, 0.0, 1.0, tz,
                0.0, 0.0, 0.0, 1.0
            );
        }

        /** Rotación sobre eje Z */
        static Matriz4x4 RotateZ(double angle) {
            double c = EngineUtilities::cos(angle);
            double s = EngineUtilities::sin(angle);
            return Matriz4x4(
                c, -s, 0.0, 0.0,
                s, c, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0
            );
        }

        /** Transpuesta */
        Matriz4x4 transpose() const {
            Matriz4x4 result;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    result.m[i][j] = m[j][i];
            return result;
        }

        /** Inversa */
        Matriz4x4 inverse() const {
            Matriz4x4 inv;
            double det, invOut[16];
            const double* m_ = &m[0][0];

            invOut[0] = m_[5] * m_[10] * m_[15] - m_[5] * m_[11] * m_[14] - m_[9] * m_[6] * m_[15] + m_[9] * m_[7] * m_[14] + m_[13] * m_[6] * m_[11] - m_[13] * m_[7] * m_[10];
            invOut[1] = -m_[1] * m_[10] * m_[15] + m_[1] * m_[11] * m_[14] + m_[9] * m_[2] * m_[15] - m_[9] * m_[3] * m_[14] - m_[13] * m_[2] * m_[11] + m_[13] * m_[3] * m_[10];
            invOut[2] = m_[1] * m_[6] * m_[15] - m_[1] * m_[7] * m_[14] - m_[5] * m_[2] * m_[15] + m_[5] * m_[3] * m_[14] + m_[13] * m_[2] * m_[7] - m_[13] * m_[3] * m_[6];
            invOut[3] = -m_[1] * m_[6] * m_[11] + m_[1] * m_[7] * m_[10] + m_[5] * m_[2] * m_[11] - m_[5] * m_[3] * m_[10] - m_[9] * m_[2] * m_[7] + m_[9] * m_[3] * m_[6];
            invOut[4] = -m_[4] * m_[10] * m_[15] + m_[4] * m_[11] * m_[14] + m_[8] * m_[6] * m_[15] - m_[8] * m_[7] * m_[14] - m_[12] * m_[6] * m_[11] + m_[12] * m_[7] * m_[10];
            invOut[5] = m_[0] * m_[10] * m_[15] - m_[0] * m_[11] * m_[14] - m_[8] * m_[2] * m_[15] + m_[8] * m_[3] * m_[14] + m_[12] * m_[2] * m_[11] - m_[12] * m_[3] * m_[10];
            invOut[6] = -m_[0] * m_[6] * m_[15] + m_[0] * m_[7] * m_[14] + m_[4] * m_[2] * m_[15] - m_[4] * m_[3] * m_[14] - m_[12] * m_[2] * m_[7] + m_[12] * m_[3] * m_[6];
            invOut[7] = m_[0] * m_[6] * m_[11] - m_[0] * m_[7] * m_[10] - m_[4] * m_[2] * m_[11] + m_[4] * m_[3] * m_[10] + m_[8] * m_[2] * m_[7] - m_[8] * m_[3] * m_[6];
            invOut[8] = m_[4] * m_[9] * m_[15] - m_[4] * m_[11] * m_[13] - m_[8] * m_[5] * m_[15] + m_[8] * m_[7] * m_[13] + m_[12] * m_[5] * m_[11] - m_[12] * m_[7] * m_[9];
            invOut[9] = -m_[0] * m_[9] * m_[15] + m_[0] * m_[11] * m_[13] + m_[8] * m_[1] * m_[15] - m_[8] * m_[3] * m_[13] + m_[12] * m_[1] * m_[11] - m_[12] * m_[3] * m_[9];
            invOut[10] = m_[0] * m_[5] * m_[15] - m_[0] * m_[7] * m_[13] - m_[4] * m_[1] * m_[15] + m_[4] * m_[3] * m_[13] + m_[12] * m_[1] * m_[7] - m_[12] * m_[3] * m_[5];
            invOut[11] = -m_[0] * m_[5] * m_[11] + m_[0] * m_[7] * m_[9] + m_[4] * m_[1] * m_[11] - m_[4] * m_[3] * m_[9] - m_[8] * m_[1] * m_[7] + m_[8] * m_[3] * m_[5];
            invOut[12] = -m_[4] * m_[9] * m_[14] + m_[4] * m_[10] * m_[13] + m_[8] * m_[5] * m_[14] - m_[8] * m_[6] * m_[13] - m_[12] * m_[5] * m_[10] + m_[12] * m_[6] * m_[9];
            invOut[13] = m_[0] * m_[9] * m_[14] - m_[0] * m_[10] * m_[13] - m_[8] * m_[1] * m_[14] + m_[8] * m_[2] * m_[13] + m_[12] * m_[1] * m_[10] - m_[12] * m_[2] * m_[9];
            invOut[14] = -m_[0] * m_[5] * m_[14] + m_[0] * m_[6] * m_[13] + m_[4] * m_[1] * m_[14] - m_[4] * m_[2] * m_[13] - m_[12] * m_[1] * m_[6] + m_[12] * m_[2] * m_[5];
            invOut[15] = m_[0] * m_[5] * m_[10] - m_[0] * m_[6] * m_[9] - m_[4] * m_[1] * m_[10] + m_[4] * m_[2] * m_[9] + m_[8] * m_[1] * m_[6] - m_[8] * m_[2] * m_[5];

            det = m_[0] * invOut[0] + m_[1] * invOut[4] + m_[2] * invOut[8] + m_[3] * invOut[12];
            if (EngineUtilities::fabs(det) < EngineUtilities::EPSILON)
                return Matriz4x4();

            det = 1.0 / det;
            for (int i = 0; i < 16; ++i)
                invOut[i] *= det;

            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    inv.m[i][j] = invOut[i * 4 + j];

            return inv;
        }

        /** Multiplicación por otra matriz */
        Matriz4x4 operator*(const Matriz4x4& o) const {
            Matriz4x4 result;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j) {
                    result.m[i][j] = 0.0;
                    for (int k = 0; k < 4; ++k)
                        result.m[i][j] += m[i][k] * o.m[k][j];
                }
            return result;
        }

        /** Suma de matrices */
        Matriz4x4 operator+(const Matriz4x4& o) const {
            Matriz4x4 result;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    result.m[i][j] = m[i][j] + o.m[i][j];
            return result;
        }

        /** Resta de matrices */
        Matriz4x4 operator-(const Matriz4x4& o) const {
            Matriz4x4 result;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    result.m[i][j] = m[i][j] - o.m[i][j];
            return result;
        }

        /** Multiplicación por escalar */
        Matriz4x4 operator*(double scalar) const {
            Matriz4x4 result;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    result.m[i][j] = m[i][j] * scalar;
            return result;
        }

        /** División por escalar */
        Matriz4x4 operator/(double scalar) const {
            if (EngineUtilities::fabs(scalar) < EngineUtilities::EPSILON)
                return Matriz4x4();
            return (*this) * (1.0 / scalar);
        }

        /** Comparación de igualdad */
        bool operator==(const Matriz4x4& o) const {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (EngineUtilities::fabs(m[i][j] - o.m[i][j]) >= EngineUtilities::EPSILON)
                        return false;
            return true;
        }

        /** Comparación de desigualdad */
        bool operator!=(const Matriz4x4& o) const {
            return !(*this == o);
        }
    };

}
