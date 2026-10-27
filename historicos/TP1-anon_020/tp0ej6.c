

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i, numero, factorial = 1;
	
	printf("Ingresa un numero para calcular su factorial: \n");
    scanf("%d", &numero);
	
	for (i = 1; i <= numero; i++){
        factorial = factorial * i;
    }
	printf("Factorial de %d es: %d\n", numero, factorial);
	return 0;
	
}