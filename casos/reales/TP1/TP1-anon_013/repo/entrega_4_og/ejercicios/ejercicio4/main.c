

#include <stdio.h>
#include "ejercicio4.h"

int main(void) {
    int a = 24, b = 36;
    printf("=== Ejercicio 4: MCD y MCM ===\n");
    printf("a = %d, b = %d\n", a, b);
    printf("MCD(%d, %d) = %d\n", a, b, maximo_comun_divisor(a, b));
    printf("MCM(%d, %d) = %d\n", a, b, minimo_comun_multiplo(a, b));
    return 0;
}
