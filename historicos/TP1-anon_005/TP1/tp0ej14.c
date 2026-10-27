
#include <stdio.h>
 
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[])
{
	int num1;
	int num2;
	printf("Ingrese dividendo: \n");
	scanf("%d",&num1);
	printf("Ingrese divisor: \n");
	scanf("%d",&num2);
	int resultado = divide_lento(num1, num2);
	printf("%d/%d. Cociente: %d.\n", num1, num2, resultado);
	int resultado_dos = resto_lento(num1, num2);
	printf("%d/%d. Resto: %d.\n", num1, num2, resultado_dos);
	return 0;
}

int divide_lento(int dividendo, int divisor)
{
	int contador = 0;    
    if (divisor == 0)
	{
		printf("Error. No se puede dividir por 0 \n");	
	} 
    else if((dividendo > 0) && (divisor >0))
	{
		if (dividendo >= divisor)
		{
			while (dividendo >= divisor)
			{
				dividendo = dividendo - divisor;
				contador = contador+1;
			}
		}
	}
	else
	{
		printf("Error. El dividiendo o el divisor es negativo \n");
	}
	return contador;
}

int resto_lento(int dividendo, int divisor)
{
int contador = 0;    
    if (divisor == 0)
	{
		printf("Error. No se puede dividir por 0 \n");	
	} 
    else if((dividendo > 0) && (divisor >0))
	{
		if (dividendo >= divisor)
		{
			while (dividendo >= divisor)
			{
				dividendo = dividendo - divisor;
			}
		}
	}
	else
	{
		printf("Error. El dividiendo o el divisor es negativo \n");
	}
	return dividendo;
}