/**
 * @file EngineMath.h
 * @brief Librería matemática personalizada sin dependencias estándar.
 * @author Hannin Abarca
 */

#pragma once

namespace EngineUtilities {

    // --- Constantes Matemáticas ---
    const double PI = 3.14159265358979323846;
    const double EULER = 2.71828182845904523536;
    const double EPSILON = 1e-6;

    // --- Funciones Aritméticas Básicas ---

    /// @brief Valor absoluto.
    inline double abs(double x) { return x < 0 ? -x : x; }

    /// @brief Valor absoluto en punto flotante.
    inline double fabs(double x) { return x < 0 ? -x : x; }

    /// @brief Cuadrado de un número.
    inline double square(double x) { return x * x; }

    /// @brief Cubo de un número.
    inline double cube(double x) { return x * x * x; }

    /// @brief Máximo entre dos valores.
    inline double EMax(double a, double b) { return a > b ? a : b; }

    /// @brief Mínimo entre dos valores.
    inline double EMin(double a, double b) { return a < b ? a : b; }

    /// @brief Redondeo al entero más cercano.
    inline int round(double x) { return (x >= 0.0) ? int(x + 0.5) : int(x - 0.5); }

    /// @brief Piso (redondeo hacia abajo).
    inline int floor(double x) {
        int i = int(x);
        return (x < 0.0 && x != i) ? i - 1 : i;
    }

    /// @brief Techo (redondeo hacia arriba).
    inline int ceil(double x) {
        int i = int(x);
        return (x > 0.0 && x != i) ? i + 1 : i;
    }

    /// @brief Módulo entre dos números.
    inline double mod(double a, double b) {
        while (a >= b) a -= b;
        while (a < 0) a += b;
        return a;
    }

    // --- Funciones Avanzadas ---

    /// @brief Raíz cuadrada por método de Newton.
    inline double sqrt(double x) {
        if (x < 0.0) return NAN;
        double guess = x / 2.0;
        for (int i = 0; i < 20; ++i) guess = (guess + x / guess) / 2.0;
        return guess;
    }

    /// @brief Potencia base^exponente.
    inline double power(double base, double exponent) {
        if (base == 0.0) return (exponent <= 0.0) ? NAN : 0.0;
        if (exponent == 0.0) return 1.0;
        if (base < 0.0) return NAN;
        return exp(exponent * log(base));
    }

    /// @brief Exponencial e^x por serie.
    inline double exp(double x) {
        double result = 1.0, term = 1.0;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= x / n++;
            result += term;
        }
        return result;
    }

    /// @brief Logaritmo natural.
    inline double log(double x) {
        if (x <= 0) return NAN;
        double y = (x - 1) / (x + 1), result = 0.0, term = y;
        int n = 1;
        while (fabs(term) > EPSILON) {
            result += term / (2 * n - 1);
            term *= y * y;
            ++n;
        }
        return 2 * result;
    }

    /// @brief Logaritmo en base 10.
    inline double log10(double x) {
        const double ln10 = 2.302585093;
        return log(x) / ln10;
    }

    // --- Trigonometría ---

    /// @brief Conversión de grados a radianes.
    inline double radians(double degrees) { return degrees * (PI / 180.0); }

    /// @brief Conversión de radianes a grados.
    inline double degrees(double radians) { return radians * (180.0 / PI); }

    /// @brief Seno por serie de Taylor.
    inline double sin(double x) {
        x = mod(x, 2 * PI);
        double result = x, term = x;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= -x * x / ((2 * n) * (2 * n + 1));
            result += term;
            ++n;
        }
        return result;
    }

    /// @brief Coseno por serie de Taylor.
    inline double cos(double x) {
        x = mod(x, 2 * PI);
        double result = 1.0, term = 1.0;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= -x * x / ((2 * n - 1) * (2 * n));
            result += term;
            ++n;
        }
        return result;
    }

    /// @brief Tangente.
    inline double tan(double x) {
        double s = sin(x), c = cos(x);
        return c != 0 ? s / c : INFINITY;
    }

    /// @brief Arco seno (asin).
    inline double asin(double x) {
        if (x < -1 || x > 1) return NAN;
        double result = x, term = x;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= (2.0 * n - 1) * (2.0 * n - 1) * x * x / ((2.0 * n) * (2.0 * n + 1));
            result += term;
            ++n;
        }
        return result;
    }

    /// @brief Arco coseno (acos).
    inline double acos(double x) { return PI / 2 - asin(x); }

    /// @brief Arco tangente (atan).
    inline double atan(double x) {
        double result = x, term = x;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= -x * x * (2.0 * n - 1) / (2.0 * n + 1);
            result += term;
            ++n;
        }
        return result;
    }

    /// @brief Seno hiperbólico.
    inline double sinh(double x) { return (exp(x) - exp(-x)) / 2.0; }

    /// @brief Coseno hiperbólico.
    inline double cosh(double x) { return (exp(x) + exp(-x)) / 2.0; }

    /// @brief Tangente hiperbólica.
    inline double tanh(double x) {
        double e2x = exp(2 * x);
        return (e2x - 1) / (e2x + 1);
    }

    // --- Geometría ---

    /// @brief Área de un círculo.
    inline double circleArea(double radius) {
        return PI * radius * radius;
    }

    /// @brief Perímetro de un círculo.
    inline double circleCircumference(double radius) {
        return 2 * PI * radius;
    }

    /// @brief Área de un rectángulo.
    inline double rectangleArea(double width, double height) {
        return width * height;
    }

    /// @brief Perímetro de un rectángulo.
    inline double rectanglePerimeter(double width, double height) {
        return 2 * (width + height);
    }

    /// @brief Área de un triángulo.
    inline double triangleArea(double base, double height) {
        return 0.5 * base * height;
    }

    /// @brief Distancia entre dos puntos.
    inline double distance(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1, dy = y2 - y1;
        return sqrt(dx * dx + dy * dy);
    }

    // --- Funciones Utilitarias ---

    /// @brief Interpolación lineal.
    inline double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }

    /// @brief Factorial de un número.
    inline double factorial(int n) {
        if (n < 0) return NAN;
        double result = 1.0;
        for (int i = 2; i <= n; ++i) result *= i;
        return result;
    }

    /// @brief Compara si dos valores son aproximadamente iguales.
    inline bool approxEqual(double a, double b, double epsilon = EPSILON) {
        return abs(a - b) < epsilon;
    }

}
