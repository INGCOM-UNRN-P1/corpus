/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n\n");

    
    int x = 5;
    int y = 12;
    printf("intercambiar:\n");
    printf("  Antes:   x = %d, y = %d\n", x, y);
    intercambiar(&x, &y);
    printf("  Despues: x = %d, y = %d\n\n", x, y);

    
    int menor = 80;
    int mayor = 20;
    printf("ordenar_par:\n");
    printf("  Antes:   menor = %d, mayor = %d\n", menor, mayor);
    ordenar_par(&menor, &mayor);
    printf("  Despues: menor = %d, mayor = %d\n\n", menor, mayor);

    
    int a = 30;
    int b = 10;
    int c = 20;
    printf("ordenar_tria:\n");
    printf("  Antes:   a = %d, b = %d, c = %d\n", a, b, c);
    ordenar_tria(&a, &b, &c);
    printf("  Despues: a = %d, b = %d, c = %d\n\n", a, b, c);

    
    int datos[] = {10, 20, 30, 40};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);
    long long suma = 0;
    printf("sumar_acumulado:\n");
    if (sumar_acumulado(datos, cantidad, &suma))
    {
        printf("  Suma de los %zu elementos: %lld\n", cantidad, suma);
    }
    else
    {
        printf("  Error: punteros invalidos.\n");
    }

    return 0;
}