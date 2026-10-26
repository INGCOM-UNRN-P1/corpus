/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_027
*************************/

#include <stdio.h>

int main()
{
	unsigned long long int granos = 1;
	int i;

	for (i=1; i<65; i++)
	{
		printf("Casillero %d = %llu \n", i, granos);
		granos = granos * 2;
	}

	return 0;
}