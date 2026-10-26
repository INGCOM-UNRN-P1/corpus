

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1


int* reserva_arreglo_enteros(int tamano);
void libera_arreglo_enteros(int* arreglo);

int main()
{
    int tamano = 7;
    int i;

    int* arreglo_enteros = reserva_arreglo_enteros(tamano);

    for(i=0; i<tamano; i++)
    {
        arreglo_enteros[i] = i + 1;
    }

    printf("valores del arreglo: ");
    for(i=0; i<tamano; i++)
    {
        printf("%d", arreglo_enteros[i]);
    }
    printf("\n");

    libera_arreglo_enteros(arreglo_enteros);

    return 0;
}


int* reserva_arreglo_enteros(int tamano) 
{
    // Reservar memoria para el arreglo de enteros de tamaño fijo
    int* arreglo = (int*)malloc(tamano * sizeof(int));
    
    // Verificar si la reserva de memoria fue exitosa
    if (arreglo == NULL)  
    {
        // Maneja el error
        arreglo = ERROR;
    }

    return arreglo;
}


void libera_arreglo_enteros(int* arreglo) 
{
    if(arreglo!= NULL)
    {
    // Liberar la memoria del arreglo de enteros
        free(arreglo);

    }
}
