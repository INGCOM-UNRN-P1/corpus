

#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);
int solicitar_numero();


int main(int argc, char *argv[])
{	
	int divisor, dividendo, cociente, resto;
	
	printf("Digite 2 numeros naturales para dividirlos\n");
	dividendo = solicitar_numero();
	divisor = solicitar_numero();
	
	while(dividendo < divisor)
	{
		printf("El dividendo tiene que ser mayor al divisor, reingrese los numeros\n");
		dividendo = solicitar_numero();
		divisor = solicitar_numero();
	}
	
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


int solicitar_numero()
{
	int numero;
	
	do
	{
		printf("Numero: ");
		scanf("%d", &numero);
	
		if(numero <= 0)
		{
			printf("Numeros naturales!\n");
		}
	}
	while(numero < 0);
	
	return numero;
}



	


