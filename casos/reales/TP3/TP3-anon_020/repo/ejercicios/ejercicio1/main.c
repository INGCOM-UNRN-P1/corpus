/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"
#include "punteros.h"

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int valores[4] = {0};
    long long suma = 0;
    size_t cantidad = 4;

    printf("Ejercicio 1: Ordenamiento y suma acumulada\n");
    printf("Ingrese tres valores enteros: ");
    scanf("%d %d %d", &a, &b, &c);

    ordenar_par(&a, &b);
    printf("Tras ordenar_par: %d, %d\n", a, b);

    ordenar_tria(&a, &b, &c);
    printf("Tras ordenar_tria: %d, %d, %d\n", a, b, c);

    printf("Ingrese 4 valores para sumar acumulados: ");
    leer_arreglo_int(valores, cantidad);
    if (sumar_acumulado(valores, cantidad, &suma))
    {
        printf("Arreglo ingresado: ");
        mostrar_arreglo_int(valores, cantidad);
        printf("Suma acumulada: %lld\n", suma);
    }
    else
    {
        printf("No se pudo calcular la suma acumulada.\n");
    }

    return 0;
}
