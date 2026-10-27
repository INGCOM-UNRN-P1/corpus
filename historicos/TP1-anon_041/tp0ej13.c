
#include <stdio.h>
int es_primo(int numero); 


int main(int argc, char *argv[])
{
	int numero;
	int resultado;
	printf("Ingrese un numero para saber si es primo: ");
	scanf("%d", &numero);
	resultado = es_primo(numero);
	if (resultado == 1)
	{
		printf("Su numero es primo!", resultado);
	}
	else
	{
		printf("Su numero no es primo!", resultado);
	}
	
	return 0;
}


int es_primo(int numero)
{
	if (numero < 2)
	{
        return 0;
	}
	
	if (numero == 2)
	{
		return 1;
	}
	
	for(int i = 2; i <= numero; i++)
	{
        if (numero % i == 0)
		{
            return 0;
		}
	return 1;
	}
}