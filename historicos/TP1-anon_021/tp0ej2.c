/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{

	int casillero = 0;

	double granos = 0.5;

	double kg = 0; 

	while (casillero < 64)
	{
			casillero = casillero + 1;
		
			granos = granos * 2;
		
			printf("Casillero : %d \n",casillero);
		
			printf("Granos = %f \n \n",granos);
		
	}

	kg = granos / 20000;

	printf("\n En total el Rey pago %fKg ",kg);

	return 0;

}
