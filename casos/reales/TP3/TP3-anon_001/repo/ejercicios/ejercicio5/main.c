/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void) {
    char dest[20];

    copiar_con_punteros(dest, sizeof(dest), "Hola ");
    concatenar_con_punteros(dest, sizeof(dest), "Mundo!");

    printf("%s\n", dest);

    return 0;
}