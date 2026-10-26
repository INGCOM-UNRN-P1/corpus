/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){
	int num_factorial, factorial, resultado, mostrar_num_factorial;
	
	printf("ingrese un numero: \n");
	scanf("%d", &num_factorial);
	
	
	resultado = num_factorial;
	mostrar_num_factorial = num_factorial;
	
	for(num_factorial; num_factorial > 1; num_factorial--) {
		resultado = resultado * (num_factorial - 1);
	}
	printf("el factorial de %d! es: %d", mostrar_num_factorial, resultado);
	return 0;
}