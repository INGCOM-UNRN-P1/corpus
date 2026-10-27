
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;
	int multiplo;
	int resultado;
	printf("Ingrese un numero entero mayor a 100 para saber si es multiplo de 2, 3, 4, 5 y 6: ");
	scanf("%d", &numero);
	if (numero > 100)
	{
		for (multiplo = 2; multiplo <= 6; multiplo++)
		{
			resultado = numero / multiplo;
			resultado = resultado * multiplo;
			if (resultado == numero)
			{
				printf("Si es multiplo de %d\n", multiplo);
			}
			else
			{
				printf("No es multiplo de %d\n", multiplo);
			}	
		}
	}
	else 
	{
		printf("Usted no ingreso un numero entero mayor a 100!");
	}
	
    return 0;
}