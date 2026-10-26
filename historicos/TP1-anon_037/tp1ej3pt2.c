/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>

int compara(int numero, int otronumero);

int main()
{
	int numero;
	int otronumero;
	int resultado;
	
	printf("Ingrese dos numeros para ser comparados\n");
	
	printf("--> ");
	scanf("%d", &numero);
	
	printf("--> ");
	scanf("%d", &otronumero);
	
	resultado = compara(numero, otronumero);	
	printf("El resultado es : %d", resultado);
	
}

int compara(int numero, int otronumero)
{
	int res;
	
	if (numero > otronumero)
	{	
		res = 1;
	}
	
	else if (numero < otronumero)
	{
		res = -1;
	}
	
	else
	{
		res = 0;
	}

	return res;
}	