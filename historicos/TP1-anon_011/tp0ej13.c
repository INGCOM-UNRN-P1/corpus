/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
int es_primo(int numero){
	int i, primo;
	primo = 1;
	
	for(i = 2; i < numero; i++){
		if(numero % i == 0) {
			primo = 0;
		}
	}
	return primo;
}	
int main(int argc, char *argv[]){
	int numero;
	
	printf("Numero primo\n");
	printf("ingrese un numero: ");
	scanf("%d",&numero);
	
	if(es_primo(numero) == 1) {
		printf("es un numero primo");
	}
	else if(es_primo(numero) == 0) {
		printf("no es un numero primo");
	}
	return 0;
}
