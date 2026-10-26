/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>
#define MAX 5
int get_min(int numeros[]);
int get_max(int numeros[]);
int compute_mean(int numeros[]);

int main()
{
    int valores[] = {23,4,67,32,13};
    printf("El minimo es: %d\n",get_min(valores));
    printf("El maximo es: %d\n",get_max(valores));
    printf("El promedio es: %f\n",compute_mean(valores));
    return 0;
}

int get_max(int numeros[MAX])
{
    int maximo;
    maximo = 0;
    for (int i=0;i<5;i++)
    {
        if (maximo < numeros[i])
        {
			maximo = numeros[i];
		}
	}
	return maximo;
}

int get_min(int numeros[])
{
	int minimo;
	minimo = numeros[0];
	for (int i=0;i<5;i++)
    {
		if (minimo > numeros[i])
        {
			minimo = numeros[i];
		}
	}

	return minimo;
}

int compute_mean(int numeros[])
{
	double promedio;
	promedio = 0;
	for (int i=0; i<5; i++)
    {
		promedio += numeros[i];
	}
	promedio = promedio / MAX;
	return promedio;
}
