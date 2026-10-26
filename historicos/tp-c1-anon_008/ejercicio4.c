/*
4. Comparación de números
Juan Bautista Mangold Moro - 2022
Programacion 1 - Ingenieria en computacion
*/


#include <stdio.h>

int main(int argc, char *argv[]){
	int numero, otro_numero, c, k;
	
	printf("Ingrese un numero: ");
	scanf ("%i", &numero);
	
	printf("Ingrese un numero: ");
	scanf ("%i", &otro_numero);
	
	if (numero - otro_numero == 0 ){
		printf("0. \n");}
	else if (numero + 0 > otro_numero + 0){
		printf("1. \n");}
	else if (numero + 0 < otro_numero + 0) {
		printf("-1 \n");} 

}
