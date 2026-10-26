/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){
	
	int num_ingresado;
	
	do
	{
		printf("ingrese un numero: ");
		scanf("%d", &num_ingresado);
		if(num_ingresado < 100){
			printf("El numero ingresado es menor a 100\n");
		}
		else if(num_ingresado == 100) {
			printf("El numero ingresado es 100\n");
		}
		else
			printf("El numero ingresado es mayor a 100");
	}
	while(num_ingresado <= 100);	
	return 0;
}