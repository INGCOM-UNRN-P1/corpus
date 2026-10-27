

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero, divisor;
	double resto;
	printf("Este programa le dira si su numero es\n");
	printf("multiplo de 2, 3, 4, 5 o 6.\n");
	printf("Ingrese un numero entero mayor a 100: ");
	scanf("%d", &numero);
	if (numero <= 100)
	{
		printf("El numero ingresado debe ser mayor a 100,\n");
		printf("Vuelva a iniciar el programa.\n");
		return 0;
	}
	divisor = 2;
	while(divisor <= 6)
		{
			resto = numero % divisor;
			if(resto == 0)
			{
				printf("El numero es multiplo de %d: SI\n", divisor);
			}
			else
			{
				printf("El numero es multiplo de %d: NO\n", divisor);
			}
			divisor++;
		}
	return 0;
}