/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    char copia[30];
    char texto[30] = "Hola";

    printf("Ejercicio 5: Cadenas seguras con punteros\n");

    if (copiar_con_punteros(copia, 30, "Programacion"))
    {
        printf("Cadena copiada: %s\n", copia);
    }

    if (concatenar_con_punteros(texto, 30, " mundo"))
    {
        printf("Cadena concatenada: %s\n", texto);
    }

    printf("Longitud de la cadena: %zu\n",
           longitud_con_punteros(texto, 30));

    return 0;
}