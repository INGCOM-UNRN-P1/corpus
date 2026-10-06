/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    int primer_valor = 80;
    int segundo_valor = 20;

    int primer_tria = 30;
    int segundo_tria = 10;
    int tercer_tria = 20;

    int datos[] = {10, 20, 30, 40};
    size_t cantidad = 4;
    long long suma = 0;

    printf("Ejercicio 1: Intercambio con punteros\n");

    printf("\nPar antes de ordenar: %d %d\n", primer_valor, segundo_valor);
    ordenar_par(&primer_valor, &segundo_valor);
    printf("Par despues de ordenar: %d %d\n", primer_valor, segundo_valor);

    printf("\nTria antes de ordenar: %d %d %d\n",
           primer_tria, segundo_tria, tercer_tria);

    ordenar_tria(&primer_tria, &segundo_tria, &tercer_tria);

    printf("Tria despues de ordenar: %d %d %d\n",
           primer_tria, segundo_tria, tercer_tria);

    if (sumar_acumulado(datos, cantidad, &suma))
    {
        printf("\nSuma acumulada: %lld\n", suma);
    }
    else
    {
        printf("\nNo se pudo calcular la suma acumulada.\n");
    }

    return 0;
}
