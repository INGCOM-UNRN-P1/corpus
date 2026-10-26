/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	unsigned long long int granos = 1;
	unsigned long long int suma_granos = 1;
	int casillero = 1;
	unsigned long long int kilogramos_a_entregar = 0;
	
	for (casillero; casillero <= 64; casillero++)
	{	
		printf("Casillero %d = %llu. \n", casillero, granos);
		
		
		if (casillero == 64)
		{
			
			kilogramos_a_entregar = suma_granos / 20000;
			
			printf("El rey debera entregarle un total de %llu granos que son %llu Kg de granos. \n", suma_granos, kilogramos_a_entregar);
		}
		
		granos = granos * 2;
		suma_granos = suma_granos + granos;
	}
	
	return 0;
	
}