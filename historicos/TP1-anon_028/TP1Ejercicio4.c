/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_028
*************************/

#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero, i;
	
	do
	{
	printf("Digite un numero mayor a 100: ");
	scanf("%d", &numero);
	}
	while(numero <= 100);
	
	for(i = 2; i <= 6; i++)
	{
		if(numero % i == 0)
		{
			printf("\nEs multiplo de %d: SI", i);
		}
		else
		{
			printf("\nEs multiplo de %d: NO", i);
		}	
	}
	
	return 0;
}