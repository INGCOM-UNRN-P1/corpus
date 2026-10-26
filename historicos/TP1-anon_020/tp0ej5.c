/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i;
	int inicio;
	int final;
	printf("ingrese el inicio de la cadena de numeros: ");
	scanf("%d", &inicio);
	printf("ingrese el final de la cadena de numeros: ");
	scanf("%d", &final);
	printf(" Primer numero: %d", inicio);
	printf(" Segundo numero: %d\n", final);
	for(i=inicio;i<final;i++)
	{
	printf("%d\n", i);
	}
	
	printf("%d", final);
	return 0;

}