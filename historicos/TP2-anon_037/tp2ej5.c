

#include <stdio.h>

int get_min(int *valores);
int get_max(int *valores);
int compute_mean(int *valores);


#define MAX 5
int main()
{
	int valores[MAX] = {23, 4, 67, 32, 13};
	printf("El minimo es %d\n", get_min(valores));
	printf("El maximo es %d\n", get_max(valores));
	printf("El promedio es %d\n", compute_mean(valores));
	return 0;
}

int get_min(int *valores)
{
	int i = 1;
	int minimo = valores[0];
	
	for (i; i < 5; i++)
	{
		if (minimo > valores[i])
		{
			minimo = valores[i];
		}
	}
	return minimo;
}

int get_max(int *valores)
{
	int i = 1;
	int maximo = valores[0];
	
	for (i; i < 5; i++)
	{
		if (maximo < valores[i])
		{
			maximo = valores[i];
		}
	}
	return maximo;
}

int compute_mean(int *valores)
{
	int i = 1;
	int suma_total = valores[0];
	
	for (i; i < 5; i++)
	{
		suma_total += valores[i];
	}
	int promedio = suma_total / 5;
	return promedio;
}