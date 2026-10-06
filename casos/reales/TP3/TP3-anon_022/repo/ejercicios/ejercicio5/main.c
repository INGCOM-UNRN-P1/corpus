/**
 * @file main.c
 * @brief Programa demostrativo del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    char buffer[16];

    printf("Ejercicio 5: Cadenas seguras con punteros\n\n");

    bool copia_ok = copiar_con_punteros(buffer, sizeof(buffer),
                                         "Hola");

    printf("copiar_con_punteros(\"Hola\") -> \"%s\" "
           "(completa: %s)\n",
           buffer, copia_ok ? "true" : "false");

    bool concat_ok = concatenar_con_punteros(buffer, sizeof(buffer),
                                              ", mundo!");

    printf("concatenar_con_punteros(\", mundo!\") -> \"%s\" "
           "(completa: %s)\n",
           buffer, concat_ok ? "true" : "false");

    size_t longitud = longitud_con_punteros(buffer, sizeof(buffer));

    printf("longitud_con_punteros -> %zu\n\n", longitud);

    char chico[6];

    bool trunco = copiar_con_punteros(chico, sizeof(chico),
                                       "Este texto no entra");

    printf("copiar_con_punteros truncado -> \"%s\" "
           "(completa: %s)\n",
           chico, trunco ? "true" : "false");

    return 0;
}