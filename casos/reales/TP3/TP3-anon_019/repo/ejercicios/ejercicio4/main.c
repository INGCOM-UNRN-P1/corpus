/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Busqueda con punteros\n");

    int datos[] = {15, 42, 8, 99, 23};
    size_t cantidad = 5;
    int valor_a_buscar = 99;

    printf("Buscando el valor %d...\n", valor_a_buscar);
    
    const int *resultado = buscar_primero(datos, cantidad, valor_a_buscar);

    if (resultado != NULL)
    {
        int indice = distancia_punteros(datos, resultado);
        
        printf("¡Encontrado!\n");
        printf("Direccion de memoria: %p\n", (void*)resultado);
        printf("Indice calculado con punteros: %d\n", indice);
    }
    else
    {
        printf("El valor no se encuentra en el arreglo.\n");
    }

    return 0;
}