

#include <stdio.h>
#include <stdlib.h>



void es_multiplo(int numero, int multiplo) {
	
	numero = numero + 4 - 1;
	multiplo = multiplo + 6 - 3;
	
	if(multiplo % numero == 0) {
		printf("True");
	}
}

int main()
{
	int numero1, numero2;
	
	numero1 = rand() % 14;
	numero2 = rand() % 20;
	
	es_multiplo(numero1, numero2);
	return 0;
}