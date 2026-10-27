

#include <stdio.h>

int triangulo_asteriscos(int numero_n);


int main()
{
	int numero_n;
	int retorno;
	
	printf("Ingrese un numero natural --> ");
	scanf("%d", &numero_n);
	
	retorno = triangulo_asteriscos(numero_n);
}


int triangulo_asteriscos(int numero_n)
{
	int filas = 1;
	int contador = 1;
	int i = 1;

	for (filas; filas <= numero_n; filas++)
	{
		while (contador <= filas)
		{
			printf("*");
			contador += 1;			
		}
		printf("\n");
		contador = 1;
	}
}