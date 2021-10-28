#include "helper.h"
#include <stdio.h>

// Разложение на множители
void f1() {
    double a, b, c;

    puts("Способ - разложение на множители");
    puts("Уравнение вида ax^2 + bx + c = 0, (a, b, c) - int");
    puts("Ограничения: a != 0");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = D(a, b, c);

    if (d > 0) {
        double x1 = X1(a, b, d);
        double x2 = X2(a, b, d);

        printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf) <=> (%.1lf)(x - (%.1lf))(x - "
               "(%.1lf))\n",
               a, b, c, a, x1, x2);
        printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);

    } else if (d == 0) {
        double x0 = X0(a, b);

        printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf) <=> (%.1lf)(x - (%.1lf))^2\n",
               a, b, c, a, x0);
        printf("==> x = %.1lf\n", x0);

    } else if (d < 0)
        puts("Данное уравнение нельзя разложить по множетелям!");
}

// Выделение полного квадрата
void f2() {
    double b, c;

    puts("Способ - выделение полного квадрата");
    puts("Уравнение вида x^2 + bx + c = 0, (b, c) - int");
    puts("Ограничения: b - чётное число");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf", &b, &c);

    double temp = b / 2;
    double temp2 = c - temp * temp;
    if (temp2 > 0)
        puts("В данном уравнении нельзя выделить полный квадрат!");

    else if (temp2 == 0) {
        printf("x^2 + (%.1lf)x + (%.1lf) <=> (x + (%.1lf))^2\n", b, c, temp);
        printf("==> x = %.1lf\n", -temp);

    } else if (temp2 < 0) {
        printf("x^2 + (%.1lf)x + (%.1lf) <=> (x + (%.1lf))^2 + (%.1lf)\n", b, c,
               temp, temp2);
        printf("==> x1 = %.1lf, x2 = %.1lf\n", sqrt(-temp2) - temp,
               -sqrt(-temp2) - temp);
    }
}

// Решение по формуле
void f3() {
    double a, b, c;

    puts("Способ - решение по формуле");
    puts("Уравнение вида ax^2 + bx + c = 0, (a, b, c) - int");
    puts("Ограничения: a != 0");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = D(a, b, c);

    if (d > 0) {
        double x1 = X1(a, b, d);
        double x2 = X2(a, b, d);

        printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf), D = (%.1lf)\n", a, b, c, d);
        printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);

    } else if (d == 0) {
        double x0 = X0(a, b);

        printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf), D = 0\n", a, b, c);
        printf("==> x = %.1lf\n", x0);

    } else if (d < 0)
        puts("У данного уравнения нет корней!");
}

// Решение с использованием теоремы Виета
void f4() {
    double p, q;

    puts("Способ - решение с использованием теоремы Виета");
    puts("Уравнение вида x^2 + px + q = 0, (p, q) - int");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf", &p, &q);

    double d = D(1, p, q);

    if (d > 0) {
        double x1 = X1(1, p, d);
        double x2 = X2(1, p, d);

        printf("x^2 + (%.1lf)x + (%.1lf)\n", p, q);
        printf("x1 * x2 = q = (%.1lf), x1 + x2 = -p = -(%.1lf)\n", q, p);
        if (q > 0) {
            puts("Т.к. q > 0 => x1 и x2 одинаковы по знаку");
            if (p < 0)
                puts("Т.к. p < 0 => x1 и x2 - положительны");
            else if (p > 0)
                puts("Т.к. p > 0 => x1 и x2 - отрицательны");
        } else if (q < 0) {
            puts("Т.к. q < 0 => x1 и x2 различны по знаку");
            if (p < 0)
                puts("Т.к. p < 0 => больший по модулю корень будет "
                     "положительный");
            else if (p > 0)
                puts("Т.к. p > 0 => больший по модулю корень будет "
                     "отрицательный");
        }
        printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);

    } else if (d == 0) {
        double x0 = X0(1, p);

        printf("x^2 + (%.1lf)x + (%.1lf), D = 0\n", p, q);
        if (q > 0) {
            puts("Т.к. q > 0 => x1 и x2 одинаковы по знаку");
            if (p < 0)
                puts("Т.к. p < 0 => x1 и x2 - положительны");
            else if (p > 0)
                puts("Т.к. p > 0 => x1 и x2 - отрицательны");
        }
        printf("==> x1 = x2 = %.1lf\n", x0);

    } else if (d < 0)
        puts("У данного уравнения нет корней!");
}

// Решение способом "переброски"
void f5() {}

// Свойства коэффициентов квадратного уравнения
void f6() {}

// Графическое решение
void f7() {}

// Решение с помощью циркуля и линейки
void f8() {}

// Решение с помощью номограммы
void f9() {}

// Решение геометрическим способом
void f10() {}
