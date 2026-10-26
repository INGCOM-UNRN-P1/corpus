
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int esta_ordenado(int array[], int cant)
{
    /**
    * La funcion se fija si la lista de numeros del archivo esta de forma ordenada o no.
    *  @param array es la direccion del arreglo con la que se verá si el contenido se encuentra ordenado o no
    *  @pre array es un arreglo de tipo int
    *  @param cant la cant es un número que contiene la cantidad de elementos en el arreglo
    *  @pre cant es un valor numerico entero positivo mayor a uno
    *  @returns int en donde 1 representan que la cadena esta ordenada de forma ascendente
                0 que la cadena no esta ordenada:
                y -1 que la cadena esta ordenada de forma descendente
    *  @post boolean es una variable de tipo int en donde se retorna los casos anteriores.
    */
    int i;
    int boolean;

    boolean = 0;
    for(i=2; i<cant; i++){
        if(array[i] >= array[i-1] && array[i] <= array[i+1])
        {
            boolean = 1;
        }
        else if(array[i] <= array[i-1] && array[i] >= array[i+1])
        {
            boolean = -1;
        }
        else
            boolean = 0;
            break;
    }

    return boolean;
}
int main(int argc, char *argv[])
{
    int arreglo[MAX];
    int c;
    int i = 0;
    int cantidad;
    int caso;
    FILE *file;

    file = fopen(argv[1], "r");
    
    do
    {
        fscanf(file, "%d", &arreglo[i]);
        i++;
    }
    while (!feof(file));
    fclose(file);
    cantidad = arreglo[0];

    caso = esta_ordenado(arreglo, cantidad);

    if(caso == 0){
        printf("No esta ordenado\n");
    }
    else if(caso == 1)
    {
        printf("Esta ordenado de forma ascendente");
    }
    else
        printf("Esta ordenado de forma descendente\n");

    return 0;
}

