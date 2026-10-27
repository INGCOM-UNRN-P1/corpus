
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero_A = 0;
	int numero_B = 0;
	int mayor = 0;
	int menor = 0;
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &numero_A);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &numero_B);
	
	if (numero_A > numero_B)
	{
		mayor = numero_A;
		menor = numero_B;
	}
	else
	{
		mayor = numero_B;
		menor = numero_A;
	}
	
	printf("Primer numero: %d\nSegundo numero: %d\n", numero_A, numero_B);
	
	for (menor; menor <= mayor; menor++)
	{
		printf("%d\n", menor);
	}
	return 0;
}