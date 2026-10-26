/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int numa;
	int numb;
	int multiplicacion;
	double division;
	int resto;
	
	printf("ingrese el numero A: ");
	scanf("%d", &numa);
	printf("ingrese el numero B: ");
	scanf("%d", &numb);
	
	multiplicacion = numa*numb;
	division = (float)numa / numb; 
	resto = numa % numb;
	
	printf("el numero A es: %d\n", numa);
	printf("el numero B es: %d\n", numb);
	printf("la multiplicacion es %d\n", multiplicacion);
	printf("la division es %f\n", division);
	printf("el resto es %d\n", resto);
	return 0;
}