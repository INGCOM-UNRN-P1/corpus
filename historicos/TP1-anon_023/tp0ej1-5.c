

#include <stdio.h>

int main (int argc, char *argv[]) 
{
	int i, numero, otronumero;
	
	printf("ingrese un numero: ");
	scanf("%d", &numero);
	printf("ingrese otro numero: ");
	scanf("%d", &otronumero);
	for(i=numero;i<=otronumero;i++)
	{
	printf("%d\n", i);
	}
	
	return 0;
}