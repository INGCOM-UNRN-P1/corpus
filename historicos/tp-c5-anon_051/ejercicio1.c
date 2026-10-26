
#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 100

int esta_ordenado(int numeros[], int capacidad)
{
    /**
    *  La funcion compara los numeros para devolver si esta ordenado de forma ascendente o descendente y/o si no lo esta.
    *  @param i se usa para recorrer la lista de numeros
    *  @pre numeros es una cadena no nula
    *  @param resultado es la que almacena el valor a devolver de si esta o no ordenado y la manera en la que esta.
    *  @post Se devuelve el orden de la cadena
    */
	int i = 0;
	int resultado = 0;
	if(numeros[i] <= numeros[i + 1])
	{
		while(i < capacidad - 1)
        {
			if(numeros[i] <= numeros[i + 1])
            {
				resultado = 1;
			}
			else
            {
				resultado = 0;
                i = capacidad;
			}
			i++;
		}
	}
	else if(numeros[i] >= numeros[i + 1])
	{
		while(i < capacidad - 1)
        {
			if(numeros[i] >= numeros[i + 1])
            {
				resultado = -1;
			}
			else
            {
				resultado = 0;
                i = capacidad;
			}
			i++;
		}
	}
	else
    {
		resultado = 0;
	}
	return resultado;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
    {
		printf("Ingrese un nombre de archivo después del ./a.exe\n");
	}
	else
    {
		FILE *fichero = fopen(argv[1], "r");
		int numeros[MAXIMO];
		int recorredor = 0;
		int capacidad = 0;
        int contador = 1;
        int resultado = 0;
        while (feof(fichero)==0)
        {
            fscanf(fichero, "%d", &numeros[recorredor]);
            recorredor++;
			capacidad++;
        }
		fclose(fichero);
        while(contador <= capacidad - 1)
        {
            printf("%d \n", numeros[contador]);
            contador++;
        }
		resultado = esta_ordenado(numeros,capacidad);
		printf("El resultado es: %d\n", resultado);
	}
	return 0;	
}