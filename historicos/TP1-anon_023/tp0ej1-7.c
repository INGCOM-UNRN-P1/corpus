

#include <stdio.h>

int main (int argc, char *argv[]) 
{
	int i, numero, factorial = 1;
	
	printf("Ingrese el valor n: ");
    scanf("%d", &numero);
	
	int factoriales[numero];
	
	for (i = 1; i <= numero; i++){
        factorial = factorial * i;
		factoriales[i] = factorial;
    }
	
	for (i = numero; i >= 1; i--){
		printf("el factorial de %d es: %d\n", i, factoriales[i]);
    }
	
	return 0;
}