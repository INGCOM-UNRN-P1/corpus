
#include <stdio.h>
 
int divide_lento(int dividendo, int divisor)
	{
	
	
	int cociente = 0;
	
	while (dividendo>=divisor)
		{
		dividendo = dividendo - divisor;
		cociente++;
		printf("%d \n", cociente);
		}
	return cociente;
	
	
	}

int resto_lento(int dividendo, int divisor, int division)
	{
	int resto = dividendo - (divisor * division);
	return resto;
	}


int main(int argc, char *argv[])
{
	int dividendo;
	int divisor;
	
	printf("Ingrese un numero para usar como dividendo \n");
	scanf("%d", &dividendo);

	printf("Ingrese un numero para usar como divisor \n");
	scanf("%d", &divisor);

	int division = divide_lento(dividendo, divisor);
	int resto = resto_lento(dividendo, divisor, division);
	
	printf("El cociente es %d, y el resto es %d \n", division, resto);


	return 0;

}

