/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/
#include <stdio.h>

int multiplicacion(int numero1, int numero2){
	int multi;
	int i;
	int numero = 0;
	
	
	for(i = 0; i < numero2; i++){
		numero = numero + numero1;
		multi = numero;
	}
	
	return multi;
}

int potenciacion(int numero1, int numero2){
	int i;
	int numero = numero1;
	int potencia;
	
	for(i = 1; i < numero2; i++){
		numero = numero * numero1;
		potencia = numero;
	}
	
	return potencia;
	
}

int main (int argc, char *argv[]){
	int numero1, numero2;
	int mult;
	int potencia;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero1);
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero2);
	
	mult = multiplicacion(numero1, numero2);
	potencia = potenciacion(numero1, numero2);
	
	printf("La multiplicacion de entre los numeros %d y %d es %d\n", numero1, numero2, mult);
	printf("La potenciacion entre los numeros %d y %d es %d\n", numero1, numero2, potencia);
	
	return 0;
}