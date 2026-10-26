/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	long int numero;
	
	printf("Ingrese un numero MAYOR a 100 \n");
	scanf("%ld", &numero);
	
	if (numero<100)
		{	
		do
		{
	
		printf("El numero %ld era menor a 100, ingrese un nuevo numero \n", numero);
		scanf("%ld", &numero);
	
		}while(numero<100);
		}
	
		printf("El numero %ld es mayor que 100 \n", numero);
	
	return 0;
}
