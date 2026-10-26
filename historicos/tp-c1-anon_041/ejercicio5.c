

#include <stdio.h>


int suma_lenta(int numero, int otro_numero)
{
	int i;
	int menor;
	
	if (otro_numero < 0)
	{
		for (i = 0; i > otro_numero; i--)
		{
			numero = numero + (-1);
		}
	}
	else
	{
		for (i = 0; i < otro_numero; i++)
		{
			numero = numero + (1);
		}
	}
	
	return numero;
}

int main()
{
	int numero;
	int otro_numero;
	int resultado;
	
	printf("Ingrese el primer número a sumar: \n");
	scanf("%d", &numero);
	
	printf("Ingrese el segundo número a sumar: \n");
	scanf("%d", &otro_numero);
	
	resultado = suma_lenta(numero, otro_numero);
	
	printf("El resultado es: %d \n", resultado);
	
	return 0;
}