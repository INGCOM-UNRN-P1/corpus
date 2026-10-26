/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){
	double casillero,Kg;

int cont;

cont=1;

casillero=1;

Kg=0;


while (cont<=64) {

	printf("Casillero %d=" ,cont);
	printf("%f\n" ,casillero);
	
	cont=cont+1;
	
	if (casillero < 1) {
		casillero=casillero+1;
	}
	else{
		casillero=casillero*2;
	
	}
}

Kg = casillero/2;
Kg=Kg/20000;

printf("\nEl rey debera entregar %f kg" ,Kg);


return 0;
}