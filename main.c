#include <locale.h>
#include "my_func.h"

int main() {
    setlocale(LC_ALL, "");

    int n;

    puts("Введите номер способа решения (1..10):");
    scanf("%d", &n);

    void (*arr[10])() = {
        f1, f2, f3, f4, f5,
        f6, f7, f8, f9, f10
    };

    arr[n - 1]();

    return 0;
}
