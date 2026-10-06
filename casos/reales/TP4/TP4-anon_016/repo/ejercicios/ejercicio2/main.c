/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "cadenas.h"
#include "texto_dinamico.h"

int main(void)
{

    
    printf("Ejercicio 2: Normalización Dinámica de Texto en Heap\n");
    char linea[256];
 
    printf("Escriba un texto (puede tener espacios al inicio y al final): ");
    char *lectura = fgets(linea, sizeof(linea), stdin);
 
    if (lectura != NULL)
    {
        size_t posicion = 0;
        while (linea[posicion] != '\0' && linea[posicion] != '\n')
        {
            posicion++;
        }
        linea[posicion] = '\0';
 
        int veces_leidas = 0;
        printf("Cantidad de repeticiones (0 o mas): ");
        int leidos = scanf("%d", &veces_leidas);
 
        if (leidos == 1 && veces_leidas >= 0)
        {
            char *recortada = cadena_recortar_espacios(linea);
            if (recortada != NULL)
            {
                printf("Recortada: [%s]\n", recortada);
                cadena_liberar_segura(&recortada);
            }
            else
            {
                printf("El texto esta vacio o solo tiene espacios.\n");
            }
 
            char *repetida = cadena_repetir(linea, (size_t)veces_leidas);
            if (repetida != NULL)
            {
                printf("Repetida: [%s]\n", repetida);
                cadena_liberar_segura(&repetida);
            }
            else
            {
                printf("No se pudo repetir el texto.\n");
            }
        }
        else
        {
            printf("Cantidad invalida.\n");
        }
    }
 
    return 0;
}
 