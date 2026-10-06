/**
 * @file main.c
 * @brief Programa principal interactivo y demostrativo del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

static void imprimir_arreglo(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    printf("[ ");
    while (actual < fin)
    {
        printf("%d ", *actual);
        actual++;
    }
    printf("]\n");
}

int main(void)
{
    printf("=== Demostracion Ejercicio 4: Busqueda con Retorno de Puntero ===\n\n");

    int datos[] = {11, 22, 33, 44, 55, 33};
    size_t cantidad = sizeof(datos) / sizeof(*(datos + 0));

    printf("Arreglo cargado: ");
    imprimir_arreglo(datos, cantidad);

    int valores_a_buscar[] = {33, 55, 99};
    size_t num_consultas = sizeof(valores_a_buscar) / sizeof(*(valores_a_buscar + 0));

    const int *ptr_consulta = valores_a_buscar;
    const int *fin_consultas = valores_a_buscar + num_consultas;

    while (ptr_consulta < fin_consultas)
    {
        int buscado = *ptr_consulta;
        printf("\nBuscando el valor %d...\n", buscado);

        const int *hallado = buscar_primero(datos, cantidad, buscado);
        if (hallado != NULL)
        {
            ptrdiff_t indice = distancia_punteros(datos, hallado);
            printf("  -> Hallado en direccion de memoria : %p\n", (const void *)hallado);
            printf("  -> Valor en esa direccion         : %d\n", *hallado);
            printf("  -> Indice (distancia relativa)    : %td\n", indice);
        }
        else
        {
            printf("  -> El valor %d no fue encontrado en el arreglo.\n", buscado);
        }

        ptr_consulta++;
    }

    return 0;
}
