#include <math.h>
#include <stdlib.h>
// #include <stdio.h>

// struct vec2 {
//     double x1, x2;
// };

double D(double a, double b, double c) {
    double ans = b * b - 4 * a * c;

    return ans >= 0 ? sqrt(ans) : -1;
}

double X0(double a, double b) { return -b / (2 * a); }
double X1(double a, double b, double d) { return (-b + d) / (2 * a); }
double X2(double a, double b, double d) { return (-b - d) / (2 * a); }

// char PM(double n) { return n > 0 ? '+' : '-'; }
// void sol(double a, double b, double c) {
//     double d = D(a, b, c);
//
//     if (d > 0)
//         printf("x1 = %lf, x2 = %lf\n", x1(a, b, d), x2(a, b, d));
//     else if (d == 0)
//         printf("x = %lf\n", x0(a, b));
//     else if (d < 0)
//         printf("U dannogo uravneniya net resheniy!");
// }
