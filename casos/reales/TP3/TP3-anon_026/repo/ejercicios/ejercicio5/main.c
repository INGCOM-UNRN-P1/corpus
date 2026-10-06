/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");
    
    const char *texto = "programacion";
    printf("longitud_con_punteros(\"%s\", 20) = %zu\n", texto, longitud_con_punteros(texto, 20));
    printf("longitud_con_punteros(\"%s\", 5) = %zu\n", texto, longitud_con_punteros(texto, 5));

    charr amplio[32];
    if (copiar_con_punteros(amplio, sizeof(amplio), "hola"))
    {
        printf("copiar (cabe): \"%s\"\n"), amplio);
    }
    if (concatenar_con_punteros(amplio, sizeof(amplio), " mundo"))
    {
        printf("concatenar (cabe): \"%s\"\n", camplio);
    }

    char corto[6];
    if(!copiar_con_punteros(corto, sizeof(corto), "Universidad"))
    {
        printf("copiar (trunca): \"%s\"\n", corto);
    }

    char medio[8];
    copiar_con_punteros(medio, sizeof(medio), "hola");
    if (!concatenar_con_punteros(medio, sizeof(medio), " mundo"))
    {
        printf("concatenar (trunca): \"%s\"\n", medio);
    }

    return 0;
}
