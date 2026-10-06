/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");

    char buffer[20];
    const char *origen_copia = "Hola, ";
    const char *origen_concat = "mundo!";

    if (copiar_con_punteros(buffer, sizeof(buffer), origen_copia))
    {
        printf("Copia: %s\n", buffer);
    }

    if (concatenar_con_punteros(buffer, sizeof(buffer), origen_concat))
    {
        printf("Concatenacion: %s\n", buffer);
    }

    char buffer_pequeno[10];
    if (!copiar_con_punteros(buffer_pequeno, sizeof(buffer_pequeno), "Texto muy largo"))
    {
        printf("Truncamiento exitoso: %s\n", buffer_pequeno);
    }

    return 0;
}