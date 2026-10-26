/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
@anon_055
*************************/

// TP1 - parte 2 - ej1. dias de la semana

#include <stdio.h>

void semana ();

int main (){
	
	semana ();
	
	system ("pause");
	return 0;
}

void semana (){
	
	int dia;
	
	printf ("Intruduce un numero entre 1 y 7: ");
	scanf ("%i", &dia);
	
	// solo funciona con variables int y char
	switch (dia){
		case 1: printf ("domingo \n"); break;
		case 2: printf ("segunda-feira \n"); break;
		case 3: printf ("terca-feira \n"); break;
		case 4: printf ("quarta-feira \n"); break;
		case 5: printf ("quinta-feira \n"); break;
		case 6: printf ("sexta-feira \n"); break;
		case 7: printf ("sabado \n"); break;
		default: printf ("numero invalido \n");
	}
}
