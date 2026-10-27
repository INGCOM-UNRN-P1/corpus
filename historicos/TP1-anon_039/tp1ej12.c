
#include <stdio.h>

int comparar(int numero_a, int numero_b);
 
int main(int argc, char *argv[])
{
	unsigned long long int numero_a = 0;
	unsigned long long int numero_b = 0;
	int resultado = 0;
	
	printf("Ingrese el primer numero: ");
	scanf("%llu", &numero_a);
	printf("Ingrese el segundo numero: ");
	scanf("%llu", &numero_b);
	
	resultado = comparar(numero_a, numero_b);
	printf("%d", resultado);
	return 0;
}

int comparar(int numero_a, int numero_b)
{
	if (numero_a != numero_b)
	{
		if (numero_a < numero_b)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}