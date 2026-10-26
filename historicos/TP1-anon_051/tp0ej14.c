/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);
int main(int argc, char *argv[])
{
	int dividendo;
	int divisor;
	int cociente;
	int resultado;
	int resto_len;
	int resto;
	printf("Ingrese el dividendo: ");
	scanf("%d", &dividendo);
	printf("Ingrese el divisor: ");
	scanf("%d", &divisor);
	resultado = divide_lento(dividendo, divisor);
	resto_len = resto_lento(dividendo, divisor);
	return 0;
}
int divide_lento(int dividendo, int divisor)
{
	int cociente;
	int temporal = dividendo;
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		cociente++;
	}
	printf("el cociente es: %d \n", cociente);
}
int resto_lento(int dividendo, int divisor)
{
	int temporal;
	int resto;
	int cociente;
	resto = temporal - (divisor * cociente);
	printf("el resto es: %d", resto);
}