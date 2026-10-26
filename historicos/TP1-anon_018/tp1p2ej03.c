/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

int comparador(); 

int main(int argc, char *argv[])
{
	int num1, num2, res;
	printf("Este programa comparara dos numeros ingresados\n");
	printf("Retorna -1 si el primero es menor que el segundo\n");
	printf("Retorna 0 si son iguales\n");
	printf("Retorna 1 si el primero es mayor que el segundo\n");
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);
	res = comparador(num1, num2, res);
	printf("%d", res);
	return 0;	
}
int comparador(int num1, int num2, int comparacion)

{
	if (num1<num2)
	{
		comparacion = -1;
	}
	else
	{
		if (num1==num2)
		{
			comparacion = 0;
		}
		else
		{
			comparacion = 1;
		}
	}
	return comparacion;
}