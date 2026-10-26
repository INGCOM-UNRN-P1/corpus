/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>
int n,j,i;

int main(int argc, char *argv[])
{
	do 
	{
		printf("Ingrese un numero entero mayor a 100: ");
		scanf("%d", &n);	
		
		if (n >= 100)
		{
			for(i=1;i<=6;i++)
			{
				if (n % i == 0)
				{
					printf("Es multiplo de %d", i);
					printf(": SI \n");
				}
				else
				{
					printf("Es multiplo de %d", i);
					printf(": NO \n");
				}
			}
			j = 0;
		}
		else
		{
			printf("Ingreso Incorrecto >.< \n");
			j = 1;
		}
	}
	while(j);
}