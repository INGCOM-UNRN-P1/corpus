/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
int producto(int n, int m){
	return n * m;
}
int potencia(int n, int m){
	int i, potencia;
	potencia = n;
	
	for(i=1; i<m; i++) {
		potencia = potencia * n;
	}
	return potencia;
}
int main(int argc, char *argv[]){
	int n, m;
	
	do{
		printf("ingrese un numero(tiene que ser mayor a 0): ");
		scanf("%d", &n);
		printf("ahora ingrese otro numero mayor a 0: ");
		scanf("%d", &m);
		if(n <= 0 || m <= 0){
			printf("tiene que ingresar un numero mayor a 0\n");
		}
	}while(n <= 0 || m <= 0);
	
	printf("el producto de n * m es de: %d\n", producto(n, m));
	printf("la potencia de n^m es de: %d", potencia(n, m));
	
	
	
	return 0;
}
