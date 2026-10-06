/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"
#include <string.h>

static void quitar_salto_linea(char *cadena)
{
    cadena[strcspn(cadena, "\n")] = '\0';
}


int main(void)
{
    printf("Ejercicio 3: Cadenas Dinamicas en Heap\n");

    char buffer1[256];
    char buffer2[256];

    printf("Ingrese la cadena a clonar: ");
    fgets(buffer1, sizeof(buffer1), stdin);

    char *clon = clonar_cadena(buffer1);

    if (clon != NULL)
    {
        printf("[Heap] Clon creado con exito: %s\n", clon);
        free(clon);
    }
    
    else
    {
        printf("Error al asignar memoria en el Heap.\n");
        return 0;
    }
    

    printf("Ingrese la primera cadena: ");
    fgets(buffer1, sizeof(buffer1), stdin);
    quitar_salto_linea(buffer1);
    printf("Ingrese la segunda cadena: ");
    fgets(buffer2, sizeof(buffer2), stdin);

    char *resultado = unir_cadenas_dinamicas(buffer1, buffer2);

    if (resultado != NULL)
    {
        printf("[Heap] Cadena unida: %s", resultado);
        free(resultado);
        return 0;
    }
    
    else
    {
        printf("Error al asignar memoria en el Heap.\n");
        return 0;
    }
}