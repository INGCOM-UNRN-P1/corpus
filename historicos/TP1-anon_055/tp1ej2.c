/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
@anon_055
*************************/

// TP1 - ej2 - el ajedrez

#include <stdio.h>

int main (){
	
	int casillero;
	double grano;
	
	grano = 1;
	casillero = 1;
	
	printf ("casillero %i : %f grano \n", casillero, grano);
	
	while (casillero < 64) {
		grano = grano * 2;
		casillero++;
		printf ("casillero %i : %f granos \n", casillero, grano);
    }
	
	grano = grano * 20000;
	printf ("el rey debe entregarle %f kg. \n", grano);
	
	system ("pause");
	return 0;
}
