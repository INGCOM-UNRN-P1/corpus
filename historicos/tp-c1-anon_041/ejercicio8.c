

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SIZE 50


char reemplazar_mayusculas(char texto[SIZE], int capacidad)
{
	int i;
	
	for (i = 0;i < capacidad; i++)
	{
		if (texto[i] > 64 && texto[i] < 91)
		{
			texto[i] = texto[i] + 32;
		}
	}
	
	return texto[SIZE];
}


int es_palindromo(char texto[SIZE])
{
	int i;
	int capacidad = 0;
	int palindromo;
	int espacios = 0;
	int contador = 0;
	
	for (i = 0 ;texto[i] != '\0'; i++)
	{
		capacidad++;
	}
	
	for (i=0;i < capacidad; i++)
	{
		if (texto[i] != ' ')
		{
			texto[contador++] = texto[i];
		}
		else
		{
			espacios++;
		}
	}
	
	capacidad = capacidad - espacios;	
	texto[capacidad] = reemplazar_mayusculas(texto, capacidad);
	
	for (i = 0 ;i < capacidad; i++)
	{
		if (texto[i] == texto[capacidad-2])
		{
			palindromo++;
		}
		else
		{
			return 0;
		}
		capacidad--;
	}
	
	return 1;
}

int main()
{
	char texto_entrada[10000];
	int resultado;
	int capacidad = 0;
	int i;
	printf("Ingrese una palabra o una frase para saber si se trata de un palindromo (max. 50 caracteres): \n");
	fgets(texto_entrada, 10000, stdin);
	
	for (i = 0;texto_entrada[i] != '\0'; i++)
	{
		capacidad++;
	}
	
	if(capacidad > SIZE)
	{
		printf("La palabra o frase es mayor a 50 caracteres\n");
		return 0;
	}
	else
	{
		resultado = es_palindromo(texto_entrada);
	}

	if(resultado == 1)
	{
		printf("Es palindromo\n");
	}
	else
	{
		printf("No es palindromo\n");
	}
	
	return 0;
}