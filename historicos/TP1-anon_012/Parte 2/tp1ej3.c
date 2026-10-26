/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Eduardo Alfredo Aguilar - @anon_012
*************************/
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNum(int num);
void limpiar_pantalla();
int compara(int numero, int otronumero);

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	printf("***Comparación de números*** \n");
	printf("Retornar -1 si el primero es menor que el segundo\nRetornar 0 si son iguales\nRetornar 1 si el primero es mayor que el segundo\n");
	int numero = ingresoNum(1);
	int otronumero = ingresoNum(1);
	int resultado = compara(numero, otronumero);
	printf("resultado: %d \n", resultado );
}

//Funciones
int ingresoNum(int num){
	printf("\nIngrese un numero: ");
	fflush(stdout);
	scanf("%d", &num);
	return num;
}

void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");
	 #else
		system("clear");
	#endif
}

int compara(int numero, int otronumero){
	if (numero < otronumero){
		return -1;
	}else if(numero == otronumero){
		return 0;
	}else if(numero > otronumero){
		return 1;
	}else{
		printf("El valor ingresado no es un numero");
	};
}
