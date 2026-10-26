/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>

int factorial(int num){
	int cont = 1;
	int res;
	int i;
	
	for(i = 1; i <= num; i++){
   
      cont = cont * i;    
	}    

	return cont;
}


int main(int argc, char *argv[]){
	int num;
	
	printf("Ingrese un numero para el factorial: ");
	scanf("%d", &num);
	
	int factor = factorial(num);
	
	printf("El factorial de %d!: %d", num, factor);
	
	return 0;
}