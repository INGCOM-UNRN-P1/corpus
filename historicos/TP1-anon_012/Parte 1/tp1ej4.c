
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnteros(int num);
void esMultiplo(int numero, int multiplo);
void limpiar_pantalla();

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	int numero1 = ingresoNumEnteros(0);
	esMultiplo(numero1,2);
	esMultiplo(numero1,3);
	esMultiplo(numero1,4);
	esMultiplo(numero1,5);
	esMultiplo(numero1,6);
}

//Funciones
int ingresoNumEnteros(int num){
	num = 0;
	while (num<101 || !num){
		fflush(stdin);
		printf("\nIngrese un numero entero mayor a 100: A = ");
		fflush(stdout);
		scanf("%d", &num);	
	}
	return num;
}
void esMultiplo(int numero, int multiplo){	
	if (numero%multiplo == 0){
		printf("Es multiplo de %d: SI \n", multiplo);
	}else{
		printf("Es multiplo de %d: NO \n", multiplo);
	}
}
void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");
	 #else
		system("clear");
	#endif
}