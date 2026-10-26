/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_042 de GitHub
*************************/
#include <stdio.h>
int operaciones (int numero_a, int numero_b);
int main(int argc, char *argv[])
{
	int numero_a;
	int numero_b;
	int resultado;
	printf("Ingresar el primer numero: ");
	scanf("%d", &numero_a);
	printf("Ingresar el segundo numero: ");
	scanf("%d", &numero_b);
	resultado = operaciones(numero_a, numero_b);
	return resultado;
}

int operaciones(int numero_a, int numero_b)
{	
	int multiplicacion;
	int resto;
	double division;
	double div_a = numero_a;
	double div_b = numero_b;
	multiplicacion = numero_a * numero_b;
	resto = numero_a % numero_b;
	division = div_a / div_b;
	printf("La multiplicacion de los numeros ingresados es: %d \n", multiplicacion);
	printf("El resto de los numero ingresados es: %d \n", resto);
	printf("La division de los numeros ingresados es: %f \n", division);
	
}