/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int compara(int numero, int otronumero)
{
    if(numero<otronumero)
	{
		return -1;
	}else if(numero==otronumero)
	{
		return 0;
	}else
	{
		return 1;
	}
	return otronumero;
}
int main(int argc, char *argv[])
{	
	int numero1;
	int numero2;
	int resultadocomparacion;
	printf("Ingresa un numero: ");
	scanf("%d", &numero1);
    printf("Ingrese otro numero: ");
	scanf("%d", &numero2);
	resultadocomparacion = compara(numero1,numero2);
	switch(resultadocomparacion)
	{
		case -1:
			printf("\nEl resultado de la comparacion es %d el primero es menor que el segundo",resultadocomparacion);
			break;
		case 0:
			printf("\nEl resultado de la comparacion es %d son iguales",resultadocomparacion);
			break;
		case 1:
			printf("\nEl resultado de la comparacion es %d el primero es mayor que el segundo",resultadocomparacion);
			break;
	}  
	return 0;
}
