

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1



int estaEnArreglo(int* arreglo, int tamano, int elemento);
int* elimina_duplicados(int* arreglo, int* tamano);

int main() 
{
    int entrada[] = {1, 2, 2, 3, 4, 4, 5};
    int tamano = sizeof(entrada) / sizeof(entrada[0]);

    // Elimina duplicados
    int* resultado = elimina_duplicados(entrada, &tamano);

    // Imprime resultado
    printf("Arreglo sin duplicados: ");
    for (int i = 0; i < tamano; ++i) 
    {
        printf("%d", resultado[i]);
    }
    printf("\n");

    // Libera memoria
    free(resultado);

    return 0;
}


int estaEnArreglo(int* arreglo, int tamano, int elemento) 
{
    int esta_oNo = 0;
    for (int i = 0; i < tamano; ++i) 
    {
        if (arreglo[i] == elemento) 
        {
            esta_oNo = 1; // El elemento está en el arreglo
        }
    }
    return esta_oNo; // El elemento no está en el arreglo
}


int* elimina_duplicados(int* arreglo, int* tamano) 
{
    int* unicos = (int*)malloc(*tamano * sizeof(int));
    if (unicos == NULL) 
    {
        unicos = ERROR;

    }

    int numUnicos = 0;

    for (int i = 0; i < *tamano; ++i) 
    {
        if (!estaEnArreglo(unicos, numUnicos, arreglo[i])) 
        {
            unicos[numUnicos] = arreglo[i];
            numUnicos++;
        }
    }

    // Redimensiona el arreglo de caracteres únicos
    unicos = (int*)realloc(unicos, numUnicos * sizeof(int));

    // Actualiza el tamaño
    *tamano = numUnicos;

    return unicos;
}
