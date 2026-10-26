/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>

int factorial(int numero);
int producto(int factor, int otrofactor);
int combinatorio(int numero_n, int numero_k);


int main()
{
	int numero_n;
	int numero_m;
	int resultado;
	int i = 1;
	
	printf("Ingrese un numero natural --> ");
	scanf("%d", &numero_n);
	
	for(i; i<numero_n; i++)
	{
		numero_m = i;
		
		resultado = combinatorio(numero_n, numero_m);
		printf("El combinatorio de %d sobre %d es: %d \n", numero_n, numero_m, resultado);
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