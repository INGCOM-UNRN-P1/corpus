/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
#define ALMACENADOR 300
int factorial(int numero_n, int numero_k);
int factorial_2(int numero_n, int numero_2);
int main(int argc, char *argv[])
{
	int numero_n = 0;
	int numero_k = 0;
	int numero_2 = 0;
	int total;
	int total2;
	printf("Ingrese un numero entero para calcular su factorial \n");
	scanf("%d", &numero_n);
	printf("Ingrese un numero entero menor o igual al primero para calcular su factorial \n");
	scanf("%d", &numero_k);
	total = factorial(numero_n, numero_k);
	total2 = factorial_2(numero_n, numero_2);
	printf("%d \n %d", total, total2);
	return 0;
}
int factorial(int numero_n, int numero_k)
{
	double factorial_n = 1;
	double factorial_k = 1;
	double factorial_ambos = 1;
	unsigned long long int resta_ambos = 0;
	double resultado = 0;
	unsigned long long int guardar_1 = 0;
	unsigned long long int guardar_2 = 0;
	unsigned long long int guardar_3 = 0;
	int i = 0;
	resta_ambos = numero_n - numero_k;
	for (i=1;i<=numero_n;i++)
	{
		factorial_n = factorial_n * i;
	}
	guardar_1 = factorial_n;
	printf("El factorial de %d es %.f \n", numero_n, factorial_n);
	if (numero_k<=numero_n)
	{
		for (i=1;i<=numero_k;i++)
		{
			factorial_k = factorial_k * i;
			guardar_2 = factorial_k;
		}
	}
	else
	{
		printf("El segundo numero debe ser menor o igual al primero, intentelo nuevamente");
		return 0;
	}
	for (i=1;i<=resta_ambos;i++)
	{
		factorial_ambos = factorial_ambos * i;
	}
	guardar_3 = factorial_ambos;
	resultado = (guardar_1)/(guardar_2*guardar_3);
	printf("El combinatorio %d %d es %f \n \n", numero_n, numero_k, resultado);
	return 0;
}
int factorial_2(int numero_n, int numero_2)
{
	int i = 0;
	double almacenar[ALMACENADOR];
	double almacenar_2[ALMACENADOR];
	double almacenar_resultado[ALMACENADOR];
	unsigned long long int almacenar_resta[ALMACENADOR];
	unsigned long long int almacenar_numero[ALMACENADOR];
	double factorial_n = 1;
	double factorial_k = 1;
	double factorial_ambos = 1;
	unsigned long long int resta_ambos = 0;
	double resultado = 0;
	unsigned long long int guardar_1 = 0;
	unsigned long long int guardar_2 = 0;
	unsigned long long int guardar_3 = 0;
	for (i=1; i<numero_n; i++)
	{
		numero_2 = i;
		almacenar_numero[i-1] = numero_2;
	}
	for (i=1; i<numero_n; i++)
	{
		resta_ambos = numero_n - almacenar_numero[i-1];
		almacenar_resta[i-1] = resta_ambos;
	}
	for (i=1;i<=numero_n;i++)
	{
		factorial_n = factorial_n * i;
	}
	guardar_1 = factorial_n;
	for (i=1;i<numero_n;i++)
	{
		factorial_k = factorial_k * i;
		almacenar[i-1] = factorial_k;
	}
	for (int j=0; j<numero_n; j++)
	{	
		factorial_ambos = 1;
		for (i=1;i<=almacenar_resta[j];i++)
		{
			factorial_ambos = factorial_ambos * i;
			almacenar_2[j] = factorial_ambos;
		}
	}
	for (i=0; i<numero_n;i++)
	{
		guardar_2 = almacenar[i];
		guardar_3 = almacenar_2[i];
		resultado = (guardar_1)/(guardar_2*guardar_3);
		almacenar_resultado[i] = resultado;
		printf("El combinatorio %d %llu es %.f \n", numero_n, almacenar_numero[i], almacenar_resultado[i]);
	}
	return 0;
}
