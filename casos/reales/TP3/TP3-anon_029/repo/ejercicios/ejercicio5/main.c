/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");
    const char *origen = "mundo";
    char destino[10];
    if (copiar_con_punteros(destino, sizeof(destino), origen))
    {
        printf("Copia exitosa: %s\n", destino);
    }
    else
    {
        printf("Error al copiar. Cadena resultante: %s\n", destino);
    }

    char destino_2[20] = "Hola ";
     if (concatenar_con_punteros(destino_2, sizeof(destino_2), origen))
    {
        printf("Concatenacion exitosa: %s\n", destino_2);
    }
    else
    {
        printf("Error al concatenar. Cadena resultante: %s\n", destino_2);
    }
    return 0;
}
