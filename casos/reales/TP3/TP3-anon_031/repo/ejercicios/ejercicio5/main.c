/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    char destino[20] = "";
    const char *primera = "Hola";
    const char *segunda = " mundo";

    printf("Ejercicio 5: Cadenas seguras con punteros\n");

    if (copiar_con_punteros(destino, sizeof(destino), primera))
    {
        printf("Copia: %s\n", destino);
    }
    else
    {
        printf("La copia fue truncada o invalida.\n");
    }

    if (concatenar_con_punteros(destino, sizeof(destino), segunda))
    {
        printf("Concatenacion: %s\n", destino);
    }
    else
    {
        printf("La concatenacion fue truncada o invalida.\n");
    }

    printf("Longitud: %zu\n", longitud_con_punteros(destino, sizeof(destino)));

    return 0;
}
