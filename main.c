#include <stdio.h>
#include "my_func.h"

int main() {
    int n;
    double a, b, c;

    puts("Vvedite nomer sposoba resheniya:");
    scanf("%d", &n);

    puts("Vvedite coefficienti uravneniya (a, b, c):");
    scanf("%lf%lf%lf", &a, &b, &c);

    struct vec2 (*arr[10])(double, double, double) = {
        f1, f2, f3, f4, f5,
        f6, f7, f8, f9, f10
    };

    struct vec2 ans = arr[n - 1](a, b, c);
    printf("%.3lf %.3lf\n", ans.x1, ans.x2);

    return 0;
}
