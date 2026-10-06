/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n");
    int datos[] = {10, 25, 40, 25, 60};
    size_t cantidad = 5;

    int buscado = 25;
    const int *encontrado = buscar_primero(datos, cantidad, &buscado);

    if (encontrado != NULL)
    {
        int distancia = distancia_punteros(datos, encontrado);
        printf("  buscar_primero(25): encontrado en indice %d (valor=%d)\n", distancia, *encontrado);
    }
    else
    {
        printf("  buscar_primero(25): no encontrado\n");
     }

    int no_esta = 99;
    const int *no_encontrado = buscar_primero(datos, cantidad, &no_esta);

    if (no_encontrado == NULL)
    {
         printf("  buscar_primero(99): no encontrado, como se esperaba\n");
    }

    printf("distancia_punteros:\n");
    printf("  distancia al primer elemento: %d\n", distancia_punteros(datos, &datos[0]));
    printf("  distancia al ultimo elemento: %d\n", distancia_punteros(datos, &datos[4]));

  
    return 0;
}
