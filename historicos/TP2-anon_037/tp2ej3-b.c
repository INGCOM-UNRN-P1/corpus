

#include <stdio.h>

int factorial(int numero);
int producto(int factor, int otrofactor);
int combinatorio(int numero_n, int numero_k);


int main()
{
	int numero_n;
	int numero_k;
	int resultado;
	
	printf("Ingrese dos numeros naturales, siendo el segundo no mayor al primero:\n");
	scanf("%d", &numero_n);
	scanf("%d", &numero_k);
	
	if (numero_n >= numero_k)
	{	
		resultado = combinatorio(numero_n, numero_k);
		printf("El combinatorio de %d sobre %d es: %d", numero_n, numero_k, resultado);
	}
	else
	{
		printf("ERROR, el segundo es mayor al primero.");
	}
}


int factorial(int numero)
{
	int i = 1;
	int factorial = 1;

	for (i; i <= numero; i++)
	{
		factorial = producto(factorial, i);
	}
	return factorial;
}



int producto(int factor, int otrofactor)
{
	int i = 1;
	int res = factor;

	for (i; i < otrofactor; i++)
	{
		res = res + factor;
	}
	return res;
}


int combinatorio(int numero_n, int numero_k)
{
	int combinatorio;
	int numerador;
	int denominador;
	int comp_uno;
	int comp_dos;
	
	
	numerador = factorial(numero_n);
	
	
	comp_uno = factorial(numero_k);
	
	comp_dos = numero_n - numero_k;
	comp_dos = factorial(comp_dos);
	
	denominador = producto(comp_uno, comp_dos);
	
	
	combinatorio = numerador / denominador;
	
	return combinatorio;
}