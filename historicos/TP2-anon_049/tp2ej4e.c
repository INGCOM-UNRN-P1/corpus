/************
UNRN-Programacion I
Ing. en Computacion
Prof: Martin Rene Vilugron
Ejercicio 4 e
anon_049
*************/

#include<stdio.h>

void asteriscos(int n);

int main(){
	int n;
	do{
		printf("Ingrese un numero positivo# ");
		scanf("%d", &n);
	
	}while(n<1);
	
	ateriscos(n);
	
	return 0;
}
void asteriscos(int n){
	int i, j;
	
	for(i= 0; i < n; i++){
		for(j= 0; j < n; j++){
			printf("*");
		}
		printf("\n");
	}		
}
