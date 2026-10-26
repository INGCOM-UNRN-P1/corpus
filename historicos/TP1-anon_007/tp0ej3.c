/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
	int primer_numero = 0;
	int segundo_numero = 0;
	int multiplicacion = 0;
	int division = 0;
	int resto = 0;
	scanf("%d", &primer_numero);
	scanf("%d", &segundo_numero);
	multiplicacion = primer_numero * segundo_numero;
	division = primer_numero / segundo_numero;
	resto = primer_numero % segundo_numero;
	printf("El resultado de %d * %d es: %d \n", primer_numero, segundo_numero, multiplicacion);
	printf("El resultado de %d / %d es: %d \n", primer_numero, segundo_numero, division);
	printf("El resultado de %d %% %d es: %d \n", primer_numero, segundo_numero, resto );
}