/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[])
{
	int dividendo;
	int divisor;
	int resultado_divide;
	int resultado_resto;
	printf("Ingrese el número entero que va a dividir: ", dividendo);
	scanf("%d", &dividendo);
	printf("Ingrese su número entero divisor: ", divisor);
	scanf("%d", &divisor);
	resultado_divide = divide_lento(dividendo,divisor);
	resultado_resto = resto_lento(dividendo,divisor);
	printf("Cociente: %d\nResto: %d", resultado_divide, resultado_resto);
	
	return 0;
}


int divide_lento(int dividendo, int divisor)
{
	int cociente = 0;
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		cociente = cociente + 1;
	}
	return cociente;
}

int resto_lento(int dividendo, int divisor)
{
	int cociente = 0;
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		cociente = cociente + 1;
	}
	return dividendo;
}
