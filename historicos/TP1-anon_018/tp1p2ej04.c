/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

int es_primo(); 

int main(int argc, char *argv[])
{
	int num, primo;
	printf("El siguiente programa imprimira 1 si el numero ingresado\n");
	printf("es Primo y 0 si no lo es.\n");
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &num);
	if (num < 0)
	{
		printf("El numero debe ser positivo. \n");
		return 0;
	}
	primo = es_primo(num, primo);
	printf("%d", primo);
	return 0;
}
int es_primo(int num, int res)

{
	int i;
	if (num == 0 || num == 1)
	{
		res = 0;
		return res;
	}
	if (num == 2 || num == 3)
	{
		res = 1;
		return res;
	}	
	for (i=2;i<num;i++)
	{
		if ((num % i) == 0)
		{
			res = 0;
			return res;
		}
	}
	res = 1;
	return res;
}