/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>

int cuadrado_asteriscos(int numero_n);


int main()
{
	int numero_n;
	int retorno;
	
	printf("Ingrese un numero natural --> ");
	scanf("%d", &numero_n);
	
	retorno = cuadrado_asteriscos(numero_n);
}


int cuadrado_asteriscos(int numero_n)
{
	int filas = 1;
	int contador = 1;

	for (filas; filas <= numero_n; filas++)
	{
		for (contador; contador <= numero_n; contador++)
		{
			printf("*");
		}
		printf("\n");
		contador = 1;
	}
}