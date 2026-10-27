#include <stdio.h>
#include "mergesort.h"

void ordenar_mergesort(int *arreglo, size_t n);

int main(void)
{
    printf("Ejercicio 2: MergeSort Recursivo\n");
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    ordenar_mergesort(arr, 7);
    return 0;
}
