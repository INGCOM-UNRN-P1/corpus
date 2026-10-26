/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>




int main(int argc, char *argv[])
{
	int n, i,j;
	
	printf("ingrese n\n\n");
	
	scanf("%d", &n);
	
	for(j=0; j<n; j++)
	{
		for(i=1; i<n; i++)
		{
			printf("*");
	
		}
		printf("*\n");
	}

	
	return 0;
}