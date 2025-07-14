/**
 * @file testCVector2.cpp
 * @brief Prueba interactiva de la clase CVector2 del módulo EngineUtilities.
 * @author Hannin Abarca
 */

#include <iostream>
#include "../include/Vector/CVector2.h"
using namespace std;

/**
 * @brief Ejecuta un menú interactivo para probar las funcionalidades de la clase CVector2.
 *
 * Este menú permite:
 * - Ingresar vectores manualmente.
 * - Realizar operaciones básicas: suma, resta, multiplicación y división.
 * - Usar operadores de asignación: +=, -=, *=, /=.
 * - Comparar vectores con == y !=.
 * - Acceder a elementos mediante índices.
 * - Calcular longitud, magnitud y producto punto/cruz.
 * - Normalizar vectores.
 * - Usar funciones estáticas como distance, lerp, zero y one.
 * - Aplicar transformaciones como setPosition, move, setScale y scale.
 */
void testCVector2() {
    int option;
    float x1, y1, x2, y2, scalar;
    EngineUtilities::CVector2 v1, v2;

    do {
        cout << "\nMenu - Prueba de CVector2\n";
        cout << "1. Ingresar vectores\n";
        cout << "2. Operadores basicos (+, -, *, /)\n";
        cout << "3. Operadores asignacion (+=, -=, *=, /=)\n";
        cout << "4. Comparacion (==, !=)\n";
        cout << "5. Acceso a elementos ([])\n";
        cout << "6. Longitud y magnitud\n";
        cout << "7. Producto punto y cruz\n";
        cout << "8. Normalizacion\n";
        cout << "9. Funciones estaticas (distance, lerp, zero, one)\n";
        cout << "10. Modificacion de posicion y escala\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Ingrese Vector 1 (x y): ";
            cin >> x1 >> y1;
            v1 = EngineUtilities::CVector2(x1, y1);

            cout << "Ingrese Vector 2 (x y): ";
            cin >> x2 >> y2;
            v2 = EngineUtilities::CVector2(x2, y2);
            cout << "Vectores ingresados:\n";
            cout << "v1 = " << v1 << "\nv2 = " << v2 << endl;
            break;

        case 2: {
            EngineUtilities::CVector2 suma = v1 + v2;
            EngineUtilities::CVector2 resta = v1 - v2;
            EngineUtilities::CVector2 producto = v1 * 2.0f;
            EngineUtilities::CVector2 division = v1 / 2.0f;

            cout << "v1 + v2 = " << suma << endl;
            cout << "v1 - v2 = " << resta << endl;
            cout << "v1 * 2 = " << producto << endl;
            cout << "v1 / 2 = " << division << endl;
            break;
        }

        case 3: {
            EngineUtilities::CVector2 temp1 = v1;
            EngineUtilities::CVector2 temp2 = v2;
            temp1 += temp2;
            cout << "v1 += v2 -> v1 = " << temp1 << endl;

            temp1 = v1;
            temp1 -= temp2;
            cout << "v1 -= v2 -> v1 = " << temp1 << endl;

            temp1 = v1;
            cout << "Ingrese escalar para *=: ";
            cin >> scalar;
            temp1 *= scalar;
            cout << "v1 *= " << scalar << " -> v1 = " << temp1 << endl;

            temp1 = v1;
            cout << "Ingrese escalar para /=: ";
            cin >> scalar;
            if (scalar != 0.0f) {
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

        case 5: {
            int index;
            cout << "Ingrese indice [0=x, 1=y]: ";
            cin >> index;
            if (index == 0 || index == 1)
                cout << "Elemento [" << index << "] = " << v1[index] << endl;
            else
                cout << "Indice invalido.\n";
            break;
        }

        case 6:
            cout << "lengthSquare(v1) = " << v1.lengthSquare() << endl;
            cout << "length(v1) = " << v1.length() << endl;
            break;

        case 7:
            cout << "dot(v1, v2) = " << v1.dot(v2) << endl;
            cout << "cross(v1, v2) = " << v1.cross(v2) << endl;
            break;

        case 8: {
            EngineUtilities::CVector2 norm1 = v1.normalized();
            EngineUtilities::CVector2 norm2 = v2.normalized();

            EngineUtilities::CVector2 copy = v1;
            copy.normalize();
            cout << "normalized(v1) = " << norm1 << endl;
            cout << "normalized(v2) = " << norm2 << endl;
            cout << "normalize(&v1) = " << copy << endl;
            break;
        }

        case 9:
            cout << "distance(v1, v2) = " << EngineUtilities::CVector2::distance(v1, v2) << endl;
            cout << "lerp(v1, v2, 0.5) = " << EngineUtilities::CVector2::lerp(v1, v2, 0.5f) << endl;
            cout << "zero() = " << EngineUtilities::CVector2::zero() << endl;
            cout << "one() = " << EngineUtilities::CVector2::one() << endl;
            break;

        case 10: {
            EngineUtilities::CVector2 position, offset, factors;

            cout << "Ingresar nueva posicion (x y): ";
            cin >> position.x >> position.y;
            v1.setPosition(position);
            cout << "setPosition -> v1 = " << v1 << endl;

            cout << "Ingresar desplazamiento (x y): ";
            cin >> offset.x >> offset.y;
            v1.move(offset);
            cout << "move -> v1 = " << v1 << endl;

            cout << "Ingresar factores de escala (x y): ";
            cin >> factors.x >> factors.y;
            v1.setScale(factors);
            cout << "setScale -> v1 = " << v1 << endl;

            v1.scale(factors);
            cout << "scale -> v1 = " << v1 << endl;
            break;
        }

        case 0:
            cout << "Volviendo al menu principal...\n";
            break;

        default:
            cout << "Opcion no valida.\n";
        }

    } while (option != 0);
}
