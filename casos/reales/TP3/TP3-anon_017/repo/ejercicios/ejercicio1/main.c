/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");
    
    int num_mayor = 3;
    int num_menor = 27;
    printf("Antes numero mayor: %d, numero menor: %d\n", num_mayor, num_menor);
    ordenar_par(&num_menor, &num_mayor);
    printf("Despues numero mayor: %d, numero menor: %d\n", num_mayor, num_menor);
    
    int num1 = 19;
    int num2 = 97;
    int num3 = 8;
    printf("Desordenado: %d %d %d\n", num1, num2, num3);
    ordenar_tria(&num1, &num2, &num3);
    printf("Ordenado: %d %d %d\n", num1, num2, num3);

    long long total = 0;

    int arr[] = {2,2,3,3};
    size_t cantidad_elementos = sizeof(arr) / sizeof(arr[0]);

    bool estado_operacion = sumar_acumulado(arr, cantidad_elementos, &total);
    if(estado_operacion == true)
    {
        printf("La suma de los elementos es: %lld\n", total);
    }
    return 0;
}
