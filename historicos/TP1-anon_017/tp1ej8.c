/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int main()

{
	int numero=1;
	int auxiliar;
	int limite;
	int anterior=0;
	printf("ingrese un numero: ");
	scanf("%d",&limite);
	for (int contador=0;contador<limite;contador++)
	{
	printf("%d \n", numero);
	auxiliar=numero;
	numero=anterior + numero;
	anterior=auxiliar;
	}
	
}

 