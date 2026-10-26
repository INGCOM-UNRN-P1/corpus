

#include <stdio.h>
#define TRUE 1
#define FALSE 0


int convertir_a_positivo(int numero)
{
	if(numero < 0)
	{
		numero = (numero) - (numero) - (numero);
		return numero;
	}
	else
	{
		return numero;
	}
}

int es_multiplo(int numero, int multiplo)
{
	int suma = 0;
	numero = convertir_a_positivo(numero);
	
	if (multiplo < 0)
	{
		while(numero > suma)
		{
			suma = suma + (-multiplo);
		}
	}
	else
	{
		while(numero > suma)
		{
			suma = suma + (multiplo);
		}
	}
	
	if(suma == numero)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	int numero;
	int multiplo;
	int resultado;
	printf("Ingrese un numero entero para saber si es multiplo de otro\nNumero:\n");
	scanf("%d", &numero);
	printf("Multiplo de:\n");
	scanf("%d", &multiplo);
	
	resultado = es_multiplo(numero, multiplo);
	
	if(resultado == 1)
	{
		printf("True\n");
	}
	
	else
	{
		printf("False\n");
	}
	
	return 0;
}

