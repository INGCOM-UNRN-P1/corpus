/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Numeros primos
Pre-condicion: Se solicita un numero entero 

Post-codicion: Se mostrara si el numero ingresado es primo o no
@anon_028
*************************/


#include <stdio.h>

#define TRUE 1
#define FALSE 0

int es_primo(int numero);

int main()
{	
	int numero, resultado;
	
	printf("Digite un numero para comprobar si es primo o no\n");
	printf("Numero: ");
	scanf("%d", &numero);
	resultado = es_primo(numero);
	if(resultado == 1)
	{
		printf("El numero es primo\n");
	}
	else 
	{
		printf("No es primo\n");
	}
	
	return 0;
}


int es_primo(int numero)
{
	int divisores, i;
	divisores = 0;
	
	for(i = 1; i <= numero ; i ++)
	{
		if(numero % i == 0)
		{
			divisores = divisores + 1;
		}
	}
		
	if(divisores == 2)
	{
		return TRUE;
	}
	
	else 
	{
		return FALSE;
	}
}



