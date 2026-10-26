/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 5 - Lazos 
*************************/
#include <stdio.h>
 
int lazo(int num1, int num2);

int main(int argc, char *argv[])
{
	int a;
	int b;
	printf("Ingrese entero A \n");
	scanf("%d",&a);
	printf("Ingrese entero B \n");
	scanf("%d",&b);
	printf("Primer numero: %d\n", a);
	printf("Segundo numero: %d\n", b);
	int resultado = lazo(a,b);
	return 0;
}

int lazo(int num1, int num2)
{
	int i;	
	for (i = num1; i < num2+1; i++)
	{
		printf("%d \n",i);
	}
    return 0;
}