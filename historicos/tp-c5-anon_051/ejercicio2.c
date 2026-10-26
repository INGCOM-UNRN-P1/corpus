
#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 100

void ordenar_asc(int arreglo[], int capacidad)
{
    /**
    *  La funcion ordena los numeros de forma ascendente
    *  @param contador se usa para contar el maximo de elementos y frenar ahi
    *  @pre numeros es una cadena no nula
    *  @param i se usa para recorrer la lisat
    *  @param almacenar_valor se usa como un auxiliar para intercambiar valores en la lista.
    *  @post La cadena se ordena de forma ascendente
    */
	int contador = 0;
    int almacenar_valor = 0;
	while(contador < capacidad)
    {
		for (int i = 0; i < capacidad - 1; i++)
        {
			if (arreglo[i] >= arreglo[i + 1])
            {
				almacenar_valor = arreglo[i];
				arreglo[i] = arreglo[i + 1];
				arreglo[i + 1] = almacenar_valor;
			}
		}
		contador++;
	}
}
void ordenar_des(int arreglo[], int capacidad)
{
    /**
    *  La funcion ordena los numeros de forma descendente
    *  @param contador se usa para contar el maximo de elementos y frenar ahi
    *  @pre numeros es una cadena no nula
    *  @param i se usa para recorrer la lisat
    *  @param almacenar_valor se usa como un auxiliar para intercambiar valores en la lista.
    *  @post La cadena se ordena de forma descendente
    */
	int contador = 0;
    int almacenar_valor = 0;
	while(contador < capacidad)
    {
		for (int i = 0; i < capacidad - 1; i++)
        {
			if (arreglo[i] <= arreglo[i + 1])
            {
				almacenar_valor = arreglo[i];
				arreglo[i] = arreglo[i + 1];
				arreglo[i + 1] = almacenar_valor;
			}
		}
		contador++;
	}
}
int main(int argc, char *argv[])
{
	FILE *destino = fopen(argv[3], "w");
	if(argc != 4)
    {
		printf("Ingrese el primer archivo, seguido del orden, seguido del tercer archivo");
	}
	else
    {
		FILE *fichero = fopen(argv[1], "r");
		int numeros[MAXIMO];
		int recorredor = 0;
		int capacidad = 0;
        int contador = 1;
        while(feof(fichero)==0)
        {
            fscanf(fichero, "%d", &numeros[recorredor]);
            recorredor++;
			capacidad++;
        }
		fclose(fichero);
        printf("La cadena contenia los siguientes numeros :\n");
        while(contador <= capacidad - 1)
        {
            printf("%d \n", numeros[contador]);
            contador++;
        }
        contador = 0;
		if(argv[2][0] == 'a' && argv[2][1] == 's' && argv[2][2] == 'c')
        {
			ordenar_asc(numeros,capacidad);
		}
		else if(argv[2][0] == 'd' && argv[2][1] == 'e' && argv[2][2] == 's')
        {
			ordenar_des(numeros,capacidad);
		}
        else
        {
            printf("Ingrese el orden en minusculas de manera asc para ascendente o des para descendente\n");
        }
        while(contador < capacidad)
        {
            fprintf(destino, "%d \n", numeros[contador]);
            contador++;
        }
        fclose(destino);
	}
	return 0;	
}