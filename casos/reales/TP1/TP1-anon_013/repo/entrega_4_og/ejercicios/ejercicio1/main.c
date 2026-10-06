

#include <stdio.h>
#include "ejercicio1.h"

int main(void) {
    int num = 17;
    printf("=== Ejercicio 1: Numeros Primos y Divisores ===\n");
    printf("Numero de prueba: %d\n", num);
    printf("Es primo: %s\n", es_primo(num) ? "SI" : "NO");
    printf("Proximo primo: %d\n", proximo_primo(num));
    printf("Cantidad de divisores: %d\n", cantidad_divisores(num));
    return 0;
}
