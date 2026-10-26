/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>


int main(int argc, char *argv[]){
	int opcion;
	
	printf("Ingrese un numero correspondiente a un dia de la semana: ");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1:
			printf("\nLunes\n");
			break;
		case 2:
			printf("\nMartes\n");
			break;
		case 3:
			printf("\nMiercoles\n");
			break;
		case 4:
			printf("\nJueves\n");
			break;
		case 5:
			printf("\nViernes\n");
			break;
		case 6:
			printf("\nSabado\n");
			break;
		case 7:
			printf("\nDomingo\n");
			break;
		default:
			printf("\nLa entrada no corresponde a ningun dia de la semana. Intente de nuevo\n");
	}
	return 0;
}