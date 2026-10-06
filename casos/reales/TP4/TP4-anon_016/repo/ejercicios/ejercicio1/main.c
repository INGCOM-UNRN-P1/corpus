/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"


static void mostrar_bloque(const char *titulo, const int *bloque,
                           size_t cantidad)
{
    printf("%s:", titulo);
    for (size_t indice = 0; indice < cantidad; indice++)
    {
        printf(" %d", bloque[indice]);
    }
    printf("\n");
}
 
int main(void)
{
      printf("Ejercicio 1: Vector Dinámico de Enteros\n");
    int cantidad_leida = 0;
 
    printf("Cantidad de elementos: ");
    int leidos = scanf("%d", &cantidad_leida);
 
    if (leidos == 1 && cantidad_leida > 0)
    {
        size_t cantidad = (size_t)cantidad_leida;
        int *numeros = crear_bloque_enteros(cantidad);
 
        if (numeros != NULL)
        {
            for (size_t indice = 0; indice < cantidad; indice++)
            {
                printf("Numero %zu: ", indice + 1);
                leidos = scanf("%d", &numeros[indice]);
                if (leidos != 1)
                {
                    printf("Entrada invalida, se toma 0.\n");
                }
            }
 
            mostrar_bloque("Original", numeros, cantidad);
 
            int *copia = clonar_arreglo_enteros(numeros, cantidad);
            if (copia != NULL)
            {
                mostrar_bloque("Clon", copia, cantidad);
                liberar_bloque_enteros(&copia);
            }
 
            size_t cantidad_pares = 0;
            int *pares = filtrar_arreglo_pares(numeros, cantidad,
                                               &cantidad_pares);
            if (pares != NULL)
            {
                mostrar_bloque("Pares", pares, cantidad_pares);
                liberar_bloque_enteros(&pares);
            }
            else
            {
                printf("No hay numeros pares.\n");
            }
 
            liberar_bloque_enteros(&numeros);
        }
        else
        {
            printf("No hay memoria disponible.\n");
        }
    }
    else
    {
        printf("Cantidad invalida.\n");
    }
 
    return 0;
}