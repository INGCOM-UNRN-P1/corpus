/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*************************/



#include <stdio.h>

void EsMultiplo(int numero, int multiplo);

int main()
{
    int numero;
	int i;
	
	while(i<101) 
	{
		printf("Por favor ingrese un numero entero mayor a 100: ");
		scanf("%d", &numero); 
		i = numero; 
		
		if (i<101)
		{
			printf("El numero igresado es menor o igual a 100.");
		}
	}
	
	printf("\nEl numero ingresado es: %d", numero);
	
	for(i=2; i<7; i++) 
	{
		printf("\nEs multiplo de %d: ", i);
		EsMultiplo(numero, i); 
	}
}

void EsMultiplo(int numero, int multiplo)
{
	int resultado;
	resultado = numero % multiplo;

	if (resultado == 0)
	{
		printf("SI");
	}
	else
	{
		printf("NO");
	}
}
