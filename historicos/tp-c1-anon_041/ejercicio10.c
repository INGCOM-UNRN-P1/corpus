

#include <stdio.h>


int factorial(int numero)
{
	int i;
	int multiplicacion = 1;
	
	if(numero < 0)
	{
		numero = numero * (-1);
		for (i = 1; i <= numero; i++)
		{
			multiplicacion = multiplicacion * i;
		}
		multiplicacion = multiplicacion * (-1)
		return multiplicacion;
	}
	
	else
	{
		for (i = 1; i <= numero; i++)
		{
			multiplicacion = multiplicacion * i;
		}
	}
	
	return multiplicacion;
}


int main()
{
	int numero;
	int resultado;
	printf("Ingrese un numero para saber su factorial:\n");
	scanf("%d", &numero);
	
	resultado = factorial(numero);
	
	printf("El factorial de %d es: %d\n", numero, resultado);
	
	return 0;
}