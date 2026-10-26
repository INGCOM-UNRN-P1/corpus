/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[]){
	int dividendo,divisor,resultado_resto,resultado_division;
	printf("Ingrese el numero a dividir: ");
	scanf("%d", &dividendo);
	printf("Ingrese el numero divisor: ");
	scanf("%d", &divisor);
	resultado_division=divide_lento(dividendo,divisor);
	printf("El Cociente es: %d\n", resultado_division);
	resultado_resto=resto_lento(dividendo,divisor);
	printf("El Resto es: %d\n", resultado_resto);
	return 0;
}
int divide_lento(int dividendo, int divisor){
	int cociente=0;
	while(dividendo>=divisor){
		dividendo=dividendo-divisor;
		cociente++;
	}
	return cociente;
}
int resto_lento(int dividendo, int divisor){
	int resto;
	while(dividendo>=divisor){
		dividendo=dividendo-divisor;
		resto=dividendo;
	}
	return resto;
}