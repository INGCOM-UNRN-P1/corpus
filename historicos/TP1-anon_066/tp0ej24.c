/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int es_primo(int numero)
{
	int cantidadivisor;
	int i;
	cantidadivisor=0;
	for(i=1;i<=numero;i++)
	{
        if(numero%i==0)
		{ 
		    cantidadivisor=cantidadivisor+1;
		}
	}
	if(cantidadivisor<=2)
	{
		return 1;
	}else{
		return 0;
	}
}
int main(int argc, char *argv[])
{	
	int numero1;
	int esprimo;
	printf("Ingresa un numero: ");
	scanf("%d", &numero1);
	esprimo = es_primo(numero1);
	if(esprimo)
	{
	    printf("\nEl numero ingresado es primo");
	}else{
		printf("\nEl numero ingresado no es primo");
	}
	return 0;
}
