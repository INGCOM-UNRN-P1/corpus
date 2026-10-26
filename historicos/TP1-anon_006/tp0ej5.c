/****************************************************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*****************************************************************/



#include <stdio.h>

int main()
{
	int numeroUno;
	int numeroDos;
	int i;
	
	printf("\nPor favor ingrese dos numeros enteros: ");
	scanf("%d %d", &numeroUno, &numeroDos);
	printf("\nPrimer numero: %d", numeroUno);
	printf("\nSegundo numero: %d", numeroDos);
	
	if(numeroUno < numeroDos)
	{
		for(i=numeroUno; i<numeroDos+1; i++)
		{
			printf("\n%d", i);
		}
	}
	else if(numeroUno > numeroDos)
	{
		for(i=numeroDos; i<numeroUno+1; i++)
		{
			printf("\n%d", i);
		}
	}
	else
	{
		printf("\nLos dos numeros son iguales");
	}
}