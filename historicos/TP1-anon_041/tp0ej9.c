/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero;
	printf("Ingrese un numero mayor a 100: ");
	scanf("%d", &numero);
	while (numero < 100)
	{	
		printf("Usted ingreso un numero menor a 100, vuelva a intentarlo: ", numero);
		scanf("%d", &numero);
	}
	printf("Su numero %d es mayor a 100!", numero);

	return 0;
}