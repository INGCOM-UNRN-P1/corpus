
#include <stdio.h>

int linea(int num1);
int cuadrado(int num1);
int triangulo(int num1);

int main(int argc, char *argv[])
{
	int num1;
	int resultado_producto;
	
	
	printf("Ingrese un numero: ");
	scanf("%d", &num1);
	
	printf("\n Linea de largo %d: \n", num1);
	linea(num1);
	
	printf("\n \n Cuadrado de %d x %d: \n", num1, num1);
	cuadrado(num1);
	
	printf("\n \n Triangulo de altura %d: \n", num1);
	triangulo(num1);

}

int linea(int num1)
{
	
	for (int i = 0; i< num1; i++)
	{
		printf(" * ");
	}

}

int cuadrado (int num1)
{
	for (int i = 0; i< num1; i++)
	{
		linea(num1);
		printf("\n");
	}
}

int triangulo(int num1)
{
	for (int i = 1; i <=num1 ; i++)
	{
		linea(i);
		printf("\n");
	}
}