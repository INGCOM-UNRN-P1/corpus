

#include <stdio.h>
#include <assert.h>
#include "ejercicio1.h"

int main(void) {
    printf("Ejecutando pruebas de Ejercicio 1...\n");

    // Pruebas es_primo
    assert(es_primo(-5) == 0);
    assert(es_primo(0) == 0);
    assert(es_primo(1) == 0);
    assert(es_primo(2) == 1);
    assert(es_primo(3) == 1);
    assert(es_primo(4) == 0);
    assert(es_primo(17) == 1);
    assert(es_primo(25) == 0);

    // Pruebas proximo_primo
    assert(proximo_primo(0) == 2);
    assert(proximo_primo(1) == 2);
    assert(proximo_primo(2) == 3);
    assert(proximo_primo(14) == 17);
    assert(proximo_primo(17) == 19);

    // Pruebas cantidad_divisores
    assert(cantidad_divisores(0) == 0);
    assert(cantidad_divisores(1) == 1);
    assert(cantidad_divisores(6) == 4); // 1, 2, 3, 6
    assert(cantidad_divisores(17) == 2); // 1, 17

    printf("Todas las pruebas del Ejercicio 1 pasaron con exito.\n");
    return 0;
}
