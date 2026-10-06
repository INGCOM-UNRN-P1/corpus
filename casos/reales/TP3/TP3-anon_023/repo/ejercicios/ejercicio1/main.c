/**
 * @file main.c
 * @brief Programa principal interactivo y demostrativo del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

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
    printf("=== Demostracion Ejercicio 1: Intercambio, Ordenamiento y Suma ===\n\n");

    int x = 45;
    int y = 12;
    printf("1. Valores iniciales: x = %d, y = %d\n", x, y);
    intercambiar(&x, &y);
    printf("   Tras intercambiar(&x, &y): x = %d, y = %d\n\n", x, y);

    int menor = 80;
    int mayor = 20;
    printf("2. Par desordenado: menor = %d, mayor = %d\n", menor, mayor);
    ordenar_par(&menor, &mayor);
    printf("   Tras ordenar_par: menor = %d, mayor = %d\n\n", menor, mayor);

    int a = 30;
    int b = 10;
    int c = 20;
    printf("3. Trio inicial: a = %d, b = %d, c = %d\n", a, b, c);
    ordenar_tria(&a, &b, &c);
    printf("   Tras ordenar_tria: a = %d, b = %d, c = %d\n\n", a, b, c);

    int datos[] = {10, 20, 30, 40};
    size_t cantidad = sizeof(datos) / sizeof(*(datos + 0));
    long long suma = 0;

    printf("4. Arreglo a sumar: ");
    imprimir_arreglo(datos, cantidad);

    if (sumar_acumulado(datos, cantidad, &suma))
    {
        printf("   Sumatoria acumulada calculada: %lld\n", suma);
    }

    return 0;
}
