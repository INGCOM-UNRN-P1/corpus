
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnterosPositivos(int num);
void limpiar_pantalla();
void imprimirDias();
int diasDeLaSemana(int dia);

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	imprimirDias();
	int numero1 = ingresoNumEnterosPositivos(0);
	diasDeLaSemana(numero1);
}

//Funciones
int ingresoNumEnterosPositivos(int num){
	while (num < 1 || num > 7){
		printf("\nIngrese un numero entre el 1 y el 7: ");
		fflush(stdout);
		scanf("%d", &num);
		if (num < 1 || num > 7) {
			printf("Numero fuera de rango,\ndebe elegir un valor entre 1 y 7 \n");
		};
	}
}

void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");
	 #else
		system("clear");
	#endif
}

int diasDeLaSemana(int dia){
    switch (dia) {
    	case 1:
			printf("1 - lunes\n");
			break;
			case 2:
			printf("2 - martes\n");
			break;
			case 3:
			printf("3 - miercoles\n");
			break;
			case 4:
			printf("4 - jueves\n");
			break;
			case 5:
			printf("5 - viernes\n");
			break;
			case 6:
			printf("6 - sabado\n");
			break;
			case 7:
			printf("7 - domingo\n");
			break;
			default:
			printf("Numero fuera de rango,\ndebe elegir un valor entre 1 y 7 \n");
    }

}

void imprimirDias(){
    printf("Dias de la semana\n");
		printf("1 - lunes\n2 - martes\n3 - miercoles\n4 - jueves\n5 - viernes\n6 - sabado\n7 - domingo \n");
}
