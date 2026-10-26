/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

int suma_lenta(); 

int main(int argc, char *argv[])
{
	int num1, num2, res;
	printf("Este programa realizara una suma lenta de lo ingresado e imprimira el resultado\n");
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);
	res = suma_lenta(num1, num2, res);
	printf("La sume entre %d y %d es: %d\n", num1, num2, res);
	
}
int suma_lenta(int num1, int num2,int r)
{
	int i;
	if (num1 == 0 || num2 == 0)
	{
		r = num1 + num2;
		return r;
	}
	if (num2 < 0)
	{
		for (i=0;i>num2;i--)
		{
			num1--;
		}
		r = num1;
		return r;
	}
	for (i=0;i<num2;i++)
	{
		num1++;
	}
	r = num1;
	return r;
}