


#include <stdio.h>

int main(int argc, char *argv[]){
	int numero, factorial;
	
	printf("Ingrese un numero: ");
	scanf ("%i", &numero);
	
	factorial = numero;
		
	while (numero > 1)
	{
		numero = numero - 1;
		factorial = factorial * numero;	
	}
 	printf("El factorial es:%i \n",factorial);
}
