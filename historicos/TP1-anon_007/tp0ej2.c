/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
**************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
	unsigned long long int granos_guardado;
	int casilla = 1;
	double granos = 1;
	double kilos;
	while (casilla <= 64)
	{
		granos_guardado = granos;
		printf("Casillero %d Granos %0.llf \n", casilla, granos);
		granos = granos + granos_guardado;
		casilla++;
	}
	kilos = (granos_guardado / 20000);
	printf("El rey deberá pagar %.0llf kilos.\n", kilos);
	return 0;
}