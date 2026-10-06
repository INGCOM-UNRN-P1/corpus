/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main()
{
    printf("||||EJERCICIO 4 : BUSQUEDA CON PUNTEROS||||\n\n");
    const int arreglo[5] = {10, 20 ,30 ,40 ,50};
    size_t cantidad = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("BUSCAR EL VALOR 20 EN ARREGLO\n");
    const int valor = *buscar_primero(arreglo, cantidad, 20);

    printf("el valor %d se encuentra dentro del arreglo\n", valor);

    int distancia = distancia_punteros(arreglo, &valor);
    printf("DISTANCIA:\n");
    printf("La distancia de ese valor con respecto al inicio del arreglo es: %d\n", distancia);
    
    return 0;
}
