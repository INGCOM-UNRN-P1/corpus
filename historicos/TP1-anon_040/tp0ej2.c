/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/

#include <stdio.h>
#include <stddef.h>

int main(int argc, char *argv[]){
	int i;
	int granos = 0;
	int granostot = 1;
	int kg;

	
	for(i = 0; i < 30; i++){
		granos =  granostot + granos;
		granostot = granos;
		printf("%d = %d \n",i, granostot);
	}
	
	kg = granostot / 20000;
	printf("Se deben %d", kg);

	return 0;
}