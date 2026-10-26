/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

int divide_lento(); 
int resto_lento(); 

int main(int argc, char *argv[])
{
	int num1, num2, cociente, resto;
	printf("El siguiente programa realiza una division mediante restas sucesivas\n");
	printf("Ingrese un dividendo entero positivo: ");
	scanf("%d", &num1);
	printf("Ingrese un divisor entero positivo: ");
	scanf("%d", &num2);
	if (num1 > 0 && num2 > 0)
	{
		cociente = divide_lento(num1, num2, cociente);
		resto = resto_lento(num1, num2, resto);
		printf("El cociente es: %d y el resto es: %d\n", cociente, resto);
	}
	else
	{
		printf("Ambos numeros deben ser mayores a 0\n");
	}
	return 0;
}
int divide_lento(int num1, int num2, int coc)
{
	int dividendo;
	dividendo = num1;
	coc = 0;
	while (dividendo >= num2)
	{
		dividendo -= num2;
		coc++;
	}
	return coc;
}
int resto_lento(int num1, int num2, int res)
{
	int cociente; 
	res = num1;
	cociente = 0;
	while (res >= num2)
	{
		res -= num2;
		cociente++;
	}
	return res;
}