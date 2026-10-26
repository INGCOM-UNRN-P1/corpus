/**
Ingenieria en Computación - UNRN Andina
Programación 1
anon_042 de GitHub
**/
#include <stdio.h>
int asteriscos_fila(int asteriscos);
int asteriscos_cuadra(int asteriscos_2);
int triangulo_tamaño(int triangulo);
int main(int argc, char *argv[])
{
	unsigned int asteriscos = 0;
	unsigned int resultado;
	unsigned int asteriscos_2 = 0;
	unsigned int resultado2;
	unsigned int triangulo;
	unsigned int resultado3;
	printf("Ingrese la cantidad de asteriscos que quiera para su linea: ");
	scanf("%u", &asteriscos);
	printf("Ingrese la cantidad de asteriscos que quiera para el cuadrado de Altitud: ");
	scanf("%u", &asteriscos_2);
	printf("Ingrese la cantidad de asteriscos que que quiere para el triangulo: ");
	scanf("%u", &triangulo);
	resultado = asteriscos_fila(asteriscos);
	resultado2 = asteriscos_cuadra(asteriscos_2);
	resultado3 = triangulo_tamaño(triangulo);
	return resultado && resultado2 && resultado3;
}
int asteriscos_fila(int asteriscos)
{
	for (int i=0; i<asteriscos; i++)
	{
		printf("* ");
	}
	printf("\n \n");
	return 0;
}
int asteriscos_cuadra(int asteriscos_2)
{
	for(int i=0;i<asteriscos_2;i++)
	{
		for (int j=0; j<asteriscos_2; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
int triangulo_tamaño(int triangulo)
{
	printf("\n");
	for(int i=0;i<=triangulo;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}