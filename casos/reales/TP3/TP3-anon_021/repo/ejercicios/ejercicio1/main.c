/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");

    int x = 80;
    int y = 20;
    printf("Ordenar_par \n");
    printf("Valores iniciales: x= %d, y = %d\n",x,y);
    ordenar_par(&x,&y);
    printf("Valores ordenados: x = %d, y = %d\n \n",x,y);

    int a= 30;
    int b= 10;
    int c = 20;
    printf("Ordenar_tria \n");
    printf("Valores iniciales: a = %d, b = %d, c= %d\n", a , b, c);
    ordenar_tria(&a,&b,&c);
    printf("Valores obtenidos: a=%d,b=%d,c=%d\n \n", a, b, c);

    int arreglo[]= {10,20,30,40};
    size_t cantidad = 4;
    long long suma_total = 0;

    printf("Suma_acumulado \n");
    bool exito = sumar_acumulado(arreglo,cantidad,&suma_total);
    if (exito)
    {
        printf("Suma acumulada calculada ocn exitos: %lld\n",suma_total);

    }
    else
    {
        printf("Error al calcular suma acumulada.\n");
    }
    return 0;
}
