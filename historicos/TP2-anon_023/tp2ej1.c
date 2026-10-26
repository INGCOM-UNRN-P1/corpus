/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_023
*************************/
#include <stdio.h>
#include <stdlib.h>

int raiz(int n)
{	
	int i = 0;
	int res;
	if(n>0)
	{
		do
		{
			i = i +1;
			res = i * i;
		}
		while(n>res);
		return i;
	}
	else
	{
		printf("el numero no es un numero natural");
		return 0;
	}
	
}

int * dosraices(int n, int m)
{

	static int raices[2];
	raices[0] = raiz(n);
	raices[1] = raiz(m);
	
	return raices;
}	

int main(int argc, char *argv[])
{
	int numero1, numero2, numero3, resultado1, *resultado2;
	printf("ingrese un numero: ");
	scanf("%d", &numero1);
	resultado1 = raiz(numero1);
	printf("la parte entera de la raiz cuadrada de %d es %d", numero1, resultado1);
	printf("\ningrese otro numero: ");
	scanf("%d", &numero2);
	printf("ingrese un ultimo numero: ");
	scanf("%d", &numero3);
	resultado2 = dosraices(numero2,numero3);
	printf("las partes enteras de las raices cuadradas de %d y %d son %d y %d respectivamente", numero2, numero3, resultado2[0], resultado2[1]);
	return 0;
} 

