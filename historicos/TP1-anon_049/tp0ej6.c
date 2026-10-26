/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_049
*************************/
#include <stdio.h>
 
int main(){
	int n, factorial, i;
	factorial = 1;
	
	printf("Ingrese el valor de n: ");
	scanf("%d", &n);
	
	for(i=1; i<= n; i++){
		factorial = factorial * i;
	}
	
	printf("\nEl factorial de %d! es: %d", n, factorial);
	return 0;
}