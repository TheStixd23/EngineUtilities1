/**
 * @file testCVector4.cpp
 * @brief Prueba interactiva de la clase CVector4 del módulo EngineUtilities.
 * @author Hannin Abarca
 */

#include <iostream>
#include "../include/Vector/CVector4.h"
using namespace std;

/**
 * @brief Ejecuta un menú interactivo para probar funcionalidades de la clase CVector4.
 *
 * Este menú permite:
 * - Ingresar vectores manualmente.
 * - Realizar operaciones básicas (+, -, *, /).
 * - Aplicar operadores de asignación (+=, -=, *=, /=).
 * - Comparar vectores con == y !=.
 * - Acceder a componentes por índice con [].
 * - Calcular magnitud y magnitud al cuadrado.
 * - Calcular producto punto.
 * - Normalizar vectores.
 * - Usar funciones estáticas como distance, lerp, zero y one.
 */
void testCVector4() {
    int option;
    float x1, y1, z1, w1, x2, y2, z2, w2, scalar;
    EngineUtilities::CVector4 v1, v2;

    do {
        cout << "\nMenu-Prueba de CVector4\n";
        cout << "1. Ingresar vectores\n";
        cout << "2. Operadores basicos (+, -, *, /)\n";
        cout << "3. Operadores asignacion (+=, -=, *=, /=)\n";
        cout << "4. Comparacion (==, !=)\n";
        cout << "5. Acceso a elementos ([])\n";
        cout << "6. Longitud y magnitud\n";
        cout << "7. Producto punto\n";
        cout << "8. Normalizacion\n";
        cout << "9. Funciones estaticas (distance, lerp, zero, one)\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Ingrese Vector 1 (x y z w): ";
            cin >> x1 >> y1 >> z1 >> w1;
            v1 = EngineUtilities::CVector4(x1, y1, z1, w1);
            cout << "Ingrese Vector 2 (x y z w): ";
            cin >> x2 >> y2 >> z2 >> w2;
            v2 = EngineUtilities::CVector4(x2, y2, z2, w2);
            cout << "Vectores ingresados:\n";
            cout << "v1 = " << v1 << "\nv2 = " << v2 << endl;
            break;

        case 2: {
            EngineUtilities::CVector4 suma = v1 + v2;
            EngineUtilities::CVector4 resta = v1 - v2;
            EngineUtilities::CVector4 producto = v1 * 2.0f;
            EngineUtilities::CVector4 division = v1 / 2.0f;
            cout << "v1 + v2 = " << suma << endl;
            cout << "v1 - v2 = " << resta << endl;
            cout << "v1 * 2 = " << producto << endl;
            cout << "v1 / 2 = " << division << endl;
            break;
        }

        case 3: {
            EngineUtilities::CVector4 temp1 = v1;
            EngineUtilities::CVector4 temp2 = v2;
            temp1 += temp2;
            cout << "v1 += v2 -> v1 = " << temp1 << endl;
            temp1 = v1;
            temp1 -= temp2;
            cout << "v1 -= v2 -> v1 = " << temp1 << endl;
            cout << "Ingrese escalar para *=: ";
            cin >> scalar;
            temp1 = v1;
            temp1 *= scalar;
            cout << "v1 *= " << scalar << " -> v1 = " << temp1 << endl;
            cout << "Ingrese escalar para /=: ";
            cin >> scalar;
            if (scalar != 0.0f) {
                temp1 = v1;
                temp1 /= scalar;
                cout << "v1 /= " << scalar << " -> v1 = " << temp1 << endl;
            }
            else {
                cout << "No se puede dividir por cero.\n";
            }
            break;
        }

        case 4:
            cout << "v1 == v2 -> " << (v1 == v2 ? "true" : "false") << endl;
            cout << "v1 != v2 -> " << (v1 != v2 ? "true" : "false") << endl;
            break;

        case 5:
            int index;
            cout << "Ingrese indice [0=x, 1=y, 2=z, 3=w]: ";
            cin >> index;
            if (index >= 0 && index <= 3)
                cout << "Elemento [" << index << "] = " << v1[index] << endl;
            else
                cout << "Indice invalido.\n";
            break;

        case 6:
            cout << "lengthSquare(v1) = " << v1.lengthSquare() << endl;
            cout << "length(v1) = " << v1.length() << endl;
            break;

        case 7:
            cout << "dot(v1, v2) = " << v1.dot(v2) << endl;
            break;

        case 8: {
            EngineUtilities::CVector4 norm1 = v1.normalized();
            EngineUtilities::CVector4 norm2 = v2.normalized();
            EngineUtilities::CVector4 copy = v1;
            copy.normalize();
            cout << "normalized(v1) = " << norm1 << endl;
            cout << "normalized(v2) = " << norm2 << endl;
            cout << "normalize(&v1) = " << copy << endl;
            break;
        }

        case 9:
            cout << "distance(v1, v2) = " << EngineUtilities::CVector4::distance(v1, v2) << endl;
            cout << "lerp(v1, v2, 0.5) = " << EngineUtilities::CVector4::lerp(v1, v2, 0.5f) << endl;
            cout << "zero() = " << EngineUtilities::CVector4::zero() << endl;
            cout << "one() = " << EngineUtilities::CVector4::one() << endl;
            break;

        case 0:
            cout << "Volviendo al menu principal...\n";
            break;

        default:
            cout << "Opcion no valida.\n";
        }

    } while (option != 0);
}
