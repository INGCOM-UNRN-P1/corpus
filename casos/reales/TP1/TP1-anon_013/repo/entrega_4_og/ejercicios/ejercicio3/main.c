

#include <stdio.h>
#include "ejercicio3.h"

int main(void) {
    int n = 5, k = 2;
    printf("=== Ejercicio 3: Factorial y Combinatoria ===\n");
    printf("%d! = %lld\n", n, factorial(n));
    printf("C(%d, %d) = %lld\n", n, k, combinatorio(n, k));
    return 0;
}
