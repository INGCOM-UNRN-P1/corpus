/**
Ingenieria en Computación - UNRN Andina
Programación 1
anon_042 de GitHub
**/
#include <stdio.h>

int producto(int numero,int numero_dos);
int potencia(int numero,int numero_dos);
int main(int argc, char *argv[])
{
	int numero;
	int numero_dos;
	int resultado;
	printf("Ingresar numero: ");
	scanf("%d", &numero);
	printf("Ingresar segundo numero: ");
	scanf("%d", &numero_dos);
	resultado = producto(numero, numero_dos), potencia(numero, numero_dos);
	return resultado;
	
}

int producto(int numero, int numero_dos)
{
	int temp = 0;
	for(int i=0; i<numero; i++)
	{
		temp =temp + numero_dos;
	}
	printf("%d \n", temp);
	return 0;
}

int potencia(int numero,int numero_dos)
{
	int temp = numero;
	for(int i=1; i<numero_dos; i++)
	{
		temp =temp * numero;
	}
	printf("%d \n", temp);
	return 0;
}