/**
Ingenieria en Computación - UNRN Andina
Programación 1
anon_042 de GitHub
**/
#include <stdio.h>
#define MAX 5
int get_min(int valores[MAX]);
int get_max(int valores[MAX]);
float compute_mean(int valores[MAX]);
int main()
{
 int valores[MAX] = {23, 4, 67, 32, 13};
 printf("El minimo es %d\n", get_min(valores));
 printf("El maximo es %d\n", get_max(valores));
 printf("El promedio es %f\n", compute_mean(valores));
 return 0;
}
int get_min(int valores[MAX])
{
	int numero_minimo = 0;
	numero_minimo = valores[0];
	for(int i=0; i<MAX; i++)
	{
		if (valores[i] < numero_minimo)
		{
			numero_minimo = valores[i];
		}
	}
	return numero_minimo;
}
int get_max(int valores[MAX])
{
	int numero_maximo = 0;
	numero_maximo = valores[0];
	for(int i=0; i<MAX; i++)
	{
		if (numero_maximo < valores[i])
		{
			numero_maximo = valores[i];
		}
	}
	return numero_maximo;
}
float compute_mean(int valores[MAX])
{
	float promedio = 0;
	float suma = 0;
	promedio = 0;
	for(int i=0; i<MAX; i++)
	{
		suma = valores[i] + suma;
	}
	promedio = suma/MAX;
	return promedio;
}