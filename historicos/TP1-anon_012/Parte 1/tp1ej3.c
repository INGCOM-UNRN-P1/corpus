/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Eduardo Alfredo Aguilar - @anon_012
*************************/
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnteros(int num);
int multiplicacionEnteros(int numA, int numB);
double divisionEnteros(double numA, double numB);
int restoDeDosNumeros(int numA, int numB);
void limpiar_pantalla();


//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	int numero1 = ingresoNumEnteros(0);
	int numero2 = ingresoNumEnteros(0);
	int multiplicacion = multiplicacionEnteros(numero1, numero2);
	double division = divisionEnteros(numero1, numero2);
	int resto = restoDeDosNumeros(numero1, numero2);
	limpiar_pantalla();
	printf("Primer numero: A = %d \n", numero1);
	printf("Segundo numero: B = %d \n", numero2);
	printf("Operador multiplicacion: AxB = %d \n", multiplicacion);
	printf("Operador division: A/B = %.1ll \n", division);
	printf("Operador resto: A%B = %d \n", resto);
}

//Funciones
int ingresoNumEnteros(int num){
	while (!num){
		fflush(stdin);
		printf("Introduce un numero \n");
		fflush(stdout);
		scanf("%d", &num);
	}
	return num;
}
int multiplicacionEnteros(int numA, int numB){
	return numA*numB;
}
double divisionEnteros(double numA, double numB){
	return numA/numB;
}
int restoDeDosNumeros(int numA, int numB){
	return numA%numB;
}
void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");
	 #else
		system("clear");
	#endif
}
