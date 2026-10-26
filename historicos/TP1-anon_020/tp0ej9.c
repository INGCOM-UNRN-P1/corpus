/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{

	int numero, i;
	
		printf("ingrese un numero: \n");
		scanf("%d", &numero);
		i = numero;
		for(i = 1; i<100;i++)
		{
		
			printf("el numero es menor que 100, ingrese otro numero: \n ");
			scanf("%d", &numero);
			i = numero;
		}
	
	printf("el numero es mayor que 100");
	return 0;
}