/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i, numero, factorial = 1;
	
	printf("Ingresa un numero para calcular su factorial: \n");
    scanf("%d", &numero);
	
	for (i = 1; i <= numero; i++){
        factorial = factorial * i;
    }
	
	for (i = numero; i >= 1; i--){
		printf("el factorial de %d es: %d\n", numero, factorial);
		factorial = factorial / numero;
		numero--;
		
    }
	
	return 0;
	
}