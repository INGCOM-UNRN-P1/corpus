

#include <stdio.h>


int compara(int numero, int otro_numero)
{
	int suma = otro_numero + otro_numero;
	numero = numero + otro_numero;
	
	if (numero == suma)
	{
		return 0;
	}
	
	else if (numero < suma)
	{
		return -1;
	}
	
	else
	{
		return 1;
	}
}

int main()
{
	int numero;
	int otro_numero;
	int resultado;
	
	printf("Ingrese el primer numero a comparar: ");
	scanf("%d", &numero);
	
	printf("Ingrese el segundo numero a comparar: ");
	scanf("%d", &otro_numero);
	
	resultado = compara(numero, otro_numero);
	printf("%d", resultado);
	
	return 0;
}