/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
@anon_055
*************************/

// TP1 - ej9 - bucle infinito

#include <stdio.h>

int main (){
	
	int n;
	
	do {
	printf ("Ingrese un numero mayor a 100: ");
	scanf ("%i",&n);
	}
	while (n < 100);
	
	printf ("El numero %i es mayor o igual a 100. \n", n);
	
	system ("pause");
	return 0;
}
