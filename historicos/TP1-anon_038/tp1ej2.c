
#include <stdio.h>

int main(int argc, char *argv[])
{
	int casillero = 1;
	double granos = 1;
	
	while (casillero<64)
		{
		granos = granos + granos;
		casillero++;
		printf("En el casillero %d hay %f granos \n", casillero, granos);
		}
	
	double kilos = granos / 20000;
	
	printf("El rey tendra que pagar %f kg de trigo \n", kilos);
	
	
	
return 0;	
}

