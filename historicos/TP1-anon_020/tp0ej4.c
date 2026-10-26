/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/

#include <stdio.h>

int main(int argc, char *argv[])  
{
	int numero;
	int i;
	printf("ingrese un numero: ");
	scanf("%d", &numero);
	
	if (numero > 100) 
	{
		for(i=2;i<7;i++)
		{
			if(numero % i != 0)
			{
				printf("Es multiplo de %d: NO\n", i);
			}
			else
			{
			printf("Es multiplo de %d: SI\n", i);
			}
		}
	
	}
	else
	{
		printf("El numero no es mayor que 100");
	}
	return 0;
}