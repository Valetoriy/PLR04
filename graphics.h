#include <math.h>  // temp
#include <stdio.h> // temp

void f7graphics(double p, double q) {
    // 81x81 array, arr[y][x] = real[(x - 40) * 0.2][(y - 40) * (-0.2)]
    // arr tile = 0.2
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

void f8graphics(double a, double b, double c) {}
void f9graphics(double p, double q) {}
void f10graphics(double a, double b, double c) {}
