/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_028
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int	numero, i, resultado;
	
	printf("Ingrese un numero entero positivo para calcular su factorial: ");
	scanf("%d", &numero);
		
	while(numero > 0)
	{
		resultado = 1;
		for(i = 1; i <= numero; i++)
		{	
			resultado = resultado * i;
		}
		printf("El factorial de %d es %d\n", numero, resultado);
		numero = numero - 1;
	}	
	return 0;
}