/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int numero;
	int auxiliar_numero;
	int i;
	int j;
	int factorial;
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	auxiliar_numero=numero;
	factorial=1;
	if(auxiliar_numero>0)
	{	for(j=auxiliar_numero;j>0;j--)
		{
			for(i=1;i<=j;i++)
			{
			factorial=factorial*i;
			}
			printf("El factorial de %d!: %d\n",j,factorial);
			factorial=1;
		}
		
		
	}else if(numero==0)
	{
		printf("El factorial de %d!: %d\n",numero,factorial);
	}else
	{
		printf("No existe el factorial para numeros negativos");
	}
	return 0;
}
