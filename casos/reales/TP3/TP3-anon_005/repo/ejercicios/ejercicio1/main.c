/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");
    
    int a = 5;
    int b = 10;
    printf("Antes de intercambiar: a=%d, b=%d\n", a, b);
    intercambiar(&a, &b);
    printf("Después de intercambiar: a=%d, b=%d\n", a, b);

    int menor = 20;
    int mayor = 5;
    printf("Antes de ordenar menor=%d, mayor=%d\n", menor, mayor);
    ordenar_par(&menor, &mayor);
    printf("Despues de ordenar menor=%d, mayor=%d\n",menor, mayor);

    int x = 34;
    int y = 10;
    int z = 20;
    printf("Antes de ordenar tria: a=%d, b=%d , c=%d\n", x, y, z);
    ordenar_tria(&x, &y , &z);
    printf("Despues de ordenar tria: a=%d, b=%d , c=%d\n", x, y, z);

    int datos[] = {10, 20, 30, 40};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);
    long long total = 0;

    if (sumar_acumulado(datos, cantidad, &total)) {
        printf("Suma exitosa. El total acumulado es: %lld\n", total);
    } else {
        printf("Error al calcular la suma.\n");
    }

    // 2. Caso con puntero NULL
    long long prueba_null = 0;
    if (!sumar_acumulado(NULL, cantidad, &prueba_null)) {
        printf("Correcto: La funcion detecto el puntero NULL y devolvio false.\n");
    }
    return 0;
}
