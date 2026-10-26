/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int producto(int x, int y)
{
	int contador = 1, producto = x;
	
	while(y > contador)
	{
	
		producto = producto + x;
		
		contador = contador + 1;
		
		
	}

	return producto;
}

int potencia(int x, int y)
{
	int contador = 1, potencia = x;
	
	while(y > contador)
	{
	
		potencia = potencia * x;
		
		contador = contador + 1;
		
		
	}

	return potencia;
}



int main(int argc, char *argv[])
{
	int numero1, numero2, resultado1, resultado2;
	
	printf("ingrese numero 1\n\n");
	
	scanf("%d", &numero1);
	
	printf("ingrese numero 2\n\n");

	scanf("%d", &numero2);
	
	resultado1 = producto(numero1, numero2);
	
	resultado2 = potencia(numero1, numero2);
	
	printf("producto = %d \n\n", resultado1);
	
	printf("potencia = %d \n\n", resultado2);
}