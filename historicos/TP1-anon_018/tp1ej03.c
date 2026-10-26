/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, numero2;
	int multiplicacion, division, resto;
	printf("Este programa le pedira 2 numeros enteros. \n");
	printf("Ingrese el primer numero: \n");
	scanf("%d", &numero1);
	printf("Ingrese el segundo numero: \n");
	scanf("%d", &numero2);
	printf("Los numeros son:\nA = %d ---- B = %d \n", numero1, numero2);
	multiplicacion = numero1 * numero2;
	division = numero1 / numero2;
	resto = numero1 % numero2;
	printf("A * B = %d \n", multiplicacion);
	printf("A / B = %d \n", division);
	printf("A % B = %d \n", resto);
	return 0;
}