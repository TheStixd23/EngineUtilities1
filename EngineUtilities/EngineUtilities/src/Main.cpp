/**
 * @file MainTest.cpp
 * @brief Punto de entrada principal para probar los módulos de la EngineMathLib.
 * @author Hannin Abarca
 */

#include <iostream>
using namespace std;

// Declaraciones de funciones de prueba

/**
 * @brief Prueba las funciones básicas de EngineMath.
 */
void testEngineMath();

/**
 * @brief Prueba la estructura CVector2.
 */
void testCVector2();

/**
 * @brief Prueba la estructura CVector3.
 */
void testCVector3();

/**
 * @brief Prueba la estructura CVector4.
 */
void testCVector4();

/**
 * @brief Prueba la clase CQuaternion.
 */
void testCQuaternion();

/**
 * @brief Prueba la clase de matriz 2x2.
 */
void testMatriz2x2();

/**
 * @brief Prueba la clase de matriz 3x3.
 */
void testMatriz3x3();

/**
 * @brief Prueba la clase de matriz 4x4.
 */
void testMatriz4x4();

/**
 * @brief Función principal que muestra un menú para seleccionar y ejecutar pruebas de EngineMathLib.
 * @return 0 al finalizar el programa.
 */
int main() {
    int option;
    do {
        cout << "\nMenu Principal-Pruebas del EngineMathLib\n";
        cout << "1. Probar EngineMath\n";
        cout << "2. Probar CVector2\n";
        cout << "3. Probar CVector3\n";
        cout << "4. Probar CVector4\n";
        cout << "5. Probar Quaternion\n";
        cout << "6. Probar Matrix2x2\n";
        cout << "7. Probar Matrix3x3\n";
        cout << "8. Probar Matrix4x4\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option) {
        case 1: {
            testEngineMath();
            break;
        }
        case 2: {
            testCVector2();
            break;
        }
        case 3: {
            testCVector3();
            break;
        }
        case 4: {
            testCVector4();
            break;
        }
        case 5: {
            testCQuaternion();
            break;
        }
        case 6: {
            testMatriz2x2();
            break;
        }
        case 7: {
            testMatriz3x3();
            break;
        }
        case 8: {
            testMatriz4x4();
            break;
        }
        case 0: {
            cout << "Saliendo del programa...\n";
            break;
        }
        default: {
            cout << "Opcion no valida. Intente nuevamente.\n";
            break;
        }
        }

    } while (option != 0);

    return 0;
}
