/*********************************************************************
TP1 - Ejercicio 6: Divisiones
Andrés Bocchigliere - Git: anon_006 - elmaildeandresbochi@gmail.com
Programacion 1 - Ingenieria en computacion - anon_001 - UNRN 
*********************************************************************/



#include <stdio.h>

int division_lenta(int dividendo, int divisor);
int cociente_lento(int dividendo, int divisor);
 
int main () 
{
	int numero_uno;
	int numero_dos;
	int cociente;
	int resto;
	
	printf("Ingrese dos numeros para obtener el cociente y el resto entre el primero y el segundo: \n"),
	scanf("%d", &numero_uno);
	scanf("%d", &numero_dos);
	
	cociente = division_lenta(numero_uno, numero_dos);
	resto = cociente_lento(numero_uno, numero_dos);
	
	printf("\nEl cociente de dividir %d por %d es: %d", numero_uno, numero_dos, cociente);
	printf("\nEl resto de dividir %d por %d es: %d", numero_uno, numero_dos, resto);
	printf("\n");
	
}

int division_lenta(int dividendo, int divisor)
{
	int cociente = 0;
	
	while(dividendo >= divisor)
	{
		dividendo -= divisor;
		cociente += 1;
	}
	return cociente;
}

int cociente_lento(int dividendo, int divisor)
{
	int resto = dividendo;
	
	while(resto >= divisor)
	{	
		resto -= divisor;
	}
	return resto;
}