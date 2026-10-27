
#include <stdio.h>
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[])
{
	int dividendo = 0;
	int divisor = 0;
	int cociente = 0;
	int resto = 0;
	
	printf("Ingrese el numero que quiere dividir (dividendo): #");
	scanf("%d", &dividendo);
	printf("Ingrese el numero con el que va a dividir (divisor): #");
	scanf("%d", &divisor);
	
	cociente = divide_lento(dividendo, divisor);
	printf("El cociente de la division es %d\n", cociente);
	resto = resto_lento(dividendo, divisor);
	printf("El resto de la division es %d", resto);
	return 0;
}

int divide_lento(int dividendo, int divisor)
{
	int cociente = 0;
	
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
		cociente++;
	}
	return cociente;
}

int resto_lento(int dividendo, int divisor)
{
	while (dividendo >= divisor)
	{
		dividendo = dividendo - divisor;
	}
	return dividendo;
}
