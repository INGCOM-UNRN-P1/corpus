

#include <stdio.h>
#include <assert.h>
#include "ejercicio3.h"

int main(void) {
    printf("Ejecutando pruebas de Ejercicio 3...\n");

    // Pruebas factorial
    assert(factorial(-2) == -1);
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
    assert(factorial(6) == 720);

    // Pruebas combinatorio
    assert(combinatorio(5, -1) == -1);
    assert(combinatorio(5, 6) == -1);
    assert(combinatorio(5, 0) == 1);
    assert(combinatorio(5, 5) == 1);
    assert(combinatorio(5, 2) == 10);
    assert(combinatorio(6, 3) == 20);

    printf("Todas las pruebas del Ejercicio 3 pasaron con exito.\n");
    return 0;
}
