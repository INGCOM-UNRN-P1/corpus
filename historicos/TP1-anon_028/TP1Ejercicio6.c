/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_028
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int	numero, i, resultado;
	
	resultado = 1;
	printf("Ingrese un numero entero positivo para calcular su factorial: ");
	scanf("%d", &numero);

	for(i = 1; i <= numero; i++)
	{	
		resultado = resultado * i;
	}

	printf("El factorial de %d es %d\n", numero, resultado);

	return 0;
}