/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include "cadena_dinamica.h"
#include <stdio.h>

void pruebas_ejercicio_3()
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
    printf("Clonacion de la cadena");
    const char *origen = "Hola";
    char *clon = clonar_cadena(origen);
    if (clon != NULL)
    {
        printf("Clon de la cadena origen: %s\n", clon);
        free(clon);
        clon = NULL;
    }
    else
    {
        printf("Error: Fallo en la asignacion de memoria");
    }

    printf("Union de cadenas");
    const char *primero = "Hola";
    const char *segundo = " mundo";
    char *unidos = unir_cadenas_dinamicas(primero, segundo);
    if (unidos != NULL)
    {
        printf("Union de las cadenas: %s\n", unidos);
        free(unidos);
        unidos = NULL;
    }
    else
    {
        printf("Error: Fallo en la asignacion de memoria");
    }
}
int main(void)
{
    pruebas_ejercicio_3();
    return 0;
}
