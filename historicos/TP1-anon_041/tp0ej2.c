/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
	int casillero = 1;
	int divisor_kilos = 20000;
	unsigned long long int kilos = 0;
	unsigned long long int granos = 1;
	unsigned long long int suma_de_granos = 1;
	while(casillero <= 64)
	{
		printf("Casillero %d = %llu granos\n", casillero, granos);
		granos = granos+granos;
		suma_de_granos = suma_de_granos + granos;
		casillero = casillero + 1;
	}
	printf("El rey debe entregarle %llu granos por los 64 casilleros. \n", suma_de_granos);
	kilos = suma_de_granos / 20000;
	printf("Suponiendo que en 1kg hay 20000 granos. Tiene que pagar %llu kilos de granos por el juego de ajedrez.", kilos);
	
	return 0;
}