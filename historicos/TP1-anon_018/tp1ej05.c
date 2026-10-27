

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, numero2;
	printf("Este programa imprime todos los numeros desde su\n");
	printf("primer numero ingresado hasta el segundo.\n");
	printf("Ingrese el primer Numero: ");
	scanf("%d", &numero1);
	printf("Ingrese el segundo Numero: ");
	scanf("%d", &numero2);
	if (numero1 == numero2)
	{
		printf("%d \n", numero1);
		return 0;
	}
	if (numero1 < numero2)
	{
		while (numero1<=numero2)
		{
			printf("%d \n", numero1);
			numero1++;
		}
		return 0;
	}
	while (numero2<=numero1)
	{
		printf("%d \n", numero2);
		numero2++;
	}
	
	return 0;
}