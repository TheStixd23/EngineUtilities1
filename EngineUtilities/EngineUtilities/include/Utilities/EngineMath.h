#pragma once
#include <cmath>

namespace EngineUtilities {

    const double PI = 3.14159265358979323846;
    const double EULER = 2.71828182845904523536;
    const double EPSILON = 1e-6;

    inline double sqrt(double x) {
        if (x < 0.0) return NAN;
        double guess = x / 2.0;
        for (int i = 0; i < 20; ++i) {
            guess = (guess + x / guess) / 2.0;
        }
        return guess;
    }

    inline double square(double x) {
        return x * x;
    }

    inline double cube(double x) {
        return x * x * x;
    }

    inline double power(double base, double exponent) {
        if (base == 0.0) {
            if (exponent <= 0.0) return NAN;
            return 0.0;
        }
        if (exponent == 0.0) return 1.0;
        if (base < 0.0) return NAN;
        return exp(exponent * log(base));
    }

    inline double abs(double x) {
        return x < 0 ? -x : x;
    }

    inline double EMax(double a, double b) {
        return a > b ? a : b;
    }

    inline double EMin(double a, double b) {
        return a < b ? a : b;
    }

    inline int round(double x) {
        return (x >= 0.0) ? int(x + 0.5) : int(x - 0.5);
    }

    inline int floor(double x) {
        int i = int(x);
        return (x < 0.0 && x != i) ? i - 1 : i;
    }

    inline int ceil(double x) {
        int i = int(x);
        return (x > 0.0 && x != i) ? i + 1 : i;
    }

    inline double fabs(double x) {
        return x < 0 ? -x : x;
    }

    inline double mod(double a, double b) {
        while (a >= b) a -= b;
        while (a < 0) a += b;
        return a;
    }

    inline double exp(double x) {
        double result = 1.0;
        double term = 1.0;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= x / n++;
            result += term;
        }
        return result;
    }

    inline double log(double x) {
        if (x <= 0) return NAN;
        double y = (x - 1) / (x + 1);
        double result = 0.0;
        double term = y;
        int n = 1;
        while (fabs(term) > EPSILON) {
            result += term / (2 * n - 1);
            term *= y * y;
            ++n;
        }
        return 2 * result;
    }

    inline double log10(double x) {
        const double ln10 = 2.302585093;
        return log(x) / ln10;
    }

    inline double radians(double degrees) {
        return degrees * (PI / 180.0);
    }

    inline double degrees(double radians) {
        return radians * (180.0 / PI);
    }

    inline double sin(double x) {
        x = mod(x, 2 * PI);
        double result = x;
        double term = x;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= -x * x / ((2 * n) * (2 * n + 1));
            result += term;
            ++n;
        }
        return result;
    }

    inline double cos(double x) {
        x = mod(x, 2 * PI);
        double result = 1.0;
        double term = 1.0;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= -x * x / ((2 * n - 1) * (2 * n));
            result += term;
            ++n;
        }
        return result;
    }

    inline double tan(double x) {
        double s = sin(x);
        double c = cos(x);
        return c != 0 ? s / c : INFINITY;
    }

    inline double asin(double x) {
        if (x < -1 || x > 1) return NAN;
        double result = x;
        double term = x;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= (2.0 * n - 1) * (2.0 * n - 1) * x * x / ((2.0 * n) * (2.0 * n + 1));
            result += term;
            ++n;
        }
        return result;
    }

    inline double acos(double x) {
        return PI / 2 - asin(x);
    }

    inline double atan(double x) {
        double result = x;
        double term = x;
        int n = 1;
        while (fabs(term) > EPSILON) {
            term *= -x * x * (2.0 * n - 1) / (2.0 * n + 1);
            result += term;
            ++n;
        }
        return result;
    }

    inline double sinh(double x) {
        return (exp(x) - exp(-x)) / 2.0;
    }

    inline double cosh(double x) {
        return (exp(x) + exp(-x)) / 2.0;
    }

    inline double tanh(double x) {
        double e2x = exp(2 * x);
        return (e2x - 1) / (e2x + 1);
    }

    inline double circleArea(double radius) {
        return PI * radius * radius;
    }

    inline double circleCircumference(double radius) {
        return 2 * PI * radius;
    }

    inline double rectangleArea(double width, double height) {
        return width * height;
    }

    inline double rectanglePerimeter(double width, double height) {
        return 2 * (width + height);
    }

    inline double triangleArea(double base, double height) {
        return 0.5 * base * height;
    }

    inline double distance(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        return sqrt(dx * dx + dy * dy);
    }

    inline double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }

    inline double factorial(int n) {
        if (n < 0) return NAN;
        double result = 1.0;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    inline bool approxEqual(double a, double b, double epsilon = 1e-6) {
        return abs(a - b) < epsilon;
    }

}
