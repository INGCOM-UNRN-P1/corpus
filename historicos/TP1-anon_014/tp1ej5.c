/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>

int numero1, numero2;

int main(int argc, char *argv[])
{
	printf("Ingreso de la primera posicion: ");
	scanf("%d", &numero1);
	printf("Ingreso de la segunda posicion: ");
	scanf("%d", &numero2);
	
	if (numero1 <= 0 && numero2 <= 0)
	{
		if(numero1 < numero2)
		{
			printf("%d \n",numero1);
			while (numero1 < numero2)
			{
				numero1 = numero1 + 1;
				printf("%d \n", numero1);
			}
		}
		else
		{
			printf("%d \n", numero2);
			while(numero2 < numero1)
			{
				numero2 = numero2 + 1;
				printf("%d \n", numero2);
			}	
		}
	}
	else
	{
		if(numero1 > 0 && numero2 > 0)
		{
			if(numero1 < numero2)
			{
				printf("%d \n", numero2);
				while(numero2 > numero1)
				{
					numero2 = numero2 - 1;
					printf("%d \n", numero2);
				}
			}
			else
			{
				printf("%d \n", numero1);
				while(numero1 > numero2)
				{
					numero1 = numero1 -1;
					printf("%d \n", numero1);
				}									
			}
		}
		else
		{
			if(numero1 > 0 && numero2 < 0)
			{
				printf("%d \n", numero2);
				while(numero2 < numero1);
				{
					numero2 = numero2 + 1;
					printf("%d \n", numero2);
				}
			}
			else
			{
				if(numero1 < 0 && numero2 > 0)
				{
					printf("%d \n", numero1);
					while(numero1 < numero2)
					{
						numero1 = numero1 + 1;
						printf("%d \n", numero1);
					}
				}
			}
		}
	}
}