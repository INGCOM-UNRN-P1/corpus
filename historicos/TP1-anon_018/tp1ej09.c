

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero;
	printf("El programa detectara si el numero ingresado es menor o mayor a 100.\n");
	printf("Ingrese un numero entero: ");
	scanf("%d", &numero);
	while (numero < 100)
	{
		printf("El numero %d es menor a 100\nIntente otra vez\n\n", numero);
		printf("Ingrese un numero entero: ");
		scanf("%d", &numero);
	}
	if (numero == 100)
	{
		printf("El numero es 100");
		return 0;
	}
	printf("El numero %d es mayor a 100\n", numero);
	return 0;
}