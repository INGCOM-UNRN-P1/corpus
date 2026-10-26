/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_023
*************************/
#include <stdio.h>
 
int main (int argc, char *argv[]) 
{
	int i;
	double kilos, granos = 1, resultado = 0;
	
	for(i=1;i<65;i++)
	{
		if (i == 1)
		{
			printf("Casillero %d: %f grano\n",i, granos);
		}
		else
		{
			printf("Casillero %d: %f granos\n",i, granos);
		}
		resultado = resultado + granos;
		granos = granos * 2;
	}
	kilos = resultado / 20000;
	printf("\nEl rey debera entregarle %f kilos de granos", kilos);
	return 0;
}