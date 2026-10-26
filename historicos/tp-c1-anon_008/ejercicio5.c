

#include <stdio.h>

int main(int argc, char *argv[]) {
	int numero, otro_numero, aux, suma;
	
	printf ("Escriba un numero: ");
	scanf ("%i", &numero);
	
	printf ("Escriba otro numero: ");
	scanf ("%i", &otro_numero);
	
	aux = otro_numero;
	otro_numero = 0;
	
	while (otro_numero < aux ){
		otro_numero++;
		printf (" %i. \n",otro_numero);
		suma = numero + otro_numero;	
	}
	printf ("el resultado es: %i. \n",suma);
	return 0;
}

