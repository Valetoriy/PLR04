#include "helper.h"
#include "graphics.h"

// Разложение на множители
void f1() {
    double a, b, c;

    puts("Способ - разложение на множители");
    puts("Уравнение вида ax^2 + bx + c = 0, (a, b, c) - int или double");
    puts("Ограничения: a != 0");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = D(a, b, c);
    printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf) = 0", a, b, c);

    if (d >= 0) {
        double x1 = X1(a, b, d);
        double x2 = X2(a, b, d);

        if (d > 0) {
            printf(" <=> (%.1lf)(x - (%.1lf))(x - (%.1lf)) = 0\n", a, x1, x2);
            printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
        } else {
            printf(" <=> (%.1lf)(x - (%.1lf))^2\n", a, x1);
            printf("==> x1 = x2 = %.1lf\n", x1);
        }

    } else if (d < 0)
        puts("\nДанное уравнение нельзя разложить по множетелям!");
}

// Выделение полного квадрата
void f2() {
    double b, c;

    puts("Способ - выделение полного квадрата");
    puts("Уравнение вида x^2 + bx + c = 0, (b, c) - int или double");
    puts("Ограничения: b - чётное число");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf", &b, &c);

    double temp = b / 2;
    double temp2 = c - temp * temp;
    printf("x^2 + (%.1lf)x + (%.1lf) = 0", b, c);

    if (temp2 > 0)
        puts("\nВ данном уравнении нельзя выделить полный квадрат!");

    else if (temp2 == 0) {
        printf(" <=> (x + (%.1lf))^2 = 0\n", temp);
        printf("==> x1 = x2 = %.1lf\n", -temp);

    } else if (temp2 < 0) {
        printf(" <=> (x + (%.1lf))^2 + (%.1lf) = 0\n", temp, temp2);
        printf("==> x1 = %.1lf, x2 = %.1lf\n", sqrt(-temp2) - temp,
               -sqrt(-temp2) - temp);
    }
}

// Решение по формуле
void f3() {
    double a, b, c;

    puts("Способ - решение по формуле");
    puts("Уравнение вида ax^2 + bx + c = 0, (a, b, c) - int или double");
    puts("Ограничения: a != 0");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = D(a, b, c);
    printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf) = 0", a, b, c);

    if (d >= 0) {
        double x1 = X1(a, b, d);
        double x2 = X2(a, b, d);

        if (d > 0) {
            printf(", D = (%.1lf)\n", d);
            printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
        } else {
            puts(", D = 0");
            printf("==> x1 = x2 = %.1lf\n", x1);
        }

    } else if (d < 0)
        puts("\nУ данного уравнения нет корней!");
}

// Решение с использованием теоремы Виета
void f4() {
    double p, q;

    puts("Способ - решение с использованием теоремы Виета");
    puts("Уравнение вида x^2 + px + q = 0, (p, q) - int или double");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf", &p, &q);

    double d = D(1, p, q);
    printf("x^2 + (%.1lf)x + (%.1lf) = 0\n", p, q);

    if (d >= 0) {
        double x1 = X1(1, p, d);
        double x2 = X2(1, p, d);

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
        if (d > 0)
            printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
        else
            printf("==> x1 = x2 = %.1lf\n", x1);

    } else if (d < 0)
        puts("У данного уравнения нет корней!");
}

// Решение способом "переброски"
void f5() {
    double a, b, c;

    puts("Способ - решение \"переброской\"");
    puts("Уравнение вида ax^2 + bx + c = 0, (a, b, c) - int или double");
    puts("Ограничения: a != 0, D - точный квадрат");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = D(a, b, c);

    printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf) = 0\n"
           "<=> (%.1lf)^2 * x^2 + "
           "(%.1lf)(%.1lf)x + (%.1lf)(%.1lf) = 0\n",
           a, b, c, a, a, b, a, c);
    printf("Пусть (%.1lf)x = y, x = y / (%.1lf); =>\n", a, a);
    printf("y^2 + (%.1lf)y + (%.1lf)(%.1lf) = 0\n", b, a, c);

    double x1 = X1(a, b, d);
    double x2 = X2(a, b, d);

    if (d > 0)
        printf("==> x1 = y1 / (%.1lf) = %.1lf, x2 = y2 / (%.1lf) = %.1lf\n", a,
               x1, a, x2);
    else
        printf("==> x1 = x2 = (y1 = y2) / (%.1lf) = %.1lf\n", a, x1);
}

