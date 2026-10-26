
#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[])
{
	
	int dividendo;
	int divisor;
	int resultado;
	int resto;

	printf( "\n Ingrese el dividendo: " );
	scanf( "%d", &dividendo );
   
	printf( "\n Ingrese el divisor: " );
	scanf( "%d", &divisor );
   
	resultado = divide_lento(dividendo, divisor);
	resto = resto_lento(dividendo, divisor);
   
	printf("\n Resultado de la division: %d", resultado);
	printf("\n Resto de la division: %d", resto);
}

int divide_lento(int dividendo, int divisor)
{
	
    int signodivisor = 1;
    int signodividendo = 1;
    int cociente = 0;
	int resto = 0;
	
    if (dividendo <0)
	{
		signodivisor = -1;
        dividendo = dividendo * -1;
	}
    if (divisor < 0)
	{
		signodividendo = -1;
        divisor = divisor * -1;
	}
  
  
    while ((dividendo >= divisor) && (divisor != 0))
	{
        dividendo = dividendo -divisor;
        cociente = cociente + 1;
	}
   
   
    cociente = cociente * signodivisor;
    return cociente;
}

int resto_lento(int dividendo, int divisor)
{
	int signodivisor = 1;
    int signodividendo = 1;
    int cociente = 0;
	int resto = 0;
	
    if (dividendo <0)
	{
		signodivisor = -1;
        dividendo = dividendo * -1;
	}
    if (divisor < 0)
	{
		signodividendo = -1;
        divisor = divisor * -1;
	}
  
  
    while ((dividendo >= divisor) && (divisor != 0))
	{
        dividendo = dividendo -divisor;
        cociente = cociente + 1;
	}
   
   
    resto = dividendo * signodividendo;
	return resto;
}
