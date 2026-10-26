/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>

int main (int argc, char *argv[]){
	int numero;
	int i, j, k;
	
	printf("ingrese un numero: ");
	scanf("%d", &numero);
	
	for(i = 0; i <= numero; i++){
		for(j = 0; j <= (i - 1); j++){
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}