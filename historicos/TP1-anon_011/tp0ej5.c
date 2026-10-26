/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){
	int primernum, segundonum;
	
	printf("ingrese el primer numero: \n");
	scanf("%d", &primernum);
	printf("ingrese el segundo numero: \n");
	scanf("%d", &segundonum);
	printf("\n");
	
	if(primernum > segundonum) {
		for(segundonum; segundonum <= primernum; segundonum++) {
			printf("%d \n", segundonum);
		}
	}
	else
		for(primernum; primernum <= segundonum; primernum++) {
			printf("%d \n");
		}
	
	return 0;
}