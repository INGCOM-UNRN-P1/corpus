

#include <stdio.h>

int suma_lenta(int numero, int otronumero);

int main()
{
	int numero;
	int otronumero;
	int res;
	
	printf("Ingrese dos numeros naturales para ser utilizados en suma lenta\n");
	
	printf("--> ");
	scanf("%d", &numero);
	
	printf("--> ");
	scanf("%d", &otronumero);
	
	if (numero < 0 || otronumero < 0)
	{
		printf("Incorrecto.");
	}
	
	else
	{
		res = suma_lenta(numero, otronumero);	
		printf("El resultado es : %d", res);
	}
}

int suma_lenta(int numero, int otronumero)
{
	int i;
	int res;
	
	for (i = 0; i < otronumero; i++)
	{
		numero += 1;
	}
	res = numero;

	return res;
}	