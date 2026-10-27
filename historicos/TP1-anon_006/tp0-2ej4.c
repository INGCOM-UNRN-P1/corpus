



#include <stdio.h>

int EsPrimo(int numero);
 
int main () 
{
	int numero;
	
	int resultado;
	
	printf("\n");
    printf("\nIngrese un numero para verificar que sea primo: ");
	scanf("%d", &numero);
	printf("\n1 = Primo");
	printf("\n0 = No es Primo");
	
	resultado = EsPrimo(numero);
	printf("\nResultado: %d", resultado);
	printf("\n");
}

int EsPrimo(int numero)
{
	int resultado;
	int divisores = 0;
	
	for(int i=1; i<numero+1; i++)
	{
		if(numero % i == 0)
			divisores += 1;
	}
	
	if(divisores == 2)
	{
		resultado = 1;
	}
	else
	{
		resultado = 0;
	}
	
	return resultado;
}