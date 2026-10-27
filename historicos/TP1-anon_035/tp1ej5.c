




#include <stdio.h>

int  divide_lento(int dividendo, int divisor)
{
	int contador = 0;
	
	if (dividendo > 0 && divisor > 0)	
	{
	
		while(dividendo >= divisor)
		{
			contador = contador + 1;
			dividendo = dividendo - divisor;
		}
		
	
	
	}
	else
	{
		printf("Error no se puede dividir por 0");
	}

	
	return contador;
}


int resto_lento(int dividendo, int divisor)
{
	int resto;
	
	resto = dividendo;
	if (dividendo > 0 && divisor > 0)	
	{
	
		while(resto >= divisor)
		{
			resto = resto - divisor;
		}
		
	
	
	}
	else
	{
		printf("Error no se puede dividir por 0");
	}

	
	return resto;
}



int main(int argc, char *argv[])
{
	
    int resultado, numero, otronumero,resto;
	
	printf("Ingrese primer numero \n");
	
	scanf("%d" , &numero);
	
	printf("Ingrese segundo numero \n");
	
	scanf("%d" , &otronumero);
	
	resultado = divide_lento(numero , otronumero);
	
	resto = resto_lento(numero , otronumero);
	
	printf("El cociente es: %d \n\n", resultado);
	
	printf("El resto es: %d \n\n", resto);
	
	
    return 0;
}