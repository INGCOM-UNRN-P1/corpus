/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include "cadenas.h"
#include "texto_dinamico.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM_BUFFER 256

//funcion auxiliar para finalizar la cadena y limpiar el salto de linea
void quitar_salto(char *cadena) 
{
    int i = 0;
    while (cadena[i] != '\0' && cadena[i] != '\n') {
        i++;
    }
    cadena[i] = '\0';
}

int main(void)
{   
    char buffer[TAM_BUFFER];

    // 1. Prueba de cadena_recortar_espacios 
    printf("=== PRUEBA: Recortar espacios ===\n");
    printf("Ingresa una cadena (con espacios al inicio o al final): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        quitar_salto(buffer); 

        char *recortada = cadena_recortar_espacios(buffer);
        if (recortada != NULL) {
            printf("Resultado: \"%s\"\n\n", recortada);
            free(recortada);
        } else {
            printf("Resultado: NULL (cadena vacia o llena de espacios)\n\n");
        }
    }

    // 2 Prueba  de cadena_repetir 
    printf("=== PRUEBA: Repetir cadena ===\n");
    printf("Ingresa el texto a repetir: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        quitar_salto(buffer); 

        size_t veces = 0;
        printf("Ingresa la cantidad de repeticiones: ");
        if (scanf("%zu", &veces) == 1) {
            char *repetida = cadena_repetir(buffer, veces);
            if (repetida != NULL) {
                printf("Resultado: \"%s\"\n", repetida);
                free(repetida);
            } else {
                printf("Error al generar la cadena repetida.\n");
            }
        }
    }

    return 0;
}
