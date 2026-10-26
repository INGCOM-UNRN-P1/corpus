/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_028
*************************/

#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[])
{	
	int divisor, dividendo, cociente, resto;
	
	printf("Digite 2 numeros naturales para dividirlos\n");
	printf("Numero: ");
	scanf("%d", &dividendo);
	printf("Numero: ");
	scanf("%d", &divisor);
	
	cociente = divide_lento(dividendo, divisor);
	resto = resto_lento(dividendo, divisor);
	printf("Cociente: %d\n", cociente);
	printf("Resto: %d", resto);
	
	return 0;
}


int divide_lento(int dividendo, int divisor)
{
	int resultado = 0;
	
	while(dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		resultado = resultado + 1;
	}
	return resultado;
}


int resto_lento(int dividendo, int divisor)
{
	while(dividendo >= divisor)
	{
		dividendo = dividendo - divisor;

	}
	return dividendo;
}
	