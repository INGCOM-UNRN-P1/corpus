
#include <stdio.h>
#include <stdlib.h>
#define MAX 99999

void generador_aleatorio(int arreglo[], int cantidad, int min, int max)
{
    /**
    * La funcion genera una lista de numeros de forma aleatoria con un tope maximo y minimo.
    *  @param arreglo es la direccion del arreglo en donde se va a guardar la lista de numeros generados
    *  @pre arreglo es un arreglo de tipo int
    *  @param cantidad es un número entero que contiene la cantidad de elementos a generar en el arreglo
    *  @pre cantidad es un valor numerico entero positivo mayor a uno
    *  @param min es un número entero que contiene el tope minimo de valor de los numeros a generar
    *  @pre min es un valor numerico entero
    *  @param max es un número entero que contiene el tope maximo de valor de los numeros a generar
    *  @pre max es un valor numerico entero
    *  @returns void solo guarda la lista de numeros en el arreglo, no retorna nada
    */
    int i;

    if(min < 0)
    {
        min = -min;
    }
    
    for(i=0; i<cantidad; i++)
    {
        arreglo[i] = rand() % (max + min + 1) - min;
    }
}
int main(int argc, char *argv[])
{
    int arreglo[MAX];
    int i;
    FILE *file;

    generador_aleatorio(arreglo, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

    file = fopen("archivo_num_aleatorio.txt", "w");
    for (i=0; i<atoi(argv[1]); i++)
    {
        fprintf(file, "%d\n", arreglo[i]);
    }
    fclose(file);

    return 0;
}