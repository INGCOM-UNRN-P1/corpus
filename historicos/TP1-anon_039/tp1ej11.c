
#include <stdio.h>

int suma_lenta(int numero_a, int numero_b);
 
int main(int argc, char *argv[])
{
	long long int numero_a = 0;
	long long int numero_b = 0;
	long long int resultado = 0;
	
	printf("Ingrese el primer numero: ");
	scanf("%llu", &numero_a);
	printf("Ingrese el segundo numero: ");
	scanf("%llu", &numero_b);
	
	if (numero_a > 0 && numero_b > 0)
	{
		resultado = suma_lenta(numero_a, numero_b);
		printf("La suma entre %llu y %llu es: %llu.", numero_a, numero_b, resultado);
	}
	else
	{
		printf("Debe ingresar numeros naturales (positivos)");
	}
	return 0;
}

int suma_lenta(int numero_a, int numero_b)
{
	unsigned long long int resultado = 0;
	unsigned long long int menor = 0;
	unsigned long long int mayor = 0;
	
	if (numero_a < numero_b)
	{
		mayor = numero_b;
		menor = numero_a;
	}
	else
	{
		mayor = numero_a;
		menor = numero_b;
	}
	
	resultado = menor + mayor;
	
	while (menor < resultado)
	{
		menor = menor + 1;
	}
	
	return menor;
}