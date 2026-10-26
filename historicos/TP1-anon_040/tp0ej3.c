/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/


#include <stdio.h>

int multiplicacion(int num1, int num2){
	int mult;
	
	mult = num1 * num2;
	
	return mult;
} 

double divicion(int num1, int num2){
	float div;
	div = num1 / num2;
	
	return div;
}

int resto(int num1, int num2){
	int rest;
	rest = num1 % num2;
	
	return rest;
}
 
int main(int argc, char *argv[]){
	int num1, num2, mult, rest;
	double div;
	
	printf("Ingrese numero: ");
	scanf("%d", &num1);
	
	printf("Ingrese numero: ");
	scanf("%d", &num2);
	
	int mult1 = multiplicacion(num1, num2);
	double div1 = divicion(num1, num2);
	int rest1 = resto(num1, num2);
	
	printf("Multiplicacion = %d\n", mult1);
	printf("Divicion = %f\n", div1);
	printf("Resto = %d\n", rest1);
	
	return 0;
}