/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");
    
    //---------------------------------------------------------------------------------------------------------
    printf("\n===== Copiar Arreglo =====\n");

    int origen[] = {1,2,3,4,5,6,7,8,9};
    size_t cantidad_origen = sizeof(origen)/sizeof(origen[0]);

    printf("ARREGLO ORIGEN: ");
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        printf("%d, ", origen[i]);
    }
    printf("\n");

    int destino[10];
    size_t cantidad_destino = sizeof(destino)/sizeof(destino[0]);

    size_t inicio = 3;
    size_t cantidad_a_copiar = 5;
    printf("Inicio: %zu\n", inicio);
    printf("Cantidad a copiar: %zu\n", cantidad_a_copiar);

    bool resultado = copiar_arreglo(origen, cantidad_origen, destino, cantidad_destino, inicio, cantidad_a_copiar);

    printf("ARREGLO DESTINO: ");
    for (size_t i = 0; i < cantidad_destino; i++)
    {
        printf("%d, ", destino[i]);
    }
    printf("\n");

    printf("Resultado de la operacion: %s\n", resultado? "exitosa" : "fallo");

    //---------------------------------------------------------------------------------------------------------
    printf("\n===== Invertir Arreglo =====\n");

    int arreglo[] = {1,2,3,4,5,6,7,8,9,10};
    size_t cantidad = sizeof(arreglo)/sizeof(arreglo[0]);

    printf("ARREGLO ANTES: ");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");

    invertir_arreglo(arreglo, cantidad);

    printf("ARREGLO DESPUES: ");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");

    return 0;
}