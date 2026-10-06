/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");

    char destino[20];

    if (copiar_con_punteros(destino, sizeof(destino), "Hola")){
        printf("Copia: %s\n", destino);
    } else {
        printf("trunco.\n");
    }

    if (concatenar_con_punteros(destino, sizeof(destino), " mundo")){
        printf("Concatenacion: %s\n", destino);
    } else {
        printf("trunco.\n");
    }

    return 0;
}