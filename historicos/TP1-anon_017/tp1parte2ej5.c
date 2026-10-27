
#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main()
{
	int dividendo;
	int divisor;
	int cociente;
	int resto;
	
	printf( "ingrese el numero que se va a dividir: ");
	scanf("%d",&dividendo);
	
	printf("ingrese el numero por el cual se va a dividir: ");
	scanf("%d",&divisor);
	
	cociente=divide_lento(dividendo,divisor);
	printf("El cociente de dividir %d por %d es: %d \n",dividendo,divisor,cociente);
	
	resto=resto_lento(dividendo,divisor);
	printf("El resto es: %d",resto);
	
}

int divide_lento(int dividendo, int divisor)
{
	int cociente;
	while (dividendo>=divisor)
	{
		dividendo = dividendo - divisor;
		cociente = cociente + 1;
	}
	return cociente;
}
int resto_lento(int dividendo, int divisor)
{
	int resto;
	resto=dividendo;
	while (resto>=divisor)
	{
		resto=resto-divisor;
	}
	return resto;
}
