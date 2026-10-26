

#include <stdio.h>


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


int division_lenta(int dividendo, int divisor)
{
	int dividendo_signo = signo(dividendo);
	
	if (divisor < 0)
	{
		while (dividendo_signo >= (divisor*-1))
		{
			dividendo_signo = dividendo_signo + (divisor);
		}
	}
	else
	{
		while (dividendo_signo >= divisor)
		{
			dividendo_signo = dividendo_signo - divisor;
		}
	}
	
	return dividendo_signo;
}



int cociente_lento(int dividendo, int divisor)
{
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
	
	if (dividendo < 0 && divisor < 0)
	{
		return cociente;
	}
	else if (dividendo < 0 || divisor < 0)
	{
		return cociente*(-1);
	}
	else
	{
		return cociente;
	}
}


int main()
{
	int numero;
	int otro_numero;
	int division;
	int cociente;
	
	printf("Ingrese el numero que va a dividir: \n");
	scanf("%d", &numero);
	
	printf("Ingrese el numero que va a ser el divisor: \n");
	scanf("%d", &otro_numero);
	
	division = division_lenta(numero, otro_numero);
	
	cociente = cociente_lento(numero, otro_numero);
	
	printf("El resto es %d \n", division);
	printf("El cociente es %d \n", cociente);
	
	return 0;
}