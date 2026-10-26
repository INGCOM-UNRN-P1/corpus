/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>


int main(int argc, char *argv[])
{
	int numero;
	printf("Este programa le idicara el dia al que corresponde el numero ingresado\n");
	printf("Ingrese un numero del 1 al 7: ");
	scanf("%d", &numero);
	switch (numero)
	{
		case 1: 
			printf("1 - Lunes\n");
			break;
		case 2: 
			printf("2 - Martes\n");
			break;
		case 3: 
			printf("3 - Miercoles\n");
			break;
		case 4: 
			printf("4 - Jueves\n");
			break;
		case 5: 
			printf("5 - Viernes\n");
			break;
		case 6: 
			printf("6 - Sabado\n");
			break;
		case 7: 
			printf("7 - Domingo\n");
			break;
		default: 
			printf("El numero no se encuentra en el rando de 1 a 7\n");
	}
	return 0;
}