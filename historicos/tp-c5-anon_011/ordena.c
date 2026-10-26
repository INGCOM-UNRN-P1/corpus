
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void ordena(int arreglo[], int cantidad, char cadena[]) 
{
    /**
    * La funcion ordena la lista de numeros de forma ascendente o descendente.
    *  @param arreglo es la direccion del arreglo que contiene la lista de numeros a ordenar
    *  @pre arreglo es un arreglo de tipo int
    *  @param cantidad es un número entero que contiene la cantidad de elementos en el arreglo
    *  @pre cantidad es un valor numerico entero positivo mayor a uno
    *  @returns void solo ordena el arreglo de forma ascendente o descendente, no retorna nada
    */
	int i, temporal;
	
	temporal = 0;
	if(cadena == "asc") {
	    for(i=2; i<=cantidad; i++)
	    {
		    if(arreglo[i] < arreglo[i-1])
		    {
			    temporal = arreglo[i-1];
			    arreglo[i-1] = arreglo[i];
			    arreglo[i] = temporal;
			    i = 0;
            }
        }
    }
    else 
        for(i=2; i<=cantidad; i++)
	    {
		    if(arreglo[i] > arreglo[i-1])
		    {
			    temporal = arreglo[i-1];
			    arreglo[i-1] = arreglo[i];
			    arreglo[i] = temporal;
			    i = 0;
            }
        }
}

int main(int argc, char *argv[])
{
    int arreglo[MAX];
    int i = 0;
    int cantidad;
    FILE *file;
    FILE *archivo;

    file = fopen(argv[2], "r");
    do
    {
        fscanf(file, "%d", &arreglo[i]);
        printf("%d\n", arreglo[i]);
        i++;
    }
    while (!feof(file));
    cantidad = arreglo[0];

    fclose(file);

    ordena(arreglo, cantidad, argv[1]);

    archivo = fopen("archivo_ordenado.txt", "w");
    for (i=0; i<=cantidad; i++)
    {
        fprintf(archivo, "%d\n", arreglo[i]);
    }
    fclose(archivo);

    return 0;
}