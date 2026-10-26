/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
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
int numero1, numero2, resultado;
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero: ");
	scanf("%d", &numero2);
	
	resultado = compara(numero1, numero2);
	printf("%d", resultado);
	return 0;
}