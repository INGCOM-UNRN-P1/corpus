/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
TP - 2
GitHub: anon_007
*************************/
#define MAX_CADENA 100
#include <stdio.h>
#include <string.h>
char * triangulo(int numero);
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
	triangulo(numero);
}
char * triangulo(int numero)
{
	for(int i = 0;i <= numero; i++)
	{
		for(int j = 0; j < i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//No supe hacerlo de otra forma