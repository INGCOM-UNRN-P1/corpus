

#include <stdio.h>

void intercambia(int* izquierda, int* derecha);
void ordenar(int arreglo[], int tamaño);

int main() 
{
    int arreglo[] = {5, 2, 9, 1, 5, 6};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);
    int contador;

    printf("Arreglo original: ");
    for (contador = 0; contador < tamaño; contador++) 
    {
        printf("%d ", arreglo[contador]);
    }
    printf("\tamaño");

    ordenar(arreglo, tamaño);

    printf("Arreglo ordenado: ");
    for (int contador = 0; contador < tamaño; contador++) 
    {
        printf("%d ", arreglo[contador]);
    }
    printf("\tamaño");

    return 0;
}


void intercambia(int* izquierda, int* derecha) 
{
    int auxiliar;
    auxiliar = *izquierda;
    *izquierda = *derecha;
    *derecha = auxiliar;
}


void ordenar(int arreglo[], int tamaño) 
{
    int contador;
    int iterador;

    for (contador = 0; contador < tamaño - 1; contador++) 
    {
        for (iterador = 0; iterador < tamaño - contador - 1; iterador++) 
        {
            if (arreglo[iterador] > arreglo[iterador + 1]) 
            {
                intercambia(&arreglo[iterador], &arreglo[iterador + 1]);
            }
        }
    }
}

