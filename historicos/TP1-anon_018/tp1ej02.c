/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int casillero = 1;
	unsigned long long int granos = 1;
	double kg;
	printf("Casillero %d = %d \n", casillero, granos);
	while (casillero <= 64)
	{
		casillero++;
		granos = granos * 2;
		printf("Casillero %d = %llu \n", casillero ,granos);
		if (casillero == 64)
		{
			kg = granos / 20000;
			printf("El rey debera pagar %f Kg de granos", kg);
			break;
		}
	}
	return 0;
}