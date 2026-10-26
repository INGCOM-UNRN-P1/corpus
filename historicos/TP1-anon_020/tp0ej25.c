/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/
#include <stdio.h>

int divide_lento(int dividendo, int divisor)
{
	int cociente, resto;
	if ( dividendo > 0 && divisor > 0 )
    {
        cociente = 0;
        resto = dividendo;

        while ( resto >= divisor )
        {
            resto -= divisor;
            cociente++;
        }

        return cociente;
    }
    else
        return -1;
	
}

int resto_lento(int dividendo, int divisor)
{
	int cociente, resto;
	if ( dividendo > 0 && divisor > 0 )
    {
        cociente = 0;
        resto = dividendo;

        while ( resto >= divisor )
        {
            resto -= divisor;
            cociente++;
        }

        return resto;
    }
    else
        return -1;
}

int main(int argc, char *argv[])
{
	int divisor, dividendo, resultado, resto;
	
	printf("Ingrese el divisor: ");
	scanf("%d", &divisor);
	printf("ingrese el dividendo: ");
	scanf("%d", &dividendo);
	
	resultado = divide_lento(dividendo, divisor);
	resto = resto_lento(dividendo, divisor);
	
	if(resto == -1 || resultado == -1)
	{
		printf("algun numero ingresado fue incorrecto, es decir igual o menor a 0");
	}
	else
	{
		printf(" el resultado de %d div %d es %d y queda %d de resto", dividendo, divisor, resultado, resto);
	}
	
	return 0;
}
