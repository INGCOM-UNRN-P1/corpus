/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int grano = 1;
	int i = 1;
	unsigned long long int kg = 0;
	unsigned long long int suma_grano = grano;
	for (i=1;i<=64;i++)
	{
		printf("Casillero %d = %llu \n", i, suma_grano);
		if (i >= 64)
		{
			kg = suma_grano / 20000;
			printf("El rey debera entregarle %llu kg \n", kg);
			break;
		}
		suma_grano = suma_grano *2;
	}
	return 0;
}