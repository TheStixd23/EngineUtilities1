#include <iostream>
#include "../include/Utilities/EngineMath.h"

using namespace std;

void testEngineMath() {
    int option;
    do {
        cout << "\n=== Menu - Prueba de EngineMath ===\n";
        cout << "1. Mostrar constantes\n";
        cout << "2. Funciones basicas\n";
        cout << "3. Trigonometria\n";
        cout << "4. Conversion angular\n";
        cout << "5. Geometria\n";
        cout << "6. Funciones utiles\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        cout.precision(6);
        cout << fixed;

        switch (option) {
        case 1:
            cout << "\n--- CONSTANTES ---\n";
            cout << "PI = " << EngineUtilities::PI << endl;
            cout << "EULER = " << EngineUtilities::EULER << endl;
            cout << "EPSILON = " << EngineUtilities::EPSILON << endl;
            break;

        case 2: {
            double a, b;
            cout << "\n--- FUNCIONES BASICAS ---\n";
            cout << "Ingrese valor a: ";
            cin >> a;
            cout << "Ingrese valor b: ";
            cin >> b;

            cout << "sqrt(a) = " << EngineUtilities::sqrt(a) << endl;
            cout << "square(a) = " << EngineUtilities::square(a) << endl;
            cout << "cube(a) = " << EngineUtilities::cube(a) << endl;
            cout << "power(a, b) = " << EngineUtilities::power(a, b) << endl;
            cout << "abs(-a) = " << EngineUtilities::abs(-a) << endl;
            cout << "EMax(a, b) = " << EngineUtilities::EMax(a, b) << endl;
            cout << "EMin(a, b) = " << EngineUtilities::EMin(a, b) << endl;
            cout << "round(a) = " << EngineUtilities::round(a) << endl;
            cout << "floor(a) = " << EngineUtilities::floor(a) << endl;
            cout << "ceil(a) = " << EngineUtilities::ceil(a) << endl;
            cout << "fabs(-a) = " << EngineUtilities::fabs(-a) << endl;
            cout << "mod(a, b) = " << EngineUtilities::mod(a, b) << endl;
            cout << "exp(a) = " << EngineUtilities::exp(a) << endl;
            cout << "log(a) = " << EngineUtilities::log(a) << endl;
            cout << "log10(a) = " << EngineUtilities::log10(a) << endl;
            break;
        }

        case 3: {
            double rad, val;
            cout << "\n--- TRIGONOMETRIA ---\n";
            cout << "Ingrese angulo en radianes: ";
            cin >> rad;
            cout << "sin(rad) = " << EngineUtilities::sin(rad) << endl;
            cout << "cos(rad) = " << EngineUtilities::cos(rad) << endl;
            cout << "tan(rad) = " << EngineUtilities::tan(rad) << endl;

            cout << "Ingrese valor para asin (entre -1 y 1): ";
            cin >> val;
            if (val < -1.0 || val > 1.0) {
                cout << "Error: El valor para asin debe estar entre -1 y 1.\n";
            }
            else {
                cout << "asin(val) = " << EngineUtilities::asin(val) << endl;
            }

            cout << "Ingrese valor para acos (entre -1 y 1): ";
            cin >> val;
            if (val < -1.0 || val > 1.0) {
                cout << "Error: El valor para acos debe estar entre -1 y 1.\n";
            }
            else {
                cout << "acos(val) = " << EngineUtilities::acos(val) << endl;
            }

            cout << "Ingrese valor para atan: ";
            cin >> val;
            cout << "atan(val) = " << EngineUtilities::atan(val) << endl;

            cout << "sinh(a) = " << EngineUtilities::sinh(rad) << endl;
            cout << "cosh(a) = " << EngineUtilities::cosh(rad) << endl;
            cout << "tanh(a) = " << EngineUtilities::tanh(rad) << endl;
            break;
        }

        case 4: {
            double deg, rad;
            cout << "\n--- CONVERSION ANGULAR ---\n";
            cout << "Ingrese grados: ";
            cin >> deg;
            cout << "radians(deg) = " << EngineUtilities::radians(deg) << endl;

            cout << "Ingrese radianes: ";
            cin >> rad;
            cout << "degrees(rad) = " << EngineUtilities::degrees(rad) << endl;
            break;
        }

        case 5: {
            double r, w, h, b, ht, x1, y1, x2, y2;
            cout << "\n--- GEOMETRIA ---\n";

            cout << "Radio del circulo: ";
            cin >> r;
            cout << "circleArea(r) = " << EngineUtilities::circleArea(r) << endl;
            cout << "circleCircumference(r) = " << EngineUtilities::circleCircumference(r) << endl;

            cout << "Ancho y alto del rectangulo: ";
            cin >> w >> h;
            cout << "rectangleArea(w, h) = " << EngineUtilities::rectangleArea(w, h) << endl;
            cout << "rectanglePerimeter(w, h) = " << EngineUtilities::rectanglePerimeter(w, h) << endl;

            cout << "Base y altura del triangulo: ";
            cin >> b >> ht;
            cout << "triangleArea(b, ht) = " << EngineUtilities::triangleArea(b, ht) << endl;

            cout << "Coordenadas de dos puntos (x1 y1 x2 y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "distance(x1, y1, x2, y2) = " << EngineUtilities::distance(x1, y1, x2, y2) << endl;
            break;
        }

        case 6: {
            double a, b, t;
            int n;
            cout << "\n--- FUNCIONES UTILES ---\n";

            cout << "Ingrese a y b para lerp: ";
            cin >> a >> b;
            cout << "Ingrese factor de interpolacion t (0..1): ";
            cin >> t;
            cout << "lerp(a, b, t) = " << EngineUtilities::lerp(a, b, t) << endl;

            cout << "Ingrese numero para factorial: ";
            cin >> n;
            cout << "factorial(n) = " << EngineUtilities::factorial(n) << endl;

            cout << "Comprobar si a ≈ b:\n";
            cout << "a: ";
            cin >> a;
            cout << "b: ";
            cin >> b;
            cout << "epsilon: ";
            cin >> t;
            cout << "approxEqual(a, b, epsilon) = " << EngineUtilities::approxEqual(a, b, t) << endl;
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
