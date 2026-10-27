
#include <stdio.h>
int sumalenta(int numero, int numero_b, int resultado);
int main(int argc, char *argv[])
{
	int numero = 0;
	int numero_b = 0;
	int resultado;
	int total;
	printf("Ingrese un numero entero:");
	scanf("%d", &numero);
	printf("Ingrese otro numero entero:");
	scanf("%d", &numero_b);
	total = sumalenta(numero, numero_b, resultado);
	return total;		
}
int sumalenta(int numero, int numero_b, int resultado)
{
	resultado = numero + numero_b;
	while (numero <= resultado)
	{
		printf("%d \n", numero);
		numero = numero + 1;
	}
}