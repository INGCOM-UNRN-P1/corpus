
#include <stdio.h>
 
int main(int argc, char *argv[]){

int cont, numeroentero, cont2=1;
unsigned long long int resultado=1;

printf("ingrese su numero entero ");

scanf("%d" ,&numeroentero);

cont=numeroentero;


while (cont>=1){


cont--;


while (cont2<numeroentero)
{
	cont2=cont2+1;
	resultado=resultado*cont2;
	
	
	
	
}

printf("\n El factorial de %d! es: %d \n" ,numeroentero ,resultado);
cont2=1;
resultado=1;
numeroentero=numeroentero-1;
}

return 0;
}