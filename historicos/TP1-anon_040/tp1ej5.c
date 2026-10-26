/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>

int divide_lento(int dividendo, int divisor){
	int contador;
	
	
	while(dividendo > 0){
		dividendo = dividendo - divisor;
		contador++;
	}
	
	return contador;
}

int resto_lento(int dividendo, int divisor){
	int resto;
	
	while(dividendo > 0){
		dividendo = dividendo - divisor;
		resto = dividendo;
	}
	
	return resto;
}

int main(int argc, char *argv[]){
	int num, divi, divd;
	int ResultadoDivision, ResultadoResto;
	
	printf("Ingrese un dividendo: ");
	scanf("%d", &divi);
	
	printf("Ingrese un divisor: ");
	scanf("%d", &divd);
	
	ResultadoDivision = divide_lento(divi, divd);
	ResultadoResto = resto_lento(divi, divd);

	printf("Resultado de la division = %d\n", ResultadoDivision);
	printf("Resultado del resto = %d\n", ResultadoResto);
	
	return 0;
}