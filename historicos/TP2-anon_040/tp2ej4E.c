

#include <stdio.h>

int main (int argc, char *argv[]){
	int numero, i , j;
	
	printf("Ingrese numero: ");
	scanf("%d", &numero);
	
	printf("\n");
	
	for(i = 0; i < numero; i++){
		for(j = 0; j < numero; j++){
			printf("* ");
		} 
		printf("\n");
	}
	
	return 0;
}