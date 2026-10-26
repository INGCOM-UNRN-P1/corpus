/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
@anon_055
*************************/

// TP1 - ej6 - factorial

#include <stdio.h>

int main() {
	
	int n, fact, i;
	fact = 1;
	
	printf ("Indique un numero: ");
	scanf ("%i", &n);
	
	for (i-1 ; i<=n ; i++){
		fact = fact * i;	
	}
	
	printf ("el factorial de %i es %i. \n", n, fact);
	
	system ("pause");
	return 0;
}
