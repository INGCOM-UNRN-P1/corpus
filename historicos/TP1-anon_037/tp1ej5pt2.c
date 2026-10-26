/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main()
{
	int dividendo;
	int divisor;
	
	int cociente;
	int resto;
	
	printf("Ingrese un numero dividendo --> ");
	scanf("%d", &dividendo);
	
	printf("Ingrese un numero divisor --> ");
	scanf("%d", &divisor);
	
	cociente = divide_lento(dividendo, divisor);	
	printf("El cociente es : %d \n", cociente);
	
	resto = resto_lento(dividendo, divisor);	
	printf("El resto es : %d", resto);
}

int divide_lento(int dividendo, int divisor)
{
	int cociente = 0;
	
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		cociente += 1;
	}
	
	return cociente;
}	

int resto_lento(int dividendo, int divisor)
{
	int resto;
	int i;
	
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
	}
	
	resto = dividendo;
	
	return resto;
}