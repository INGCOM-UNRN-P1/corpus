/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int numero1;
	int numero2;
	int auxiliar_numero1;
	int auxiliar_numero2;
	int producto;
	int division;
	int resto;
	printf("Ingrese un numero entero:");
	scanf("%d", &numero1);
	printf("Ingrese otro numero entero:");
	scanf("%d", &numero2);
	auxiliar_numero1=numero1;
	auxiliar_numero2=numero2;
	printf("primer numero: numero1 = %d\n",auxiliar_numero1);
	printf("segundo numero: numero2 = %d\n",auxiliar_numero2);
	producto=auxiliar_numero1*auxiliar_numero2;
	division=auxiliar_numero1/auxiliar_numero2;
	resto=auxiliar_numero1%auxiliar_numero2;
	printf("Operador multiplicacion: numero1*numero2 = %d\n",producto);
	printf("Operador division: numero1/numero2 = %d\n",division);
	printf("Operador resto: numero1%%numero2 = %d",resto);	
	return 0;
}
