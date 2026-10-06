/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "cadena_dinamica.h"
 #include "cadenas.h"

int main(void)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");

    char primera[64];
    char segunda[64];
 
    printf("Primera palabra: ");
    int leidos = scanf("%63s", primera);
    printf("Segunda palabra: ");
    leidos += scanf("%63s", segunda);
 
    if (leidos == 2)
    {
        char *clon = clonar_cadena(primera);
        char *unida = unir_cadenas_dinamicas(primera, segunda);
 
        if (clon != NULL && unida != NULL)
        {
            printf("Clon de la primera: %s\n", clon);
            printf("Union de las dos: %s\n", unida);
        }
        else
        {
            printf("No hay memoria disponible.\n");
        }
 
        cadena_liberar_segura(&clon);
        cadena_liberar_segura(&unida);
    }
    else
    {
        printf("Entrada invalida.\n");
    }
 
    return 0;

}
