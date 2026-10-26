/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
@lidianeivete
*************************/

// TP1 - parte 2 - ej.4 - ¿es un numero primo?


#include <stdio.h>

int primo ();

int main () {
	
	int n, res;
	
	printf ("¿Cual numero te gustaría saber si es primo? ");
	scanf ("%i", &n);
	
	res = primo (n);
	
	if (res == 0){
		printf ("%i NO es primo. \n", n);
	}
	else {
		printf ("%i ES primo. \n", n);	
	}
	
	system ("pause");
	return 0;
}

int primo (n){
	
	int i, j, aux;
	for (i = 2 ; i < n ; i++) {
		aux = n % i;
		if (aux == 0){
			j = 1;
		}	
	}
	
/*	while (i < n){
		aux = n % i;
		i++;
		if (aux == 0){
			j = 1; break;
		}
	}
*/	
	
	if (j == 1){
	return 0;
	}
	
	else {
	return 1;
	}
	
}
