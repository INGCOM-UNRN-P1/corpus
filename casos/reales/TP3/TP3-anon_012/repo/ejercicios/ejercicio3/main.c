/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    int original[5] = {10, 20, 30, 40, 50};
    int copia[5] = {0};
    size_t cantidad = 5;

    printf("Ejercicio 3: Recorrido e inversión con punteros\n");
    

    if (copiar_arreglo(copia, original, cantidad))
    { 
        printf("Arreglo original: "); 
        
        for (size_t i = 0; i < cantidad; i++)
        { 
            printf("%d ", *(original + i));
        } 
        printf("\\n"); 
        printf("Copia generada: ");
        
        for (size_t i = 0; i < cantidad; i++)
        { 
            printf("%d ", *(copia + i));
        }
        printf("\\n\\n");
    } 
    else
    {
        printf("Error al copiar el arreglo.\\n");
    }
    
    if (invertir_arreglo(copia, cantidad))
    {
        printf("Copia invertida: ");
        
        for (size_t i = 0; i < cantidad; i++)
        {
            printf("%d ", *(copia + i));
        }
        printf("\\n");
    }
    else
    {
        printf("Error al invertir el arreglo.\\n");
    }

    return 0;
}
