/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	double kilos, i;
	double granos = 1;
    
    for(i=1;i<=64;i++)
	{
		
		printf("Casillero %0.lf = %0.lf \n\n", i, granos);
		
		granos = granos * 2;
	
	}
		
	kilos = granos / 20000;
	
	printf("El rey debera entregarle %0.1lf kg \n", kilos);
	
    return 0;
}
