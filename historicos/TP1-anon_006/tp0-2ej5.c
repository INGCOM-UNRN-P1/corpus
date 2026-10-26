/****************************************************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*****************************************************************/



#include <stdio.h>

int DivideLento(int dividendo, int divisor);
int RestoLento(int dividendo, int divisor);
 
int main () 
{
	int numeroUno;
	int numeroDos;
	int cociente;
	int resto;
	
	printf("\nIngrese dos numeros para obtener el cociente y el resto entre el primero y el segundo: "),
	scanf("\n %d %d", &numeroUno, &numeroDos);
	
	cociente = DivideLento(numeroUno, numeroDos);
	resto = RestoLento(numeroUno, numeroDos);
	
	printf("\nEl cociente de dividir %d por %d es: %d", numeroUno, numeroDos, cociente);
	printf("\nEl resto de dividir %d por %d es: %d", numeroUno, numeroDos, resto);
	printf("\n");
	
}

int DivideLento(int dividendo, int divisor)
{
	int cociente = 0;
	
	while(dividendo>= divisor)
	{
		dividendo -= divisor;
		cociente += 1;
	}
	return cociente;
}
int RestoLento(int dividendo, int divisor)
{
	int resto = dividendo;
	
	while(resto>= divisor)
	{	
		resto -= divisor;
	}
	return resto;
}