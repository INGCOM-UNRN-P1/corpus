
#include <stdio.h>

int func_raiz(int numero);
int main(int argc, char *argv[])
{
	int numero;
	int total;
	
	printf("Ingresar numero: ");
	scanf("%d", &numero);
	total = func_raiz(numero);
	return total;
	
}


int func_raiz(int numero)
{
	for (int i = 0; i<numero; i++)
	{
		int resultado;
		resultado = i * i;
		if (resultado == numero)
		{
			printf("%d es raiz de %d \n", i, numero);
			break;
		}
		if (i*i >= numero)
		{
			printf("La parte entera de la raiz de %d, es %d", numero, i-1);
			break;
		}
	}
	return 0;
} 