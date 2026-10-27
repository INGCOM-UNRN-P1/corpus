#include <stdio.h>
#include "quicksort.h"

void ordenar_quicksort(int *arreglo, size_t n);

int main(void)
{
    printf("Ejercicio 1: QuickSort Recursivo\n");
    int arr[] = {34, 7, 23, 32, 5, 62};
    ordenar_quicksort(arr, 6);
    return 0;
}
