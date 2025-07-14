/**
 * @file EngineMathTest.cpp
 * @brief Prueba interactiva para funciones de EngineMath.
 * @author Hannin Abarca
 */

#include <iostream>
#include "../include/Utilities/EngineMath.h"

using namespace std;

/**
 * @brief Función de prueba interactiva para mostrar el uso de EngineMath.
 *
 * Muestra un menú con categorías de funciones matemáticas implementadas en EngineMath,
 * incluyendo constantes, funciones básicas, trigonometría, geometría, conversión angular
 * y utilidades como interpolación y factorial.
 */
void testEngineMath() {
    int option;
    do {
        cout << "\n=== Menú de prueba - EngineMath ===\n";
        cout << "1. Mostrar constantes\n";
        cout << "2. Funciones básicas\n";
        cout << "3. Trigonometría\n";
        cout << "4. Conversión angular\n";
        cout << "5. Geometría\n";
        cout << "6. Funciones útiles\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
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
            cout << "\n--- FUNCIONES BÁSICAS ---\n";
            cout << "Ingrese valor a: "; cin >> a;
            cout << "Ingrese valor b: "; cin >> b;

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
            cout << "\n--- TRIGONOMETRÍA ---\n";
            cout << "Ingrese ángulo en radianes: "; cin >> rad;
            cout << "sin(rad) = " << EngineUtilities::sin(rad) << endl;
            cout << "cos(rad) = " << EngineUtilities::cos(rad) << endl;
            cout << "tan(rad) = " << EngineUtilities::tan(rad) << endl;

            cout << "Ingrese valor para asin (entre -1 y 1): "; cin >> val;
            if (val < -1.0 || val > 1.0)
                cout << "Error: El valor debe estar entre -1 y 1.\n";
            else
                cout << "asin(val) = " << EngineUtilities::asin(val) << endl;

            cout << "Ingrese valor para acos (entre -1 y 1): "; cin >> val;
            if (val < -1.0 || val > 1.0)
                cout << "Error: El valor debe estar entre -1 y 1.\n";
            else
                cout << "acos(val) = " << EngineUtilities::acos(val) << endl;

            cout << "Ingrese valor para atan: "; cin >> val;
            cout << "atan(val) = " << EngineUtilities::atan(val) << endl;

            cout << "sinh(rad) = " << EngineUtilities::sinh(rad) << endl;
            cout << "cosh(rad) = " << EngineUtilities::cosh(rad) << endl;
            cout << "tanh(rad) = " << EngineUtilities::tanh(rad) << endl;
            break;
        }

        case 4: {
            double deg, rad;
            cout << "\n--- CONVERSIÓN ANGULAR ---\n";
            cout << "Ingrese grados: "; cin >> deg;
            cout << "radians(deg) = " << EngineUtilities::radians(deg) << endl;

            cout << "Ingrese radianes: "; cin >> rad;
            cout << "degrees(rad) = " << EngineUtilities::degrees(rad) << endl;
            break;
        }

        case 5: {
            double r, w, h, b, ht, x1, y1, x2, y2;
            cout << "\n--- GEOMETRÍA ---\n";

            cout << "Radio del círculo: "; cin >> r;
            cout << "circleArea(r) = " << EngineUtilities::circleArea(r) << endl;
            cout << "circleCircumference(r) = " << EngineUtilities::circleCircumference(r) << endl;

            cout << "Ancho y alto del rectángulo: "; cin >> w >> h;
            cout << "rectangleArea(w, h) = " << EngineUtilities::rectangleArea(w, h) << endl;
            cout << "rectanglePerimeter(w, h) = " << EngineUtilities::rectanglePerimeter(w, h) << endl;

            cout << "Base y altura del triángulo: "; cin >> b >> ht;
            cout << "triangleArea(b, ht) = " << EngineUtilities::triangleArea(b, ht) << endl;

            cout << "Coordenadas de dos puntos (x1 y1 x2 y2): "; cin >> x1 >> y1 >> x2 >> y2;
            cout << "distance(x1, y1, x2, y2) = " << EngineUtilities::distance(x1, y1, x2, y2) << endl;
            break;
        }

        case 6: {
            double a, b, t;
            int n;
            cout << "\n--- FUNCIONES ÚTILES ---\n";

            cout << "Ingrese a y b para lerp: "; cin >> a >> b;
            cout << "Ingrese t (0..1): "; cin >> t;
            cout << "lerp(a, b, t) = " << EngineUtilities::lerp(a, b, t) << endl;

            cout << "Ingrese número para factorial: "; cin >> n;
            cout << "factorial(n) = " << EngineUtilities::factorial(n) << endl;

            cout << "Comprobar si a ≈ b:\n";
            cout << "a: "; cin >> a;
            cout << "b: "; cin >> b;
            cout << "epsilon: "; cin >> t;
            cout << "approxEqual(a, b, epsilon) = " << EngineUtilities::approxEqual(a, b, t) << endl;
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
