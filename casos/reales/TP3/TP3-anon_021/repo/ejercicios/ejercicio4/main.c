/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Búsqueda con Retorno de Puntero y Distancia \n\n");
    int datos[] = {10, 25, 42, 8, 19, 42, 73};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);

    printf("Arreglo analizado: {10, 25, 42, 8, 19, 42, 73}\n");
    printf("Cantidad de elementos: %zu\n\n", cantidad);

    int valor_buscado = 42;
    printf(" buscar_primero \n");
    printf("Buscando la primera aparición del valor: %d\n", valor_buscado);

    const int *resultado_ptr = buscar_primero(datos, cantidad, valor_buscado);

    if (resultado_ptr != NULL)
    {
        printf("¡Elemento encontrado en memoria!\n");
        printf("Dirección encontrada: %p\n", (void *)resultado_ptr);
        printf("Valor en esa dirección: %d\n\n", *resultado_ptr);

        printf("distancia_punteros \n");
        ptrdiff_t indice = distancia_punteros(datos, resultado_ptr);

        if (indice != -1)
        {
            printf("Distancia calculada desde el inicio: %td elementos.\n", indice);
            printf("Comprobación: datos[%td] = %d\n\n", indice, datos[indice]);
        }
        else
        {
            printf("Error al calcular la distancia de los punteros.\n\n");
        }
    }
    else
    {
        printf("El valor %d no se encuentra en el arreglo.\n\n", valor_buscado);
    }

    int valor_ausente = 999;
    printf("búsqueda fallida (%d) ---\n", valor_ausente);
    const int *ausente_ptr = buscar_primero(datos, cantidad, valor_ausente);
    
    if (ausente_ptr == NULL)
    {
        printf("El valor %d no existe. buscar_primero retornó NULL correctamente.\n", valor_ausente);
    }

    return 0;
}
