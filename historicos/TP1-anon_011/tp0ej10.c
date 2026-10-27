
#include <stdio.h>
 
int main(int argc, char *argv[]){
	int dia;
	printf("Dias de la semana\n");
	
	do
	{
		printf("ingrese un numero entre 1 y 7: ");
		scanf("%d", &dia);
		if(dia < 1 || dia > 7) {
			printf("tiene que ingresar un numero entre 1 y 7: \n");
		}
	}
	while(dia < 1 || dia > 7);
	
	switch(dia) {
		case 1:
		printf("hoy es lunes");
		break;
		case 2:
		printf("hoy es martes");
		break;
		case 3:
		printf("hoy es miercoles");
		break;
		case 4:
		printf("hoy es jueves");
		break;
		case 5:
		printf("hoy es viernes");
		break;
		case 6:
		printf("hoy es sabado");
		break;
		case 7:
		printf("hoy es domingo");
		break;
	}
	return 0;
}
