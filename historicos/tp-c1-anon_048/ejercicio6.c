

#include <stdio.h>

int division_lenta(int dividendo, int divisor);
int cociente_lento(int dividendo, int divisor);

int main()
{	
	int divisor, dividendo, cociente, resto;
	
	printf("Digite 2 numeros enteros para dividirlos\n");
	printf("Dividendo: ");
	scanf("%d", &dividendo);
    do
    {
        printf("Divisor: ");
	    scanf("%d", &divisor);
        if(divisor == 0)
        {
            printf("El divisor no puede ser cero. Reingrese el divisor\n");
        }
    }while (divisor == 0);
	
	cociente = division_lenta(dividendo, divisor);
	resto = cociente_lento(dividendo, divisor);
	printf("Cociente: %d\n", cociente);
	printf("Resto: %d\n", resto);
	
	return 0;
}


int division_lenta(int dividendo, int divisor)
{
	int resultado = 0;
	
    if (dividendo == 0)
    {
        return 0;
    }
    
    if((dividendo < 0) && (divisor < 0))
    {
        dividendo = dividendo * -1;
        divisor = divisor * -1;

        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;
		    resultado = resultado + 1;
	    }
        return resultado;
    }

    else if((dividendo > 0) && (divisor > 0))
    {
        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;
		    resultado = resultado + 1;
	    }
        return resultado;
    }

    else if((dividendo < 0) && (divisor > 0))
    {
        dividendo = dividendo * -1;

        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;
		    resultado = resultado + 1;
	    }
        return resultado * -1;
    }

    else
    {
        divisor = divisor * -1;

        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;
		    resultado = resultado + 1;
	    }
        return resultado * -1;
    }
}


int cociente_lento(int dividendo, int divisor)
{
    if((dividendo < 0) && (divisor > 0))
    {
        dividendo = dividendo * -1;
        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;

	    }
        return dividendo * -1;
    }
    
    else if ((dividendo < 0) && (divisor < 0))
    {
        dividendo = dividendo * -1;
        divisor = divisor * -1;
        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;

	    }
        return dividendo * -1;
    }

    else if ((dividendo > 0) && (divisor < 0))
    {
        divisor = divisor * -1;
        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;

	    }
        return dividendo;
    }

    else
    {
        while(dividendo >= divisor)
	    {
		    dividendo = dividendo - divisor;

	    }
	    return dividendo;
    }	
}