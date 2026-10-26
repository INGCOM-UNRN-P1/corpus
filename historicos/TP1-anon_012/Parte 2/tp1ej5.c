/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Eduardo Alfredo Aguilar - @anon_012
*************************/
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumNatural();
void limpiar_pantalla();
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

//Ejecución
int main(int argc, char *argv[]){
    limpiar_pantalla();
		printf("***Restas sucesivas*** \n");
		printf("En el programa a implementar, dar el resultado de la division y del resto con los mismos números.\n");
		int dividendo = ingresoNumNatural();
		int divisor = ingresoNumNatural();
		printf("\nDividendo: %d\n", dividendo);
		printf("Divisor: %d\n", divisor);
		int cociente = divide_lento(dividendo, divisor);
		int resto = resto_lento(dividendo, divisor);
		printf("\nEl cociente de la division es: %d\n", cociente);
		printf("El resto de la division es: %d\n", resto);
}

//Funciones
int ingresoNumNatural(){
		int num=0;
		while (num < 1){
			printf("\nIngrese un numero natural: ");
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

int divide_lento(int dividendo, int divisor){
	int cociente = 0;
	do {
		dividendo = dividendo - divisor;
		cociente = cociente + 1;
	} while(dividendo >= divisor);
	return cociente;
}

int resto_lento(int dividendo, int divisor){
	int resto = dividendo;
	do {
		resto = resto - divisor;
	} while(resto >= divisor);
	return resto;
}
