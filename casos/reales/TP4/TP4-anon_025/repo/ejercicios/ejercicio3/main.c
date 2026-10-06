/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "cadena_dinamica.h"
#include <stdlib.h>

int main(void)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
    
    printf("============================================\n\n");
    const char *texto_original = "Programacion 1";
    char *texto_clonado = clonar_cadena(texto_original);

    if (texto_clonado != NULL)
    {
        printf("[Clonacion]\n");
        printf("Texto original : %s\n", texto_original);
        printf("Texto clonado : %s\n", texto_clonado);
        free(texto_clonado);
        texto_clonado = NULL;
    }

    printf("\n--------------------------------------------------\n\n");

    const char *mitad1 = "Hola, ";
    const char *mitad2 = "mundo dinamico!";
    char *texto_unido = unir_cadenas_dinamicas(mitad1, mitad2);

    if (texto_unido != NULL)
    {
        printf("[Concatenacion]\n");
        printf("Primera parte : %s\n", mitad1);
        printf("Segunda parte : %s\n", mitad2);
        printf("Resultado     : %s\n", texto_unido);
        free(texto_unido);
        texto_unido = NULL;
    }
    printf("\n============================================\n");
    return 0;
}
