/*********************************************************************
TP1 - Ejercicio 4: Comparacion de numeros
Andrés Bocchigliere - Git: anon_006 - elmaildeandresbochi@gmail.com
Programacion 1 - Ingenieria en computacion - anon_001 - UNRN 
*********************************************************************/



#include <stdio.h>

int Compara(int numero, int otro_numero);
 
int main () 
{
	int numero_uno;
	int numero_dos;
	int resultado;
	
	printf("\n");
	printf("Ingrese dos numeros para ser comparados: \n");
	scanf("%d", &numero_uno);
	scanf("%d", &numero_dos);
	
	resultado = Compara(numero_uno, numero_dos);
	printf("%d\n", resultado);
	printf("\n");
}

int Compara(int numero, int otro_numero)
{
	int resultado;
	
	if(numero < otro_numero)
		resultado = -1;
	else if(numero > otro_numero)
		resultado = 1;
	else
		resultado = 0;
	
	return resultado;
}