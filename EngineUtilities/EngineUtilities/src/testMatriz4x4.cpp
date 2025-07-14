/**
 * @file testMatriz4x4.cpp
 * @brief Prueba interactiva para la clase Matriz4x4 de EngineUtilities.
 *
 * Este archivo permite al usuario interactuar con operaciones básicas y avanzadas
 * de matrices 4x4, como transposición, inversión, transformaciones (escala, rotación, traslación),
 * comparación, y operaciones aritméticas.
 *
 * @author Hannin Abarca
 */

#include <iostream>
#include "../include/Matriz/Matriz4x4.h"
using namespace std;

/**
 * @brief Ejecuta un menú interactivo para probar la clase Matriz4x4.
 *
 * Opciones disponibles:
 * - Ingreso manual de matrices
 * - Mostrar contenido de matrices
 * - Obtener transpuestas
 * - Calcular inversas
 * - Operaciones aritméticas (+, -, *, /)
 * - Generación de matrices de escala, rotación (Z), y traslación
 * - Comparación lógica (==, !=)
 */
void testMatriz4x4() {
    int option;
    double values[16];
    EngineUtilities::Matriz4x4 m1, m2;

    do {
        cout << "\nMenu-Prueba de Matriz4x4\n";
        cout << "1. Ingresar matriz personalizada\n";
        cout << "2. Mostrar matrices actuales\n";
        cout << "3. Transpuesta\n";
        cout << "4. Inversa\n";
        cout << "5. Operadores básicos (+, -, *, /)\n";
        cout << "6. Generar matriz de escala\n";
        cout << "7. Generar matriz de rotación sobre Z\n";
        cout << "8. Generar matriz de traslación\n";
        cout << "9. Comparación (==, !=)\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        cout.precision(4);
        cout << fixed;

        switch (option) {
        case 1: {
            cout << "Ingrese 16 valores para la matriz 1:\n";
            for (int i = 0; i < 16; ++i) cin >> values[i];
            m1 = EngineUtilities::Matriz4x4(
                values[0], values[1], values[2], values[3],
                values[4], values[5], values[6], values[7],
                values[8], values[9], values[10], values[11],
                values[12], values[13], values[14], values[15]
            );

            cout << "Ingrese 16 valores para la matriz 2:\n";
            for (int i = 0; i < 16; ++i) cin >> values[i];
            m2 = EngineUtilities::Matriz4x4(
                values[0], values[1], values[2], values[3],
                values[4], values[5], values[6], values[7],
                values[8], values[9], values[10], values[11],
                values[12], values[13], values[14], values[15]
            );
            break;
        }

        case 2: {
            cout << "Matriz 1:\n";
            for (int i = 0; i < 4; ++i)
                cout << m1.m[i][0] << "  " << m1.m[i][1] << "  " << m1.m[i][2] << "  " << m1.m[i][3] << "\n";

            cout << "Matriz 2:\n";
            for (int i = 0; i < 4; ++i)
                cout << m2.m[i][0] << "  " << m2.m[i][1] << "  " << m2.m[i][2] << "  " << m2.m[i][3] << "\n";
            break;
        }

        case 3: {
            EngineUtilities::Matriz4x4 t1 = m1.transpose();
            EngineUtilities::Matriz4x4 t2 = m2.transpose();

            cout << "Transpuesta de Matriz 1:\n";
            for (int i = 0; i < 4; ++i)
                cout << t1.m[i][0] << "  " << t1.m[i][1] << "  " << t1.m[i][2] << "  " << t1.m[i][3] << "\n";

            cout << "Transpuesta de Matriz 2:\n";
            for (int i = 0; i < 4; ++i)
                cout << t2.m[i][0] << "  " << t2.m[i][1] << "  " << t2.m[i][2] << "  " << t2.m[i][3] << "\n";
            break;
        }

        case 4: {
            double det1 = m1.m[0][0] * m1.m[1][1] * m1.m[2][2] * m1.m[3][3];
            double det2 = m2.m[0][0] * m2.m[1][1] * m2.m[2][2] * m2.m[3][3];

            cout << "Determinante Matriz 1: " << det1 << endl;
            if (fabs(det1) < EngineUtilities::EPSILON)
                cout << "Matriz 1 no es invertible.\n";
            else {
                EngineUtilities::Matriz4x4 inv1 = m1.inverse();
                for (int i = 0; i < 4; ++i)
                    cout << inv1.m[i][0] << "  " << inv1.m[i][1] << "  " << inv1.m[i][2] << "  " << inv1.m[i][3] << "\n";
            }

            cout << "Determinante Matriz 2: " << det2 << endl;
            if (fabs(det2) < EngineUtilities::EPSILON)
                cout << "Matriz 2 no es invertible.\n";
            else {
                EngineUtilities::Matriz4x4 inv2 = m2.inverse();
                for (int i = 0; i < 4; ++i)
                    cout << inv2.m[i][0] << "  " << inv2.m[i][1] << "  " << inv2.m[i][2] << "  " << inv2.m[i][3] << "\n";
            }
            break;
        }

        case 5: {
            EngineUtilities::Matriz4x4 suma = m1 + m2;
            EngineUtilities::Matriz4x4 resta = m1 - m2;
            EngineUtilities::Matriz4x4 producto = m1 * m2;

            cout << "Suma:\n";
            for (int i = 0; i < 4; ++i)
                cout << suma.m[i][0] << "  " << suma.m[i][1] << "  " << suma.m[i][2] << "  " << suma.m[i][3] << "\n";

            cout << "Resta:\n";
            for (int i = 0; i < 4; ++i)
                cout << resta.m[i][0] << "  " << resta.m[i][1] << "  " << resta.m[i][2] << "  " << resta.m[i][3] << "\n";

            cout << "Producto matricial:\n";
            for (int i = 0; i < 4; ++i)
                cout << producto.m[i][0] << "  " << producto.m[i][1] << "  " << producto.m[i][2] << "  " << producto.m[i][3] << "\n";

            double scalar;
            cout << "Ingrese escalar para multiplicar/dividir: ";
            cin >> scalar;

            EngineUtilities::Matriz4x4 escalar = m1 * scalar;
            EngineUtilities::Matriz4x4 division = m1 / scalar;

            cout << "Matriz * escalar (" << scalar << "):\n";
            for (int i = 0; i < 4; ++i)
                cout << escalar.m[i][0] << "  " << escalar.m[i][1] << "  " << escalar.m[i][2] << "  " << escalar.m[i][3] << "\n";

            cout << "Matriz / escalar (" << scalar << "):\n";
            for (int i = 0; i < 4; ++i)
                cout << division.m[i][0] << "  " << division.m[i][1] << "  " << division.m[i][2] << "  " << division.m[i][3] << "\n";
            break;
        }

        case 6: {
            double sx, sy, sz;
            cout << "Ingrese factores de escala X Y Z: ";
            cin >> sx >> sy >> sz;
            EngineUtilities::Matriz4x4 scale = EngineUtilities::Matriz4x4::Scale(sx, sy, sz);
            for (int i = 0; i < 4; ++i)
                cout << scale.m[i][0] << "  " << scale.m[i][1] << "  " << scale.m[i][2] << "  " << scale.m[i][3] << "\n";
            break;
        }

        case 7: {
            double angle;
            cout << "Ingrese ángulo en radianes para rotación sobre Z: ";
            cin >> angle;
            EngineUtilities::Matriz4x4 rotateZ = EngineUtilities::Matriz4x4::RotateZ(angle);
            for (int i = 0; i < 4; ++i)
                cout << rotateZ.m[i][0] << "  " << rotateZ.m[i][1] << "  " << rotateZ.m[i][2] << "  " << rotateZ.m[i][3] << "\n";
            break;
        }

        case 8: {
            double tx, ty, tz;
            cout << "Ingrese traslación (tx ty tz): ";
            cin >> tx >> ty >> tz;
            EngineUtilities::Matriz4x4 translate = EngineUtilities::Matriz4x4::Translate(tx, ty, tz);
            for (int i = 0; i < 4; ++i)
                cout << translate.m[i][0] << "  " << translate.m[i][1] << "  " << translate.m[i][2] << "  " << translate.m[i][3] << "\n";
            break;
        }

        case 9:
            cout << "m1 == m2 -> " << (m1 == m2 ? "true" : "false") << endl;
            cout << "m1 != m2 -> " << (m1 != m2 ? "true" : "false") << endl;
            break;

        case 0:
            cout << "Volviendo al menú principal...\n";
            break;

        default:
            cout << "Opción no válida.\n";
        }

    } while (option != 0);
}
