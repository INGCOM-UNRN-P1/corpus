/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int primer_numero;
	int segundo_numero;
	printf("Ingrese dos numeros enteros para obtener la  multiplicacion, division y resto entre si!\n");
	printf("Su primer numero: ");
	scanf("%d", &primer_numero);
	printf("Su segundo numero: ");
	scanf("%d", &segundo_numero);
	int multiplicacion = primer_numero * segundo_numero;
	int division = primer_numero / segundo_numero;
	int resto = primer_numero % segundo_numero;
	printf("Multiplicacion: %d \nDivision: %d \nResto: %d", multiplicacion, division, resto);
	
	return 0;
}