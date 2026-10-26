/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero = 0;
	int multiplo = 0;
	int i = 2;
	printf("Ingrese un numero entero mayor a 100: #");
	scanf("%d",&numero);
	
	if (numero >= 100)
	{
		for (i; i <=6; i++)
		{
			if (numero%i == 0)
			{
				printf("Es multiplo de %d: SI\n", i);
			}
			else
			{
				printf("Es multiplo de %d: NO\n", i);
			}
		}
	}
	return 0;
}