/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
void linea_asteriscos(int n){
	int i;
	printf("punto a)\n");
	for(i = 0; i < n; i++) {
		printf("*");
	}
	printf("\n");
}

void cuadrado_asteriscos(int n){
	int i, j;
	
	printf("punto b)\n");
	for(i = 0; i < n; i++) {
		printf("*");
	}
	printf("\n");
	for(j = 0; j < n - 2; j++){	
		for(i = 0; i < n; i++) {
			if(i == 0 || i == n - 1){
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}

	for(i = 0; i < n; i++) {
		printf("*");
	}
	printf("\n");
}
void piramide_asteriscos(int n){
	int i, j, k;
	
	printf("punto c)\n");
	for(k = 1; k <= n; k++){
		for(i = 0; i < k; i++){
			printf("*");
		}
		printf("\n");
	}
}
int main(int argc, char *argv[]){
	int n;

	printf("ingrese el valor de n: ");
	scanf("%d", &n);
	
	linea_asteriscos(n);
	cuadrado_asteriscos(n);
	piramide_asteriscos(n);
	
	return 0;
}
