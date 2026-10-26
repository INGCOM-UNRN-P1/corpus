
#include <stdio.h>
#include <stdlib.h>
#define MAX 99999

void generador_lineal(int arreglo[], int cantidad, int direccion)
{
    /**
    * La funcion genera una lista de numeros con una direccion en la se suma(o se resta) un valor sucesivamente.
    *  @param arreglo es la direccion del arreglo en donde se va a guardar la lista de numeros generados
    *  @pre arreglo es un arreglo de tipo int
    *  @param cantidad es un número entero que contiene la cantidad de elementos a generar en el arreglo
    *  @pre cantidad es un valor numerico entero positivo mayor a uno
    *  @param direccion es un número entero que contiene la direccion en la cual se va a sumar(o restar) el valor de forma sucesiva
    *  @pre direccion es un valor numerico entero, puede ser positivo o negativo
    *  @returns void solo guarda la lista de numeros en el arreglo, no retorna nada
    */
    int i;
    
    for(i=1; i<cantidad; i++)
    {
        arreglo[i] = arreglo[i-1] + direccion;
    }
}
int main(int argc, char *argv[])
{
    int arreglo[MAX];
    int i;
    FILE *file;

    arreglo[0] = atoi(argv[2]);

    generador_lineal(arreglo, atoi(argv[1]), atoi(argv[3]));

    file = fopen("archivo_num.txt", "w");
    for (i=0; i<atoi(argv[1]); i++)
    {
        fprintf(file, "%d\n", arreglo[i]);
    }
    fclose(file);

    return 0;
}