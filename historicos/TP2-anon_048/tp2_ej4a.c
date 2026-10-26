/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
fergim92
*************************/

#include <stdio.h>

int solicitarNumero();
void imprimirAsteriscos(int n);


int main(int argc, char *argv[])
{
    int	n;
	
	printf("Digite un numero entero positivo: ");
	n = solicitarNumero();
	imprimirAsteriscos(n);

	return 0;
}


void imprimirAsteriscos(int n)
{
	int i;
	
	for(i= 0; i < n; i++)
	{
		printf("*");
	}
}


int solicitarNumero()
{
	int n;
	
		do
	{
		scanf("%d", &n);
		if(n < 1)
		{
		printf("Entero positivo!: ");
		}
	}
	while(n < 1);
}
