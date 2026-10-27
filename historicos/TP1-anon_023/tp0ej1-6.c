

#include <stdio.h>

int main (int argc, char *argv[]) 
{
	int i, numero, factorial = 1;
	
	printf("Ingres el valor n: ");
    scanf("%d", &numero);
	
	for (i = 1; i <= numero; i++){
        factorial = factorial * i;
    }
	printf("El factorial de %d! es: %d\n", numero, factorial);
	
	return 0;
}