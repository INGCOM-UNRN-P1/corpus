

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define POSICION_INVALIDA -2



int* insertaElemento(int* arreglo, int* tamano, int posicion, int valor);

int main()
{
    int tamano = 5;
    int* arreglo = (int*)malloc(tamano * sizeof(int));
    
    // Inicializar el arreglo
    for (int i = 0; i < tamano; ++i) 
    {
        arreglo[i] = i + 1;
    }

    printf("Arreglo original: ");
    for (int i = 0; i < tamano; ++i) 
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    int posicion = 2; // Insertar el nuevo elemento en la posición 2 (tercer elemento)
    int valor = 10;   // Valor del nuevo elemento a insertar
    arreglo = insertaElemento(arreglo, &tamano, posicion, valor);
    
    printf("Arreglo después de insertar el elemento %d en la posición %d: ", valor, posicion);
    for (int i = 0; i < tamano; ++i) 
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Liberar la memoria del arreglo
    free(arreglo);

    return 0;
}


int* insertaElemento(int* arreglo, int* tamano, int posicion, int valor) 
{
    // Verificar si la posición es válida
    if (posicion < 0 || posicion > *tamano) 
    {
        posicion = POSICION_INVALIDA;
        arreglo; // Devolver el arreglo original sin cambios
    }

    // Incrementar el tamaño del arreglo
    (*tamano)++;
    
    // Reservar memoria para el nuevo arreglo dinámico con un elemento más
    int* nuevoArreglo = (int*)malloc((*tamano) * sizeof(int));
    
    // Verificar si la reserva de memoria fue exitosa
    if (nuevoArreglo == NULL) 
    {
        nuevoArreglo = ERROR;
        
    }
    
    // Copiar los elementos del arreglo original al nuevo arreglo, insertando el nuevo valor en la posición especificada
    int i, j = 0;
    for (i = 0; i < *tamano; ++i) 
    {
        if (i == posicion) 
        {
            nuevoArreglo[i] = valor;
        } 
        else 
        {
            nuevoArreglo[i] = arreglo[j];
            ++j;
        }
    }
    
    // Liberar la memoria del arreglo original
    free(arreglo);
    
    return nuevoArreglo;
}
