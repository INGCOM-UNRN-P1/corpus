/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{	
	long numero;
	long auxiliar_numero;
	long i;
	double x;
	double y;
	double fibonacci;
	printf("Ingrese un numero entero mayor a 100: ");
	scanf("%d", &numero);
	auxiliar_numero=numero;
	x=0;
	y=1;
	if(auxiliar_numero>100)
	{	
		printf("Los numeros de la sucesion de fibonacci menor a %d son: 0, 1",auxiliar_numero);
		for(i=1;i<auxiliar_numero;i++)
		{
			  fibonacci=x+y;
			  printf(", %.0f",fibonacci);
			  x=y;
			  y=fibonacci;
		}
	}else
	{
		printf("El numero no es mayor que 100");
	}
	return 0;
}
