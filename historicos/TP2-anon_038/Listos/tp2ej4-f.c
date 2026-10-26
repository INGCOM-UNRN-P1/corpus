/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/

#include <stdio.h>

int main()
{
	int n, asteriscos=1; 
	
	printf("Ingrese el tamaño de triangulo rectangulo #");
	scanf("%i",&n);
	
	  	for(int renglon=1;renglon<=n;renglon++)
		{
		  for(int i=1;i<=asteriscos;i++) 
		  	{
		  		printf("*");
			}
			printf("\n");
			asteriscos = asteriscos+1;
		}
	return 0;
}
