

#include <stdio.h>
int main()
{
	int limite = 64;
	int casillero = 1;
	unsigned long long int granos = 1;
	unsigned long long int suma_de_granos = 0;
	unsigned long long int kilos = 0;
	int divisor_a_kilos = 20000;
	
	while (casillero <= limite)
	{
		printf("Casillero %d \n",casillero);
		printf("Granos:%llu \n",granos);
		suma_de_granos = granos + suma_de_granos;
		granos = granos*2;
		casillero = casillero + 1;
	}	
	
	printf("La suma total de granos es %llu \n", suma_de_granos);
	kilos = suma_de_granos/divisor_a_kilos;
	printf("El rey tiene que entregarle %llu kg", kilos);
}