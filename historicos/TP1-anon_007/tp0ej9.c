
#include <stdio.h>
int main(int argc, char *argv[])
{
	int numero = 0;
	while (1)
	{
		printf("Ingrese un numero: ");
		fflush(stdout);
		scanf("%d", &numero);
		if (numero > 100)
		{
			printf("El numero es mayor a 100 \n");
			break;
		}
		else
		{
			printf("El numero es menor a 100 \n");
		}
	}
}