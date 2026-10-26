/*
3. Números positivos y negativos
Juan Bautista Mangold Moro - 2022
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	float numero = 0;
	
	printf("Escriba un numero:\n");
    
	scanf("%f", &numero);

	if (numero == 0 ){
		printf("Este numero es 0. \n");}
	else if (numero + numero > 0){
		printf("Este numero es positivo. \n");}
	else if (numero + numero < 0) {
		printf("Este numero es negativo. \n");}
	
	return 0;
}

