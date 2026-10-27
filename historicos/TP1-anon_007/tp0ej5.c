
#include <stdio.h>
int main(int argc, char *argv[])
{
	int primer_numero = 0;
	int segundo_numero = 0;
	int mayor = 0;
	int menor = 0;
	int i = 0;
	printf("Ingrese un numero: ");
	fflush(stdout);
	scanf("%d", &primer_numero);
	printf("Ingrese otro numero: ");
	fflush(stdout);
	scanf("%d", &segundo_numero);
	if (primer_numero > segundo_numero)
	{
		mayor = primer_numero;
		menor = segundo_numero;
	}
	else
	{
		mayor = segundo_numero;
		menor = primer_numero;
	}
	
	for(i = menor; i <= mayor; i++)
	{
		printf("%d \n", i);
	}
}
