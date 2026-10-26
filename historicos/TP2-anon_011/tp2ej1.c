/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
int raiz_n(int n){
	int i;
	
	for(i=0; i<n; i++) {
		if(i * i == n) {
			return i;
			break;
		}
	}
	return 0;
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
	
	if(raiz_n(n) != 0){
		printf("la raiz del primer numero (n) es: %d\n ", raiz_n(n));
	}
	else
		printf("no se puede sacar raiz del numero ingresado\n");
	
	if(raiz_n(m) != 0){
		printf("la raiz del del 2do numero (m) es %d", raiz_n(m));
	}
	else
		printf("no se puede sacar raiz del numero ingresado");
	
	
	
	return 0;
}
