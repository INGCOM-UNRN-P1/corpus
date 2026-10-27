

#include <stdio.h>

int compara(int numero, int otronumero);
int solicitar_numero();
int definir(int dato);


int main(int argc, char *argv[])
{	
	int numero, otronumero, resultado;
	
	printf("Digite 2 numeros enteros para compararlos\n");
	numero = solicitar_numero();
	otronumero = solicitar_numero();
	resultado = compara(numero, otronumero);
	definir(resultado);
	
	return 0;
}


int compara(int numero, int otronumero)
{
	if(numero < otronumero)
	{
		return -1;
	}
	else if(numero == otronumero)
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
		printf("El primer numero es menor al segundo numero");
	}
	else if(dato == 0)
	{
		printf("Los numeros son iguales");	
	}
	else 
	{
		printf("El primer numero es mayor al segundo numero");
	}
}
