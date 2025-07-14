#include <iostream>
#include "../include/Vector/CQuaternion.h"
using namespace std;

void testCQuaternion() {
    int option;
    float x1, y1, z1, w1, x2, y2, z2, w2, scalar, t, angleRad;
    EngineUtilities::CVector3 axis, vectorToRotate;

    do {
        cout << "\n=== Menu - Prueba de CQuaternion ===\n";
        cout << "1. Ingresar quaterniones\n";
        cout << "2. Operadores basicos (+, -, *, escalado)\n";
        cout << "3. Acceso a elementos ([]), longitud y producto punto\n";
        cout << "4. Normalizacion y conjugado\n";
        cout << "5. Rotacion de vector 3D\n";
        cout << "6. Crear desde eje-angulo\n";
        cout << "7. Interpolacion esferica (slerp)\n";
        cout << "8. Comparacion (==, !=)\n";
        cout << "9. Valores predefinidos (identity, zero)\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        cout.precision(4);
        cout << fixed;

        switch (option) {
        case 1:
            cout << "Ingrese Quaternion 1 (x y z w): ";
            cin >> x1 >> y1 >> z1 >> w1;
            cout << "Ingrese Quaternion 2 (x y z w): ";
            cin >> x2 >> y2 >> z2 >> w2;
            break;

        case 2: {
            EngineUtilities::CQuaternion q1(x1, y1, z1, w1);
            EngineUtilities::CQuaternion q2(x2, y2, z2, w2);

            EngineUtilities::CQuaternion suma = q1 + q2;
            EngineUtilities::CQuaternion resta = q1 - q2;
            EngineUtilities::CQuaternion producto = q1 * q2;
            cout << "q1 + q2 = " << suma << endl;
            cout << "q1 - q2 = " << resta << endl;
            cout << "q1 * q2 = " << producto << endl;

            cout << "Ingrese escalar para multiplicar: ";
            cin >> scalar;
            EngineUtilities::CQuaternion escalar = q1 * scalar;
            cout << "q1 * " << scalar << " = " << escalar << endl;
            break;
        }

        case 3: {
            EngineUtilities::CQuaternion q(x1, y1, z1, w1);
            cout << "Acceso por indice:\n";
            cout << "q[0] = " << q[0] << ", "
                << "q[1] = " << q[1] << ", "
                << "q[2] = " << q[2] << ", "
                << "q[3] = " << q[3] << endl;

            cout << "lengthSquare(q) = " << q.lengthSquare() << endl;
            cout << "length(q) = " << q.length() << endl;
            cout << "dot(q1, q2) = " << q.dot(EngineUtilities::CQuaternion(x2, y2, z2, w2)) << endl;
            break;
        }

        case 4: {
            EngineUtilities::CQuaternion q(x1, y1, z1, w1);
            EngineUtilities::CQuaternion norm = q.normalized();
            EngineUtilities::CQuaternion conj = q.conjugate();
            cout << "normalized(q) = " << norm << endl;
            cout << "conjugate(q) = " << conj << endl;
            break;
        }

        case 5: {
            EngineUtilities::CQuaternion q(x1, y1, z1, w1);
            cout << "Ingrese vector 3D a rotar (x y z): ";
            cin >> vectorToRotate.x >> vectorToRotate.y >> vectorToRotate.z;
            cout << "Resultado: " << q.rotate(vectorToRotate) << endl;
            break;
        }

        case 6:
            cout << "Ingrese eje de rotacion (x y z): ";
            cin >> axis.x >> axis.y >> axis.z;
            cout << "Ingrese angulo en radianes: ";
            cin >> angleRad;
            cout << "fromAxisAngle(axis, angleRad) = "
                << EngineUtilities::CQuaternion::fromAxisAngle(axis, angleRad) << endl;
            break;

        case 7:
            cout << "Ingrese factor de interpolacion t [0..1]: ";
            cin >> t;
            cout << "slerp(q1, q2, " << t << ") = "
                << EngineUtilities::CQuaternion::slerp(
                    EngineUtilities::CQuaternion(x1, y1, z1, w1),
                    EngineUtilities::CQuaternion(x2, y2, z2, w2), t)
                << endl;
            break;

        case 8: {
            EngineUtilities::CQuaternion q1(x1, y1, z1, w1);
            EngineUtilities::CQuaternion q2(x2, y2, z2, w2);
            cout << "q1 == q2 -> " << (q1 == q2 ? "true" : "false") << endl;
            cout << "q1 != q2 -> " << (q1 != q2 ? "true" : "false") << endl;
            break;
        }

        case 9:
            cout << "identity() = " << EngineUtilities::CQuaternion::identity() << endl;
            cout << "zero() = " << EngineUtilities::CQuaternion::zero() << endl;
            break;

        case 0:
            cout << "Volviendo al menu principal...\n";
            break;

        default:
            cout << "Opcion no valida.\n";
        }

    } while (option != 0);
}
