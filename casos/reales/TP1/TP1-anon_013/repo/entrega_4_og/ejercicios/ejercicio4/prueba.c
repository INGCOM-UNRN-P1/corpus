

#include <stdio.h>
#include <assert.h>
#include "ejercicio4.h"

int main(void) {
    printf("Ejecutando pruebas de Ejercicio 4...\n");

    // Pruebas MCD
    assert(maximo_comun_divisor(0, 0) == -1);
    assert(maximo_comun_divisor(24, 36) == 12);
    assert(maximo_comun_divisor(7, 13) == 1);
    assert(maximo_comun_divisor(-24, 36) == 12);
    assert(maximo_comun_divisor(0, 5) == 5);

    // Pruebas MCM
    assert(minimo_comun_multiplo(0, 5) == -1);
    assert(minimo_comun_multiplo(-4, 6) == -1);
    assert(minimo_comun_multiplo(4, 6) == 12);
    assert(minimo_comun_multiplo(24, 36) == 72);
    assert(minimo_comun_multiplo(7, 13) == 91);

    printf("Todas las pruebas del Ejercicio 4 pasaron con exito.\n");
    return 0;
}
