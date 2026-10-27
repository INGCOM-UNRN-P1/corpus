
#include <stdio.h>

int main(int argc, char *argv[])
{
    int primer_numero;
	int segundo_numero;
	int limite;
	printf("Ingrese dos numeros enteros para ver todos su numeros enteros comprendidos entre si!\n");
	printf("Su primer numero: ");
	scanf("%d", &primer_numero);
	printf("Su segundo numero: ");
	scanf("%d", &segundo_numero);
	if (primer_numero < segundo_numero)
	{
		while (primer_numero < segundo_numero+1)
		{
			printf("%d\n", primer_numero);
			primer_numero++;
		}
	}
	else
	{
		while(primer_numero+1 > segundo_numero)
		{
			printf("%d\n", primer_numero);
			primer_numero--;
		}
	}
	
    return 0;
}
