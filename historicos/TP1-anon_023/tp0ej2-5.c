
#include <stdio.h>

int divide_lento(int dividendo, int divisor)
{
	int cociente;
	if ( divisor > 0 )
    {
        cociente = 0;
        while ( dividendo >= divisor )
        {
            dividendo -= divisor;
            cociente++;
        }
		return cociente;
    }
    else
	{
        return -1;
	}
}

int resto_lento(int dividendo, int divisor)
{
	int resto = dividendo;
	if ( divisor > 0 )
    {
        while ( resto >= divisor )
        {
            resto -= divisor;
        }
		return resto;
    }
    else
	{
        return -1;
	}
}

int main(int argc, char *argv[])
{
	int divisor, dividendo, cociente, resto;
	
	printf("ingrese el dividendo: ");
	scanf("%d", &dividendo);
	printf("Ingrese el divisor: ");
	scanf("%d", &divisor);
	
	cociente = divide_lento(dividendo, divisor);
	resto = resto_lento(dividendo, divisor);
	if (cociente == -1 || resto == -1)
	{
		printf("El divisor debe ser mayor a 0");
	}
	else
	{
		printf("\n%d/%d = %d resto: %d", dividendo, divisor, cociente, resto);
	}
	
	return 0;
}
