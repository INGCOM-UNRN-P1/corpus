/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_022
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int cantidad, contador,anterior= 0, actual= 1, resul;
	printf("Ingrese la cantidad de numeros a mostar");
	scanf("%d\n",cantidad);
	print("0,1, ");
	for (contador=0; contador<cantidad-2; contador++){
		resul= anterior+actual;
		printf("%d, ", resul);
		anterior=actual;
		actual=resul;
	}
	return 0;
}