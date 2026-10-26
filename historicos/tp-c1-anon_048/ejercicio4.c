

#include <stdio.h>

int compara(int numero, int otro_numero);
int solicitar_numero();
int definir(int dato);


int main()
{	
	int numero, otro_numero, resultado;
	
	printf("Digite 2 numeros enteros para compararlos\n");
	numero = solicitar_numero();
	otro_numero = solicitar_numero();
	resultado = compara(numero, otro_numero);
	definir(resultado);
	
	return 0;
}


int compara(int numero, int otro_numero)
{
	if(numero < otro_numero)
	{
		return -1;
	}
	else if(numero == otro_numero)
	{
		return 0;	
	}
	else 
	{
		return 1;
	}
}


int solicitar_numero()
{
	int numero;
	printf("Numero: ");
	scanf("%d", &numero);
		
	return numero;
}


int definir(int dato)
{
	if(dato == -1)
	{
		printf("El primer numero es menor al segundo numero\n");
	}
	else if(dato == 0)
	{
		printf("Los numeros son iguales");	
	}
	else 
	{
		printf("El primer numero es mayor al segundo numero\n");
	}
}