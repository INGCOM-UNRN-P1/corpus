/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/

#include <stdio.h>

int raiz(int numero);


int main()
{
	int numero;
	int resultado;
	printf("ingrese un numero mayor a 0: ");
	scanf("%d",&numero);
	
	resultado=raiz(numero);
	printf("la raiz es: %d", resultado);
	
}

int raiz(int numero)
{
	int contador=1;
	int resultado;
	
	while (contador<numero)
	{
		contador +=1;
		if(contador*contador<=numero)
		{
		 resultado=contador;
		}
		else
		{	
			;
		}
	}
	return resultado;
}