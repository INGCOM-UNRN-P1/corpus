/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/
#include <stdio.h>

int RaizCuadrada(int numero){
	float i = 0;
	float resto;
	
	do
	{
		i = i + 0.1;
		resto = i * i ;
	}while (numero >= resto);
	
	return i;
}


int main (int argc, char *argv[]){
	int numero;
	int raiz;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	
	raiz = RaizCuadrada(numero);
	
	printf("La raiz cuadra de %d es: %d", numero, raiz);

	return 0;
}