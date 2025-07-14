#include <iostream>
#include "../include/Matriz/Matriz2x2.h"
using namespace std;

void testMatriz2x2() {
    int option;
    double a, b, c, d, scalar, angle;
    EngineUtilities::Matriz2x2 m1, m2;

    do {
        cout << "\n=== Menu - Prueba de Matriz2x2 ===\n";
        cout << "1. Ingresar matriz personalizada\n";
        cout << "2. Mostrar matrices actuales\n";
        cout << "3. Transpuesta\n";
        cout << "4. Determinante e inversa\n";
        cout << "5. Operadores basicos (+, -, *, /)\n";
        cout << "6. Matriz de escala y rotacion\n";
        cout << "7. Comparacion (==, !=)\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        cout.precision(4);
        cout << fixed;

        switch (option) {
        case 1:
            cout << "Ingrese valores para la matriz 1 (m00 m01 m10 m11): ";
            cin >> a >> b >> c >> d;
            m1 = EngineUtilities::Matriz2x2(a, b, c, d);

            cout << "Ingrese valores para la matriz 2 (m00 m01 m10 m11): ";
            cin >> a >> b >> c >> d;
            m2 = EngineUtilities::Matriz2x2(a, b, c, d);
            break;

        case 2:
            cout << "Matriz 1:\n";
            cout << m1.m00 << "  " << m1.m01 << "\n";
            cout << m1.m10 << "  " << m1.m11 << "\n";

            cout << "Matriz 2:\n";
            cout << m2.m00 << "  " << m2.m01 << "\n";
            cout << m2.m10 << "  " << m2.m11 << "\n";
            break;

        case 3: {
            EngineUtilities::Matriz2x2 t1 = m1.transpose();
            EngineUtilities::Matriz2x2 t2 = m2.transpose();

            cout << "Transpuesta de Matriz 1:\n";
            cout << t1.m00 << "  " << t1.m01 << "\n";
            cout << t1.m10 << "  " << t1.m11 << "\n";

            cout << "Transpuesta de Matriz 2:\n";
            cout << t2.m00 << "  " << t2.m01 << "\n";
            cout << t2.m10 << "  " << t2.m11 << "\n";
            break;
        }

        case 4: {
            double det1 = m1.determinant();
            double det2 = m2.determinant();

            cout << "Determinante de Matriz 1: " << det1 << endl;
            cout << "Determinante de Matriz 2: " << det2 << endl;

            if (fabs(det1) > EngineUtilities::EPSILON) {
                EngineUtilities::Matriz2x2 inv1 = m1.inverse();
                cout << "Inversa de Matriz 1:\n";
                cout << inv1.m00 << "  " << inv1.m01 << "\n";
                cout << inv1.m10 << "  " << inv1.m11 << "\n";
            }
            else {
                cout << "Matriz 1 no es invertible.\n";
            }

            if (fabs(det2) > EngineUtilities::EPSILON) {
                EngineUtilities::Matriz2x2 inv2 = m2.inverse();
                cout << "Inversa de Matriz 2:\n";
                cout << inv2.m00 << "  " << inv2.m01 << "\n";
                cout << inv2.m10 << "  " << inv2.m11 << "\n";
            }
            else {
                cout << "Matriz 2 no es invertible.\n";
            }
            break;
        }

        case 5: {
            EngineUtilities::Matriz2x2 suma = m1 + m2;
            EngineUtilities::Matriz2x2 resta = m1 - m2;
            EngineUtilities::Matriz2x2 producto = m1 * m2;

            cout << "Ingrese escalar para multiplicar/dividir: ";
            cin >> scalar;

            EngineUtilities::Matriz2x2 escalar = m1 * scalar;
            EngineUtilities::Matriz2x2 division = m1 / scalar;

            cout << "Suma:\n";
            cout << suma.m00 << "  " << suma.m01 << "\n";
            cout << suma.m10 << "  " << suma.m11 << "\n";

            cout << "Resta:\n";
            cout << resta.m00 << "  " << resta.m01 << "\n";
            cout << resta.m10 << "  " << resta.m11 << "\n";

            cout << "Producto (matricial):\n";
            cout << producto.m00 << "  " << producto.m01 << "\n";
            cout << producto.m10 << "  " << producto.m11 << "\n";

            cout << "Producto por escalar (" << scalar << "):\n";
            cout << escalar.m00 << "  " << escalar.m01 << "\n";
            cout << escalar.m10 << "  " << escalar.m11 << "\n";

            cout << "Division por escalar (" << scalar << "):\n";
            cout << division.m00 << "  " << division.m01 << "\n";
            cout << division.m10 << "  " << division.m11 << "\n";
            break;
        }

        case 6: {
            cout << "Ingrese factor de escala X: ";
            cin >> a;
            cout << "Ingrese factor de escala Y: ";
            cin >> b;
            EngineUtilities::Matriz2x2 scale = EngineUtilities::Matriz2x2::Scale(a, b);
            cout << "Matriz de escala:\n";
            cout << scale.m00 << "  " << scale.m01 << "\n";
            cout << scale.m10 << "  " << scale.m11 << "\n";

            cout << "Ingrese ángulo en radianes para rotación: ";
            cin >> angle;
            EngineUtilities::Matriz2x2 rotate = EngineUtilities::Matriz2x2::Rotate(angle);
            cout << "Matriz de rotación:\n";
            cout << rotate.m00 << "  " << rotate.m01 << "\n";
            cout << rotate.m10 << "  " << rotate.m11 << "\n";
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
