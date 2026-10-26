/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>


int suma_lenta(int numero, int otronumero);
int main(int argc, char *argv[])
{
    int numero,otronumero,resultado;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("Ingrese otro numero: ");
    scanf("%d", &otronumero);
    resultado = suma_lenta(numero,otronumero);
    return 0;
}

int suma_lenta(int numero, int otronumero)
{
    int max, min, cont, suma = numero + otronumero;
	if(numero<otronumero)
    {
        max = otronumero;
        min = numero;
	}
	else
    {
        max = numero;
		min = otronumero;
	}
	cont = min;
	while(cont <= suma)
    {
        printf("%d\n", cont);
        cont++;
	}
	return cont;
}
