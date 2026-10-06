/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

static void mostrar_busqueda(const int *arreglo, size_t cantidad, int valor)
{
    const int *encontrato = buscar_primero(arreglo, cantidad, valor);

    if (encontrado == NULL)
    {
        printf("valor %d: no encontrado\n", valor);
        return;
    }

    printf("valor %d: encontrado en el indice %td (valor apuntado: %d)\n", valor, distancia_punteros(arreglo, encontrado), *encontrado);
}

int main(void)
{
    printf("ejercicio 4: busqueda con puntero\n");

    int datos[] = {7, 3, 9, 3, 15, 21};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);

    mostrar_busqueda(datos, cantidad, 9);
    mostrar_busqueda(datos, cantidad, 3);
    mostrar_busqueda(datos, cantidad, 21);
    mostrar_busqueda(datos, cantidad, 100);

    printf("distancia con inicio NULL: %td\n", dsitancia_punteros(NULL, datos));

    return 0;
}
