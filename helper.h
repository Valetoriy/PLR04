#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double D(double a, double b, double c) {
    double ans = b * b - 4 * a * c;

    return ans >= 0 ? sqrt(ans) : -1;
}

double X1(double a, double b, double d) { return (-b + d) / (2 * a); }
double X2(double a, double b, double d) { return (-b - d) / (2 * a); }
