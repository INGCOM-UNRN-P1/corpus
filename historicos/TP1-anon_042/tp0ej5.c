
#include <stdio.h>

int valor_a;
int valor_b;
int mostrar_numeros(int valor_a, int valor_b)
{
	if (valor_a < valor_b)
	{
		for(valor_a=valor_a;valor_a <= valor_b; valor_a++)
		{
			printf("%d \n", valor_a);
		}
	}
	else
	{
		for(valor_a=valor_a; valor_a>= valor_b; valor_a--)
		{
			printf("%d \n", valor_a);
		}
	}
}

 
int main(int argc, char *argv[])
{
	int resultado;
	printf("Ingresar primer numero: ");
	scanf("%d", &valor_a);
	printf("Ingresar segundo numero: ");
	scanf("%d", &valor_b);
	resultado = mostrar_numeros(valor_a, valor_b);
	return resultado;
}

