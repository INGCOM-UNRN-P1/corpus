

#include <stdio.h>

typedef struct {
	int resto;
	int cociente;
}divlenta_t;

divlenta_t division_lenta(int dividendo, int divisor);
int signo(int dividendo);

int signo(int dividendo)
{
	if (dividendo < 0)
	{
		dividendo = dividendo*(-1);
		return dividendo;
	}
	else
	{
		return dividendo;
	}
}

divlenta_t division_lenta(int dividendo, int divisor)
{
	divlenta_t resultado;
	int cociente = 0;
	int dividendo_signo = signo(dividendo);
	
	if (divisor < 0)
	{
		while (dividendo_signo >= divisor*-1)
		{
			dividendo_signo = dividendo_signo + (divisor);
			cociente++;
		}
	}
	else
	{
		while (dividendo_signo >= divisor)
		{
			dividendo_signo = dividendo_signo - divisor;
			cociente++;
		}
	}
	
	resultado.resto = dividendo_signo;
	
	if (dividendo < 0 && divisor < 0)
	{
		resultado.cociente = cociente;
	}
	else if (dividendo < 0 || divisor < 0)
	{
		resultado.cociente = cociente*(-1);
	}
	else
	{
		resultado.cociente = cociente;
	}
	return resultado;
}


int main()
{
	int numero;
	int otro_numero;
	divlenta_t resultado;
	
	printf("Ingrese el numero que va a dividir: \n");
	scanf("%d", &numero);
	printf("Ingrese el numero que va a ser el divisor: \n");
	scanf("%d", &otro_numero);
	
	resultado = division_lenta(numero, otro_numero);
	printf("Resultado: \n");
	printf("Resto: %d\nCociente: %d \n", resultado.resto, resultado.cociente);
	
	return 0;
}