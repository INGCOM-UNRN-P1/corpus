/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Eduardo Alfredo Aguilar - @anon_012
*************************/
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnteros(int num);
void limpiar_pantalla();
void numComprendidos(int num1, int num2);

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	int numero1 = ingresoNumEnteros(0);
	int numero2 = ingresoNumEnteros(0);
	limpiar_pantalla();
	printf("primer numero: %d \n",numero1);
	printf("segundo numero: %d \n",numero2);
	numComprendidos(numero1, numero2);
}

//Funciones
int ingresoNumEnteros(int num){
	num = 0;
	while (!num){
		fflush(stdin);
		printf("\nIngrese un numero entero: \n");
		fflush(stdout);
		scanf("%d", &num);	
	}
	return num;
}

void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");
	 #else
		system("clear");
	#endif
}

void numComprendidos(int num1, int num2){
	for (num1; num1 <= num2; num1++){
		printf("%d \n", num1);
	}
}