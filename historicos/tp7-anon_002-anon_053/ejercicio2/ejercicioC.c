
#include<stdio.h>
#include <stdlib.h>

#define ERROR -1
#define POSICION_INVALIDA -2



int* elimina_elemento(int* arreglo, int tamano, int posicion);

int main()
{
    int tamano = 5;
    int* arreglo = (int*)malloc(tamano * sizeof(int));
    
    // Inicializar el arreglo
    for (int i = 0; i < tamano; i++) 
    {
        arreglo[i] = i + 1;
    }

    printf("Arreglo original: ");
    for (int i = 0; i < tamano; i++) 
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    int posicion = 2; // Eliminar el elemento en la posición 2 (tercer elemento)
    arreglo = elimina_elemento(arreglo, tamano, posicion);
    tamano--; // Reducir el tamaño del arreglo
    
    printf("Arreglo después de eliminar el elemento en la posición %d: ", posicion);
    for (int i = 0; i < tamano; i++) 
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Liberar la memoria del arreglo
    free(arreglo);

    return 0;
}


int* elimina_elemento(int* arreglo, int tamano, int posicion) 
{
    // Verificar si la posición es válida
    if (posicion < 0 || posicion >= tamano) 
    {
        posicion = POSICION_INVALIDA;
        arreglo; // Devolver el arreglo original
    }

    // Reducir el tamaño del arreglo
    int nuevoTamano = tamano - 1;
    
    // Reservar memoria para el nuevo arreglo dinámico con un elemento menos
    int* nuevoArreglo = (int*)malloc(nuevoTamano * sizeof(int));
    
    // Verificar si la reserva de memoria fue exitosa
    if (nuevoArreglo == NULL) 
    {
        nuevoArreglo = ERROR;
    }
    
    // Copiar los elementos del arreglo original al nuevo arreglo, excluyendo el elemento en la posición especificada
    int i;
    int j = 0;
    for (i = 0; i < tamano; i++) 
    {
        if (i != posicion) 
        {
            nuevoArreglo[j] = arreglo[i];
            j++;
        }
    }
    
    // Liberar la memoria del arreglo original
    free(arreglo);
    
    return nuevoArreglo;
}
