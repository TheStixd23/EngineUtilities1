/**
 * @file testMatriz3x3.cpp
 * @brief Prueba interactiva para la clase Matriz3x3 de EngineUtilities.
 * @author Hannin Abarca
 */

#include <iostream>
#include "../include/Matriz/Matriz3x3.h"
using namespace std;

/**
 * @brief Ejecuta un menú interactivo para probar la clase Matriz3x3.
 *
 * Esta función permite al usuario:
 * - Ingresar dos matrices 3x3 personalizadas.
 * - Ver las matrices ingresadas.
 * - Obtener las transpuestas.
 * - Calcular determinantes e inversas.
 * - Aplicar operaciones básicas: suma, resta, multiplicación, división y por escalar.
 * - Generar matrices de escala y rotación.
 * - Comparar matrices.
 */
void testMatriz3x3() {
    int option;
    double a00, a01, a02, a10, a11, a12, a20, a21, a22;
    double b00, b01, b02, b10, b11, b12, b20, b21, b22;
    double scalar, angle, sx, sy;

    EngineUtilities::Matriz3x3 m1, m2;

    do {
        cout << "\nMenu-Prueba de Matriz3x3\n";
        cout << "1. Ingresar matriz personalizada\n";
        cout << "2. Mostrar matrices actuales\n";
        cout << "3. Transpuesta\n";
        cout << "4. Determinante e inversa\n";
        cout << "5. Operadores básicos (+, -, *, /)\n";
        cout << "6. Matriz de escala y rotación\n";
        cout << "7. Comparación (==, !=)\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        cout.precision(4);
        cout << fixed;

        switch (option) {
        case 1:
            cout << "Ingrese valores para la matriz 1 (fila por fila, 9 valores):\n";
            cin >> a00 >> a01 >> a02 >> a10 >> a11 >> a12 >> a20 >> a21 >> a22;
            m1 = EngineUtilities::Matriz3x3(a00, a01, a02, a10, a11, a12, a20, a21, a22);

            cout << "Ingrese valores para la matriz 2:\n";
            cin >> b00 >> b01 >> b02 >> b10 >> b11 >> b12 >> b20 >> b21 >> b22;
            m2 = EngineUtilities::Matriz3x3(b00, b01, b02, b10, b11, b12, b20, b21, b22);
            break;

        case 2:
            cout << "Matriz 1:\n";
            cout << m1.m00 << "  " << m1.m01 << "  " << m1.m02 << "\n";
            cout << m1.m10 << "  " << m1.m11 << "  " << m1.m12 << "\n";
            cout << m1.m20 << "  " << m1.m21 << "  " << m1.m22 << "\n";

            cout << "Matriz 2:\n";
            cout << m2.m00 << "  " << m2.m01 << "  " << m2.m02 << "\n";
            cout << m2.m10 << "  " << m2.m11 << "  " << m2.m12 << "\n";
            cout << m2.m20 << "  " << m2.m21 << "  " << m2.m22 << "\n";
            break;

        case 3: {
            EngineUtilities::Matriz3x3 t1 = m1.transpose();
            EngineUtilities::Matriz3x3 t2 = m2.transpose();

            cout << "Transpuesta de Matriz 1:\n";
            cout << t1.m00 << "  " << t1.m01 << "  " << t1.m02 << "\n";
            cout << t1.m10 << "  " << t1.m11 << "  " << t1.m12 << "\n";
            cout << t1.m20 << "  " << t1.m21 << "  " << t1.m22 << "\n";

            cout << "Transpuesta de Matriz 2:\n";
            cout << t2.m00 << "  " << t2.m01 << "  " << t2.m02 << "\n";
            cout << t2.m10 << "  " << t2.m11 << "  " << t2.m12 << "\n";
            cout << t2.m20 << "  " << t2.m21 << "  " << t2.m22 << "\n";
            break;
        }

        case 4: {
            double det1 = m1.determinant();
            double det2 = m2.determinant();

            cout << "Determinante de Matriz 1: " << det1 << endl;
            cout << "Determinante de Matriz 2: " << det2 << endl;

            if (fabs(det1) > EngineUtilities::EPSILON) {
                EngineUtilities::Matriz3x3 inv1 = m1.inverse();
                cout << "Inversa de Matriz 1:\n";
                cout << inv1.m00 << "  " << inv1.m01 << "  " << inv1.m02 << "\n";
                cout << inv1.m10 << "  " << inv1.m11 << "  " << inv1.m12 << "\n";
                cout << inv1.m20 << "  " << inv1.m21 << "  " << inv1.m22 << "\n";
            }
            else {
                cout << "Matriz 1 no es invertible.\n";
            }

            if (fabs(det2) > EngineUtilities::EPSILON) {
                EngineUtilities::Matriz3x3 inv2 = m2.inverse();
                cout << "Inversa de Matriz 2:\n";
                cout << inv2.m00 << "  " << inv2.m01 << "  " << inv2.m02 << "\n";
                cout << inv2.m10 << "  " << inv2.m11 << "  " << inv2.m12 << "\n";
                cout << inv2.m20 << "  " << inv2.m21 << "  " << inv2.m22 << "\n";
            }
            else {
                cout << "Matriz 2 no es invertible.\n";
            }
            break;
        }

        case 5: {
            EngineUtilities::Matriz3x3 suma = m1 + m2;
            EngineUtilities::Matriz3x3 resta = m1 - m2;
            EngineUtilities::Matriz3x3 producto = m1 * m2;

            cout << "Suma:\n";
            cout << suma.m00 << "  " << suma.m01 << "  " << suma.m02 << "\n";
            cout << suma.m10 << "  " << suma.m11 << "  " << suma.m12 << "\n";
            cout << suma.m20 << "  " << suma.m21 << "  " << suma.m22 << "\n";

            cout << "Resta:\n";
            cout << resta.m00 << "  " << resta.m01 << "  " << resta.m02 << "\n";
            cout << resta.m10 << "  " << resta.m11 << "  " << resta.m12 << "\n";
            cout << resta.m20 << "  " << resta.m21 << "  " << resta.m22 << "\n";

            cout << "Producto matricial:\n";
            cout << producto.m00 << "  " << producto.m01 << "  " << producto.m02 << "\n";
            cout << producto.m10 << "  " << producto.m11 << "  " << producto.m12 << "\n";
            cout << producto.m20 << "  " << producto.m21 << "  " << producto.m22 << "\n";

            cout << "Ingrese escalar para multiplicar/dividir: ";
            cin >> scalar;

            EngineUtilities::Matriz3x3 escalar = m1 * scalar;
            EngineUtilities::Matriz3x3 division = m1 / scalar;

            cout << "Producto por escalar (" << scalar << "):\n";
            cout << escalar.m00 << "  " << escalar.m01 << "  " << escalar.m02 << "\n";
            cout << escalar.m10 << "  " << escalar.m11 << "  " << escalar.m12 << "\n";
            cout << escalar.m20 << "  " << escalar.m21 << "  " << escalar.m22 << "\n";

            cout << "División por escalar (" << scalar << "):\n";
            cout << division.m00 << "  " << division.m01 << "  " << division.m02 << "\n";
            cout << division.m10 << "  " << division.m11 << "  " << division.m12 << "\n";
            cout << division.m20 << "  " << division.m21 << "  " << division.m22 << "\n";
            break;
        }

        case 6: {
            cout << "Ingrese factor de escala X: ";
            cin >> sx;
            cout << "Ingrese factor de escala Y: ";
            cin >> sy;

            EngineUtilities::Matriz3x3 scale = EngineUtilities::Matriz3x3::Scale(sx, sy);
            cout << "Matriz de escala:\n";
            cout << scale.m00 << "  " << scale.m01 << "  " << scale.m02 << "\n";
            cout << scale.m10 << "  " << scale.m11 << "  " << scale.m12 << "\n";
            cout << scale.m20 << "  " << scale.m21 << "  " << scale.m22 << "\n";

            cout << "Ingrese ángulo en radianes para rotación: ";
            cin >> angle;
            EngineUtilities::Matriz3x3 rotate = EngineUtilities::Matriz3x3::Rotate(angle);
            cout << "Matriz de rotación:\n";
            cout << rotate.m00 << "  " << rotate.m01 << "  " << rotate.m02 << "\n";
            cout << rotate.m10 << "  " << rotate.m11 << "  " << rotate.m12 << "\n";
            cout << rotate.m20 << "  " << rotate.m21 << "  " << rotate.m22 << "\n";
            break;
        }

        case 7: {
            cout << "Matriz 1 == Matriz 2 -> " << (m1 == m2 ? "true" : "false") << endl;
            cout << "Matriz 1 != Matriz 2 -> " << (m1 != m2 ? "true" : "false") << endl;
            break;
        }

        case 0:
            cout << "Volviendo al menú principal...\n";
            break;

        default:
            cout << "Opción no válida.\n";
        }

    } while (option != 0);
}
