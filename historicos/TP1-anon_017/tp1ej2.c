
#include <stdio.h>

int main()
{
	int casillero= 1;
	int final=64;
	unsigned long long int granos=1;
	unsigned long long int kilos=0;
	unsigned long long int granostotales=0;

	while (casillero <= final)
	{
	printf("casillero: %d , granos %llu \n",casillero, granos);
	granostotales= granos+granostotales;
	granos= granos*2;
	casillero= casillero+1;
	

	}
	printf("la cantidad total de granos es de: %llu \n",granostotales);
	kilos= granostotales/20000;
	printf("El rey debera entregarle: %llu kilos", kilos);

}

