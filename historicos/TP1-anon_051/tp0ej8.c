
#include <stdio.h>
#define FIBONACCI 50000
int fibonacci(int numero_entero, int numero_menor);
int main(int argc, char *argv[])
{
	int numero_entero = 0;
	int numero_menor = 0;
	int total;
	printf("Ingrese un numero entero mayor a 10: \n");
	scanf("%d", &numero_entero);
	total = fibonacci(numero_entero, numero_menor);
	return total;
}
int fibonacci(int numero_entero, int numero_menor)
{
	int j = 0;
	unsigned long long int contadora[FIBONACCI];
	int numero_1 = 0;
	int numero_2 = 1;
	int suma = 0;
	contadora[0] = numero_1;
	contadora[1] = numero_2;
	numero_menor = numero_entero;
	int i = 0;
	for (i=2;i<=numero_entero;i++)
	{
		suma = numero_1 + numero_2;
		numero_1 = numero_2;
		numero_2 = suma;
		contadora[i] = suma;
	}
	printf("Los numeros de la sucesion de fibonacci menores a %d son: \n", numero_entero);
	for (j=0;j<numero_menor;j++)
	{
		if (contadora[j] < numero_menor)
		{
			printf("%llu,", contadora[j]);
		}
		if (contadora[j] >= numero_menor)
		{
			break;
		}
	}

}