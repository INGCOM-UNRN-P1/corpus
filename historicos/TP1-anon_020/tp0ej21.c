/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero;
	printf("ingrese un numero del 1 al 7: ");
	scanf("%d", &numero);
	switch(numero)
	{
		case 1:
			printf("lunes");
		break;
		
		case 2:
			printf("martes");
		break;
		
		case 3:
			printf("miercoles");
		break;
		
		case 4:
			printf("jueves");
		break; 
		
		case 5:
			printf("viernes");
		break;
		
		case 6:
			printf("sabado");
		break;
		
		case 7:
			printf("domingo");
		break;
		
		default:
		printf("no ingresaste un numero del 1 al 7");
		
	}
	
	return 0;
}