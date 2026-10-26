/****************************************************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*****************************************************************/



#include <stdio.h>

int Compara(int numero, int otroNumero);
 
int main () 
{
	int numeroUno;
	int numeroDos;
	int resultado;
	
	printf("\n");
    printf("\nIngrese dos numeros para ser comparados: ");
	scanf("%d %d", &numeroUno, &numeroDos);
	
	resultado = Compara(numeroUno, numeroDos);
	printf("\n%d", resultado);
	printf("\n");
}

int Compara(int numero, int otroNumero)
{
	int resultado;
	
	if(numero < otroNumero)
		resultado = -1;
	else if(numero > otroNumero)
		resultado = 1;
	else
		resultado = 0;
	
	return resultado;
}