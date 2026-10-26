



#include <stdio.h>
#include <stdlib.h>

int signo(int numero){
	if (numero == 0){
		printf("El numero es igual a 0");
	}
	else if(numero + abs(numero) == 0){
		printf("El numero es negativo");
	}
	else if(numero - numero == 0){
		printf("El numero es positivo");
	}
	return 0;
}

int main()
{
	int numero;
    printf("Ingrese un numero. \n");
	scanf("%d", &numero);
	signo(numero);
	
    return 0;
}