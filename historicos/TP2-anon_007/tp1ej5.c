/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
TP - 2
GitHub: anon_007
*************************/
#include <stdio.h>
#define MAX 5
int get_min(int valores[MAX]);
int get_max(int valores[MAX]);
int compute_mean(int valores[MAX]);
int main()
{
 int valores[MAX] = {23, 4, 67, 32, 13};
 printf("El minimo es %d\n", get_min(valores));
 printf("El maximo es %d\n", get_max(valores));
 printf("El promedio es %d\n", compute_mean(valores));
 return 0;
}
int get_min(int valores[MAX])
{
	int minimo = valores[0];
	for(int i = 0; i < MAX; i++)
	{
		if (valores[i] < minimo)
		{
			minimo = valores[i];
		}
	}
	return minimo;
}
int get_max(int valores[MAX])
{
	int maximo = valores[0];
	for(int i = 0; i < MAX; i++)
	{
		if (valores[i] > maximo)
		{
			maximo = valores[i];
		}
	}
	return maximo;
}
int compute_mean(int valores[MAX])
{
	int sum = 0;
	for(int i = 0; i < MAX; i++)
	{
		sum += valores[i];
	}
	return sum / MAX;
}