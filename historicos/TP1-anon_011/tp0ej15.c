/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
int compara_fechas(char *primera, char *segunda) {
	int caso, i;
	
	caso = 0;
	
	for(i = 2; i >= 0; i--) {
		if(primera[i] < segunda[i]) {
			caso = 1;
			break;
		}
		else if(primera[i] > segunda[i]) {
			caso = -1;
			break;
		}
	}
	return caso;
}

int main(int argc, char *argv[]){
	char primer_fecha[2], segunda_fecha[2];
	
	printf("ingrese el día de la primer fecha: ");
	scanf("%c", &primer_fecha[0]);
	printf("ingrese el mes de la primer fecha: ");
	scanf("%c", &primer_fecha[1]);
	printf("ahora ingrese el año de la primer fecha: ");
	scanf("%c", &primer_fecha[2]);
	
	printf("ingrese el día de la segunda fecha: ");
	scanf("%c", &segunda_fecha[0]);
	printf("ingrese el mes de la segunda fecha: ");
	scanf("%c", &segunda_fecha[1]);
	printf("ahora ingrese el año de la segunda fecha: ");
	scanf("%c", &segunda_fecha[2]);
	
	switch(compara_fechas(primer_fecha[2], segunda_fecha[2]){
		case 1: 
		printf("la primer fecha es anterior a la segunda");
		break;
		case 0:
		printf("la primer fecha y la segunda son iguales");
		break;
		case -1:
		printf("la segunda fecha es anterior a la primera");
		break;
	return 0;
}
