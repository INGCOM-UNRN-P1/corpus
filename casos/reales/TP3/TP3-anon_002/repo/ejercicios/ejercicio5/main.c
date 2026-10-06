/**
 * @file main.c
 * @brief Programa demostrativo del Ejercicio 5.
 *
 * Programación 1 - Ingeniería en Computación - UNRN
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    char destino[30] = "";
    const char origen[] = "Hola";
    const char adicional[] = " mundo";

    printf("Ejercicio 5: Cadenas seguras con punteros\n");

    if (copiar_con_punteros(destino, sizeof(destino), origen))
    {
        printf("Copia: %s\n", destino);
    }
    else
    {
        printf("La copia fue truncada.\n");
    }

    if (concatenar_con_punteros(destino, sizeof(destino), adicional))
    {
        printf("Concatenacion: %s\n", destino);
    }
    else
    {
        printf("La concatenacion fue truncada.\n");
    }

    printf("Longitud: %zu\n",
           longitud_con_punteros(destino, sizeof(destino)));

    return 0;
}
