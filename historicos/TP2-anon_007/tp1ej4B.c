/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
TP - 2
GitHub: anon_007
*************************/
#define MAX_CADENA 100
#include <stdio.h>
#include <string.h>
char * cuadrado(int numero);
int main(int argc, char *argv[])
{
	int numero = 0;
	while(1)
	{
		printf("Ingrese un numero: ");
		fflush(stdout);
		scanf("%d", &numero);
		if(numero > 0)
			break;
		else
		{
			printf("El numero no puede ser negativo ni 0");
		}
	}
	//char * mostrar = linea(numero);
	//printf("%s", mostrar);
	cuadrado(numero);
}
char * cuadrado(int numero)
{
    char linea_asteriscos[MAX_CADENA];
	for (int j = 0; j < numero; j ++)
	{
		for (int i = 0; i < (numero * 2); i++)
		{
			if (i%2 == 0 || i == 0)
			{
				linea_asteriscos[i] = '*';
			}
			else
			{
				linea_asteriscos[i] = ' ';
			}
		}
		linea_asteriscos[numero * 2] = '\0';
		char * retornar = linea_asteriscos;
		printf("%s\n", retornar);
	}
    return 0;
}