/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>

int contador = 0; 
int numero1 = 0;
int numero2 = 1;

int fibonacci(){	
	numero1 = numero2;
	numero2 = contador;
	contador = numero1 + numero2;
	
	return contador;
}

int main(int argc, char *argv[]){
	int num, i;
	int fibo;
	
	printf("Ingrese un numero entero mayor que 10: ");
	scanf("%d", &num);
	
	if(10 < num){
		printf("Los numeros de la sucesion de fibonacci menor a %d son: ", num);
		while(fibo < num){
			printf("%d ", fibo);
			fibo = fibonacci();
		}
	}else{
		printf("opcion incorrecta, intente de nuevo\n");
	}
	
	return 0;
}