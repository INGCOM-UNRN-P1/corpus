

#include <stdio.h>

int main (int argc, char *argv[]){
	int numero, i;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	printf("\n");
	
	for(i = 0; i < numero; i++){
		printf("*");
	}
	printf("\n");

	return 0;
}