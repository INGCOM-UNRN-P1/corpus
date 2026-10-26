

#include <stdio.h>

void numero_negativo_positivo(int numero){
	
	if (numero > 0) {
		printf("El numero es positivo");
	} else if (numero < 0){
		printf("El numero es negativo");
	}else if (numero == 0){
		printf("El numero es 0");
	}else{
		printf("El caracter seleccionado no es nu numero.");
	}
}

int main()
{
	int numero;
	
	printf("Escriba un numero: ");
	scanf("%d", &numero);
	
	numero_negativo_positivo(numero);
	
	return 0;	
}

//precondicion: se pide un numero el cual se evalua para ver si es positivo, negativo o 0.
//poscondicion: se devuelve por pantalla si el numero es positivo, negativo o 0.
