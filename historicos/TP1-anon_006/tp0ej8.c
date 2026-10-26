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
		printf("\nIngrese un numero entero mayor a 100: ");
		scanf("%d", &numeroIngresado);
		
		if (numeroIngresado<101)
		{
			printf("\n");
			printf("El numero igresado es menor o igual a 100.");
		}
		
		printf("\n");
	}
	
	printf("\nEl numero ingresado es %d", numeroIngresado);
	
	int cadenaFibo[numeroIngresado];  
	cadenaFibo[0] = 0;
	cadenaFibo[1] = 1;
	
	int anterior = 1;
	int actual = 1;
	int sumaFibo = 0;
	int i = 2;
	
	printf("\nLos numeros de la sucesion de fibonacci menores a %d son: %d, %d", numeroIngresado, cadenaFibo[0], cadenaFibo[1]);

	while(sumaFibo < numeroIngresado + 1) 
	{
		sumaFibo = anterior + actual;
		anterior = actual;
		
		cadenaFibo[i] = actual;
		printf(", %d", cadenaFibo[i]);
		
		actual = sumaFibo; 
		i++;
	}
	
	printf("\n");
}