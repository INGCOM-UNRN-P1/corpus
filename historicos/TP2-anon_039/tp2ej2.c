/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>

int producto(int n, int m);
int potencia(int n, int m);

int main(int argc, char *argv[])
{
	int numero_n = 0;
	int numero_m = 0;
	unsigned long long int resultado_producto = 0;
	unsigned long long int resultado_potencia = 0;
	
	printf("Ingrese el primer numero (n) = ");
	scanf("%d", &numero_n);
	printf("Ingrese el segundo numero (m) = ");
	scanf("%d", &numero_m);
	
	resultado_producto = producto(numero_n, numero_m);
	printf("El resultado del producto (n*m) = %llu\n", resultado_producto);
	resultado_potencia = potencia(numero_n, numero_m);
	printf("El resultado de la potencia (n^m) = %llu\n", resultado_potencia);
	
	return 0;
}

int producto(int n, int m)
{
	int i= 0;
	unsigned long long int resultado = 0;
	
	while (i < m)
	{
		i++;
		resultado = resultado + n;
	}
	
	return resultado;
}

int potencia(int n, int m)
{
	int i = 1;
	unsigned long long int resultado = n;
	
	while (i < m)
	{
		i++;
		resultado = resultado * n;
	}
	
	return resultado;
}