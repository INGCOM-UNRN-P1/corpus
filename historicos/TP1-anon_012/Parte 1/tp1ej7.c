/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Eduardo Alfredo Aguilar - @anon_012
*************************/
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnterosPositivos(int num);
void limpiar_pantalla();
int factorial(int n);
int factorialSucesivo(int n);

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	int numero1 = ingresoNumEnterosPositivos(0);
	int result = factorialSucesivo(numero1);
}

//Funciones
int ingresoNumEnterosPositivos(int num){
	num = 0;
	while (num <= 0 || !num){
		fflush(stdin);
		printf("\nIngrese el valor n: ");
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

int factorial(int n){
	int i = 1;
	double result = 1;
	for (i; i <= n; i++){
		result = result * i;
	}
	printf("El factorial de %d!: %.0f \n", n, result);
}

int factorialSucesivo(int n){
	while(n >= 1){
		factorial(n);
		n = n - 1;
	}
}
