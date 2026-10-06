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
    const char *saludo = "Hola";
    const char *complemento = " Mundo!";

    if (copiar_con_punteros(buffer, sizeof(buffer), saludo)) {
        printf("Copia exitosa: \"%s\"\n", buffer);
    }

    if (concatenar_con_punteros(buffer, sizeof(buffer), complemento)) {
        printf("Concatenacion exitosa: \"%s\"\n", buffer);
    }

    return 0;
}
