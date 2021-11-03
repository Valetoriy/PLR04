// 81x81 array, arr[y][x] = real[(x - 40) * 0.2][(y - 40) * (-0.2)]
// arr tile = 0.2
void f7graphics(double p, double q) {
    for (int y = 0; y < 81; y++) {
        for (int x = 0; x < 81; x++) {
            // translation
            double rx = ((double)x - 40) * 0.2;
            double ry = ((double)y - 40) * -0.2;

            int cross = 0;
            for (double dx = rx - 0.1; dx <= rx + 0.1; dx += 0.001)
                if ((dx * dx >= ry - 0.005 && dx * dx <= ry + 0.005) &&
                    (p * dx + q >= ry - 0.005 && p * dx + q <= ry + 0.005)) {
                    cross = 2;
                    break;
                } else if ((dx * dx >= ry - 0.005 && dx * dx <= ry + 0.005) ||
                           (p * dx + q >= ry - 0.005 &&
                            p * dx + q <= ry + 0.005))
                    cross = 1;

            if (cross == 2)
                printf("X");
            else if (cross == 1)
                printf("▇");
            else if (rx == 0) {
                if ((int)(ry * 10) % 10 == 0)
                    printf("%d", abs((int)ry));
                else
                    printf("|");
            } else if (ry == 0) {
                if ((int)(rx * 10) % 10 == 0)
                    printf("%d", abs((int)rx));
                else
                    printf("-");
            } else
                printf(".");
        }
        puts("");
    }
}

void f8graphics(double a, double b, double c, double d) {
    double ox = -b / (2 * a);
    double oy = (a + c) / (2 * a);
    double R = sqrt((oy - 1) * (oy - 1) + ox * ox);

    // double cheking
    double x1 = X1(a, b, d);
    double x2 = X2(a, b, d);

    for (int y = 0; y < 81; y++) {
        for (int x = 0; x < 81; x++) {

            double rx = ((double)x - 40) * 0.2;
            double ry = ((double)y - 40) * -0.2;

            int cross = 0;

            for (double dx = rx - 0.1; dx <= rx + 0.1; dx += 0.001)
                if ((dx - ox) * (dx - ox) + (ry - oy) * (ry - oy) >=
                        R * R - 0.1 &&
                    (dx - ox) * (dx - ox) + (ry - oy) * (ry - oy) <=
                        R * R + 0.1) {
                    if (ry == 0 && ((dx >= x1 - 0.01 && dx <= x1 + 0.01) ||
                                    (dx >= x2 - 0.01 && dx <= x2 + 0.01))) {
                        cross = 2;
                        break;
                    } else
                        cross = 1;
                }

            if (cross == 2)
                printf("X");
            else if (rx >= ox - 0.1 && rx <= ox + 0.1 && ry >= oy - 0.1 &&
                     ry <= oy + 0.1)
                printf("S");
            else if (rx == 0 && ry == 1.0)
                printf("A");
            else if (cross == 1)
                printf("▇");
            else if (rx == 0) {
                if ((int)(ry * 10) % 10 == 0)
                    printf("%d", abs((int)ry));
                else
                    printf("|");
            } else if (ry == 0) {
                if ((int)(rx * 10) % 10 == 0)
                    printf("%d", abs((int)rx));
                else
                    printf("-");
            } else
                printf(".");
        }
        puts("");
    }
}

void f9graphics(double p, double q) {
    for (int y = 0; y < 81; y++) {
        for (int x = 0; x < 81; x++) {

            double rx = ((double)x) * 0.1;
            double ry = ((double)y - 40) * -0.2;

            int cross = 0;
            int count = 0;
            for (double dx = rx - 0.05; dx <= rx + 0.05; dx += 0.001) {
                double z = (8.0 - dx) / dx;
                if (-(z * z) / (1 + z) >= ry - 0.1 &&
                    -(z * z) / (1 + z) <= ry + 0.1) {
                    if (z >= round(z) - 0.002 && z <= round(z) + 0.002)
                        count = round(z);
                    cross = 1;
                } else if ((dx * (q - p)) / 8 + p >= ry - 0.1 &&
                           (dx * (q - p)) / 8 + p <= ry + 0.1)
                    cross = 1;
            }

            if (count)
                printf("%d", count);
            else if (cross == 1)
                printf("▇");
            else if (rx == 0 || rx == 8) {
                if ((int)(ry * 10) % 10 == 0)
                    printf("%d", abs((int)ry));
                else
                    printf("|");
            } else
                printf(".");
        }
        puts("");
    }
}

void f10graphics(double b, double c) {
    printf("┌---------┬-----┐       ┌---------------┐\n"
           "|         |     |       |               |\n"
           "|         |     |       |               |\n"
           "|  x * x  |  A  |       |               |\n"
           "|         |     |   =   |       C       |\n"
           "|         |     |       |               |\n"
           "├---------┼-----┤       |               |\n"
           "|    A    |  B  |       |               |\n"
           "└---------┴-----┘       └---------------┘\n");
    printf("A = %.1lf * x, B = %.1lf, C = %.1lf\n", b / 2, (b * b) / 4,
           ((b * b) - 4 * c) / 4);
}
