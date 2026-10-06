

#include <stdio.h>
#include "ejercicio8.h"

int main(void) {
    int num = 6;
    printf("=== Ejercicio 8: Clasificacion de Numeros ===\n");
    printf("Numero: %d\n", num);
    printf("Suma de divisores propios: %d\n", suma_divisores_propios(num));
    int clase = clasificar_numero(num);
    printf("Clasificacion: %s\n", (clase == 1) ? "Perfecto" : (clase == 0 ? "Deficiente" : "Abundante"));
    return 0;
}
