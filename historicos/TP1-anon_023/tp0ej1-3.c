/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_023
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int a,b;
	
	printf("ingrese el numero entero A: ");
	scanf("%d", &a);
	printf("ingrese el numero entero B: ");
	scanf("%d", &b);
	
	printf("el numero A es: %d\n", a);
	printf("el numero B es: %d\n", b);
	printf("la multiplicacion es %d\n", a*b);
	printf("la division es %d\n", a/b);
	printf("el resto es %d\n", a%b);
	
	return 0;
}