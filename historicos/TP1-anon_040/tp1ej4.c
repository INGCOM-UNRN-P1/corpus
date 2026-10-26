/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>

int es_primo(int numero){
	int i;
	int cont = 0;
	
	for(i = numero; i > 0; i--){
		
		if (numero%i == 0){
			cont ++;
		}
	}
	if(cont == 2){
		return 1;
	}else{
		return 0;
	}
}

int main(int argc, char *argv[]){
	int num1, Resultado;
	
	printf("Ingrese un numero: ");
	scanf("%d", &num1);
	
	Resultado = es_primo(num1);
	
	if(Resultado == 1){
		printf("El numero es primo");
	}else{
		printf("El numero no es primo");
	}

	return 0;
}