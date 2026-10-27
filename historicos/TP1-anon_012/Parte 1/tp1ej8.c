
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnterosPositivos(int num);
void limpiar_pantalla();
int fibonacci(int num);

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	int numero1 = ingresoNumEnterosPositivos(0);
	fibonacci(numero1);
}

//Funciones
int ingresoNumEnterosPositivos(int num){
	//num = 0;
	while (num < 101 || !num){
		fflush(stdin);
		printf("\nIngrese un numero entero mayor a 100: n: ");
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

int fibonacci(int num){
	int numAnterior = 0;
	int numActual = 1;
	printf("Los numeros de la sucesion de fibonacci menor a %d son: 0, 1", num);
	while (numActual + numAnterior <= num){
		int numCopia = numActual;
		numActual = numActual + numAnterior;
		numAnterior = numCopia;
		printf(", %d", numActual);
	}
	printf("\n");
}
