/****************************************************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*****************************************************************/



#include <stdio.h>

int main()
{
	int numeroIngresado;
	
	while(numeroIngresado < 101)
	{		
		printf("\n Por favor, Ingrese un numero entero mayor a 100: ");
		scanf("%d", &numeroIngresado);
		
		if (numeroIngresado<101)
		{
			printf("\n");
			printf("El numero igresado es menor o igual a 100.");
		}
		
		printf("\n");
	}
	
	printf("\nEl numero ingresado %d es mayor a 100. Gracias!", numeroIngresado);
	printf("\n");
}