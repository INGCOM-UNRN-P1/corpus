/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_027
*************************/

#include <stdio.h>

int main ()
{
	int ingreso=0;
	
	while (ingreso <101){
		printf("Ingrese un numero: ");
		scanf("%d", &ingreso);
		
		if (ingreso < 100){
			printf("El numero %d es menor a 100\n", ingreso);
		}
		
	}
	
	printf("El numero es %d es mayor a 100", ingreso);
	
	
	
}