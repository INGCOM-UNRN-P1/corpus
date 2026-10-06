

#include <stdio.h>
#include <assert.h>
#include "ejercicio2.h"

int main(void) {
    printf("Ejecutando pruebas de Ejercicio 2...\n");

    // Pruebas fibonacci
    assert(fibonacci(-1) == -1);
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(3) == 2);
    assert(fibonacci(4) == 3);
    assert(fibonacci(5) == 5);
    assert(fibonacci(6) == 8);
    assert(fibonacci(7) == 13);

    // Pruebas suma_fibonacci
    assert(suma_fibonacci(-1) == -1);
    assert(suma_fibonacci(0) == 0);
    assert(suma_fibonacci(1) == 1); // 0 + 1
    assert(suma_fibonacci(4) == 7); // 0 + 1 + 1 + 2 + 3

    printf("Todas las pruebas del Ejercicio 2 pasaron con exito.\n");
    return 0;
}
