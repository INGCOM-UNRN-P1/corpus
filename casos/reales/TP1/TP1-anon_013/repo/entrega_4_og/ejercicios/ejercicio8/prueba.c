

#include <stdio.h>
#include <assert.h>
#include "ejercicio8.h"

int main(void) {
    printf("Ejecutando pruebas de Ejercicio 8...\n");

    // Pruebas suma_divisores_propios
    assert(suma_divisores_propios(0) == -1);
    assert(suma_divisores_propios(-6) == -1);
    assert(suma_divisores_propios(1) == 0);
    assert(suma_divisores_propios(6) == 6); // 1 + 2 + 3
    assert(suma_divisores_propios(12) == 16); // 1 + 2 + 3 + 4 + 6

    // Pruebas clasificar_numero (1: perfecto, 0: deficiente, 2: abundante)
    assert(clasificar_numero(0) == -1);
    assert(clasificar_numero(6) == 1);  // 6 = 1+2+3 (perfecto)
    assert(clasificar_numero(28) == 1); // 28 = 1+2+4+7+14 (perfecto)
    assert(clasificar_numero(8) == 0);  // 1+2+4 = 7 < 8 (deficiente)
    assert(clasificar_numero(12) == 2); // 16 > 12 (abundante)

    printf("Todas las pruebas del Ejercicio 8 pasaron con exito.\n");
    return 0;
}
