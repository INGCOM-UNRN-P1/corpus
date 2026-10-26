/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_023
*************************/

#include <stdio.h>
int compara(int numero, int otronumero)
{
	if(numero<otronumero)
	{
		return -1;
	}
	else if(numero == otronumero)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char *argv[])
{
int numero, otronumero, resultado;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	printf("ingrese otro numero: ");
	scanf("%d", &otronumero);
	
	resultado = compara(numero, otronumero);
	printf("%d", resultado);
	
	return 0;
}