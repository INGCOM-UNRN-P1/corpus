/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

#define MAX 5
int get_min();
int get_max();
double compute_mean();

int main()
{
	int valores[MAX] = {23, 4, 67, 32, 13};
	printf("El minimo es %d\n",get_min(valores));
    printf("El maximo es %d\n",get_max(valores));
	printf("El promedio es %.2f\n",compute_mean(valores));
    return 0;
}

int get_min(int valores[MAX])
{//esta funcion busca el valor minimo del arreglo.
	int minimo;
	int j;
	minimo = valores[0];
	for (j=1;j<MAX;j++)
	{
		if (minimo >= valores[j])
		{
			minimo = valores[j];
		}
	}
	return minimo;
}

int get_max(int valores[MAX])
{//esta funcion busca el valor maximo del arreglo.
	int maximo;
	int j;
	maximo = valores[0];
	for (j=1;j<MAX;j++)
	{
		if (maximo <= valores[j])
		{
			maximo = valores[j];
		}
	}
	return maximo;
}

double compute_mean(int valores[MAX])
{//esta funcion calcula el promedio de los valores del arreglo.
	int j, suma, promedio;
	suma = valores[0];
	for (j=1;j<MAX;j++)
	{
		suma += valores[j];
	}
	promedio = suma / MAX;
	return promedio;	
}