// Свойства коэффициентов квадратного уравнения
void f6() {
    double a, b, c;

    puts("Способ - свойства коэффициентов квадратного уравнения");
    puts("Уравнение вида ax^2 + bx + c = 0, (a, b, c) - int или double");
    puts("Ограничения: a != 0");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = D(a, b, c);
    printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf) = 0\n", a, b, c);

    if (d >= 0) {
        double x1 = X1(a, b, d);
        double x2 = X2(a, b, d);

        if (a + b + c == 0) {
            puts("Сумма коэффициентов равна нулю");
            printf("==> x1 = 1, x2 = (%.1lf) / (%.1lf) = %.1lf\n", c, a, c / a);

        } else if (a == 1) {
            puts("Данное уравнение совпадает с уравнением общего вида(a = 1, b "
                 "= p, c = q)");
            printf("Формулу корней можно записать в виде:\n"
                   "x1,2 = (-(%.1lf) +- sqrt((%.1lf)^2 - 4(%.1lf))) / 2, или\n"
                   "x1,2 = -(%.1lf) / 2 +- sqrt(((%.1lf) / 2)^2 - (%.1lf))\n",
                   b, b, c, b, b, c);
            if (d > 0)
                printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
            else
                printf("==> x1 = x2 = %.1lf\n", x1);

        } else if ((int)b % 2 == 0) {
            double k = b / 2;
            puts("Второй коэффициент - чётное число");
            printf("(%.1lf) / 2 = %.1lf\n", b, k);
            printf("Формулу корней можно записать в виде:\n"
                   "x1,2 = (-(%.1lf) +- sqrt((%.1lf)^2 - (%.1lf)(%.1lf))) / "
                   "(%.1lf)\n",
                   k, k, a, c, a);
            if (d > 0)
                printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
            else
                printf("==> x1 = x2 = %.1lf\n", x1);
        }

    } else if (d < 0)
        puts("У данного уравнения нет корней!");
}

// Графическое решение
void f7() {
    double p, q;

    puts("Способ - графическое решение");
    puts("Уравнение вида x^2 + px + q = 0, (p, q) - int или double");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf", &p, &q);

    double d = D(1, p, q);
    printf("x^2 + (%.1lf)x + (%.1lf) = 0\n", p, q);
    f7graphics(-p, -q);
    printf("Функции x^2 и -(%.1lf)x - (%.1lf) ", p, q);

    if (d >= 0) {
        double x1 = X1(1, p, d);
        double x2 = X2(1, p, d);

        if (d > 0) {
            puts("пересекаются в двух точках");
            printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
        } else {
            puts("пересекаются в одной точке");
            printf("==> x1 = x2 = %.1lf\n", x1);
        }

    } else if (d < 0)
        puts("не пересекаются\nУ данного уравнения нет корней!");
}

// Решение с помощью циркуля и линейки
void f8() {
    double a, b, c;

    puts("Способ - решение с помощью циркуля и линейки");
    puts("Уравнение вида ax^2 + bx + c = 0, (a, b, c) - int или double");
    puts("Ограничения: a != 0");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = D(a, b, c);
    printf("(%.1lf)x^2 + (%.1lf)x + (%.1lf) = 0\n", a, b, c);
    puts("P.S. - повторный вывод символов(XX, SS и т.д.) может означать,\n"
         "что координата точки не делится на 0.2 без остатка");
    f8graphics(a, b, c, d);
    printf("Радиус окружности ");

    if (d >= 0) {
        double x1 = X1(a, b, d);
        double x2 = X2(a, b, d);

        if (d > 0) {
            puts("больше ординаты центра");
            printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
        } else {
            puts("равен ординате центра");
            printf("==> x1 = x2 = %.1lf\n", x1);
        }

    } else if (d < 0)
        puts("меньше ординаты центра\nУ данного уравнения нет корней!");
}

// Решение с помощью номограммы
void f9() {
    double p, q;

    puts("Способ - решение с помощью номограммы");
    puts("Уравнение вида x^2 + px + q = 0, (p, q) - int или double");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf", &p, &q);

    double d = D(1, p, q);
    printf("x^2 + (%.1lf)x + (%.1lf) = 0\n", p, q);
    printf("Проведём через точки p = (%.1lf) и q = (%.1lf) прямую:\n", p, q);
    puts("P.S. - повторный вывод символов(11, ▇▇ и т.д.) может означать,\n"
         "что координата точки не делится на 0.2 без остатка");
    f9graphics(p, q);

    if (d >= 0) {
        double x1 = X1(1, p, d);
        double x2 = X2(1, p, d);

        if (d > 0)
            printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
        else
            printf("==> x1 = x2 = %.1lf\n", x1);

    } else if (d < 0)
        puts("У данного уравнения нет корней!");
}

// Решение геометрическим способом
void f10() {
    double b, c;

    puts("Способ - решение с помощью геометрических построений");
    puts("Уравнение вида x^2 + bx = c, (b, c) - int или double");
    puts("Введите коэффициенты уравнения:");
    scanf("%lf%lf", &b, &c);

    double d = D(1, b, -c);
    printf("x^2 + (%.1lf)x = (%.1lf)\n", b, c);
    puts("Представим уравнение в геометрическом виде:");
    f10graphics(b, -c);

    if (d >= 0) {
        double x1 = X1(1, b, d);
        double x2 = X2(1, b, d);

        if (d > 0)
            printf("==> x1 = %.1lf, x2 = %.1lf\n", x1, x2);
        else
            printf("==> x1 = x2 = %.1lf\n", x1);

    } else if (d < 0)
        puts("У данного уравнения нет корней!");
}
