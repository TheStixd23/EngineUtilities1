#include <iostream>
using namespace std;

// Declaraciones de funciones de prueba
void 
testEngineMath();
void 
testCVector2();
void 
testCVector3();
void 
testCVector4();
void 
testCQuaternion();
void 
testMatriz2x2();
void 
testMatriz3x3();
void 
testMatriz4x4();

int 
main() {
  int option;
  do {
    cout << "\n=== Menu Principal - Pruebas de EngineMathLib ===\n";
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
