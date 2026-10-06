/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadena_dinamica.h"
 
int main(void)
{
    int estado = 0;
 
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
 
    char texto1[100];
    char texto2[100];
 
    printf("Ingrese la primera cadena: ");
    if (fgets(texto1, sizeof(texto1), stdin) == NULL) {
        printf("Error de lectura\n");
        estado = 1;
    } else {
        texto1[strcspn(texto1, "\n")] = '\0';
 
        printf("Ingrese la segunda cadena: ");
        if (fgets(texto2, sizeof(texto2), stdin) == NULL) {
            printf("Error de lectura\n");
            estado = 1;
        } else {
            texto2[strcspn(texto2, "\n")] = '\0';
 
            char *clon = clonar_cadena(texto1);
            char *unida = unir_cadenas_dinamicas(texto1, texto2);
            if (clon == NULL || unida == NULL) {
                printf("Error: no hay memoria suficiente\n");
                estado = 1;
            } else {
                printf("Clon de la primera: [%s]\n", clon);
                printf("Cadenas unidas: [%s]\n", unida);
            }
 
            free(unida);
            free(clon);
        }
    }
    return estado;
}
