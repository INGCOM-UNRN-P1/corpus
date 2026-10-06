

#include <stdio.h>
#include "recorrido.h"
#include <stdbool.h>

static void imprimir_arreglo(const int *arreglo, size_t cantidad)
    {
        const int *actual = arreglo;
        const int *fin = arreglo + cantidad;
 
        while (actual != fin)
        {
            printf("%d ", *actual);
            actual++;
        }
            printf("\n");
        } 
int main(void)
{
    

    printf("Ejercicio 3: Recorrido e inversión con punteros\n");
   
    const int origen[] = {2,4,-10,20};
    int destino[4];
    size_t cantidad = sizeof(origen) / sizeof(origen[0]);

    printf("Copiar arreglo: \n");

    if(copiar_arreglo(origen,cantidad,destino))
    {
        printf("origen: ");
        imprimir_arreglo(origen,cantidad);
        rintf("destino: ");
        imprimir_arreglo(destino,cantidad);
    }
    else
    {
       printf("Error.No se pudo copiar");
    }

    int arreglo[] = {4,6,-8,90};
    size_t capacidad = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Invertir entero\n");
    printf("Antes: ");
    imprimir_arreglo(arreglo, capacidad);

    if(invertit_entero(arreglo, capacidad))
    {
        printf("Despues: ");
        imprimir_arreglo(arreglo, capacidad);
    }
    else
    {
        printf("Error.No se pudo invertir");
    }

    return 0;
}
