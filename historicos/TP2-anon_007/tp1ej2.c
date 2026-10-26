/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
TP - 2
GitHub: anon_007
*************************/
#include <stdio.h>
int producto(int  numero, int otro_numero);
long potencia(long numero, long otro_numero);
int main(int argc, char *argv[])
{
	long numero;
	long otro_numero;
	long mostrar;
	printf("Ingrese un numero: ");
	fflush(stdout);
	scanf("%ld", &numero);
	printf("Ingrese otro numero: ");
	fflush(stdout);
	scanf("%ld", &otro_numero);
	mostrar = producto(numero, otro_numero);
	printf("  %ld * %ld = %ld", numero, otro_numero, mostrar);
	mostrar = potencia(numero, otro_numero);
	printf(" y %ld ^ %ld = %ld", numero, otro_numero, mostrar);
}
int producto(int  numero, int otro_numero)
{
	return numero * otro_numero;
}
long potencia(long numero, long otro_numero)
{
    long resultado = numero;
    while (otro_numero > 1)
    {
        resultado = resultado * numero;
        otro_numero--;
    }
    return resultado;
}