/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include "cadena_dinamica.h"
#include <stdio.h>

int main(void)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
    //______________________________________________________________________________________________________________

    printf("\n===== clonar_cadena =====\n");

    char cadena_origen[] = "Esta cadena va a ser clonada";

    printf("CADENA ORIGEN: %s\n", cadena_origen);

    char *ptr_heap = clonar_cadena(cadena_origen);

    if (ptr_heap != NULL)
    {
        printf("CADENA HEAP: %s\n", ptr_heap);
        cadena_liberar_segura(&ptr_heap);
        printf("PUNTERO AL HEAP LIBERADO CON cadena_liberar_segura()\n");
    }
    else
    {
        printf("EL PUNTERO AL HEAP ES NULL, algo malio sal\n");
    }

    //______________________________________________________________________________________________________________

    printf("\n===== unir_cadenas_dinamicas =====\n");

    char primera[] = "Primer texto - ";
    char segunda[] = "Segundo texto";

    printf("PRIMERA CADENA: %s\n", primera);
    printf("SEGUNDA CADENA: %s\n", segunda);

    ptr_heap = unir_cadenas_dinamicas(primera, segunda);

    if (ptr_heap != NULL)
    {
        printf("CADENA HEAP CONCATENADA: %s\n", ptr_heap);
        cadena_liberar_segura(&ptr_heap);
        printf("PUNTERO AL HEAP LIBERADO CON cadena_liberar_segura()\n");
    }
    else
    {
        printf("EL PUNTERO AL HEAP ES NULL, algo malio sal\n");
    }

    return 0;
}
