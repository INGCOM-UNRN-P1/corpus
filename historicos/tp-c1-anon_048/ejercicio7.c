

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int es_primo(int numero);
int solicitar_numero();
int definir(int dato);

int main()
{	
	int numero, resultado;
	
	printf("Digite un numero para comprobar si es primo o no\n");
	numero = solicitar_numero();
	resultado = es_primo(numero);
	definir(resultado);
	
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


int definir(int dato)
{
	if(dato == 1)
	{
		printf("El numero es primo\n");
	}
	else 
	{
		printf("No es primo\n");
	}
}


int solicitar_numero()
{
	int numero;
	printf("Numero: ");
	scanf("%d", &numero);
		
	return numero;
}