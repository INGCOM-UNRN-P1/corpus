
#include <stdio.h>
int raiz(int numero);
int main(int argc, char *argv[])
{
	int numero;
	int otro_numero;
	int mostrar;
	printf("Ingrese un numero: ");
	fflush(stdout);
	scanf("%d", &numero);
	printf("Ingresa otro numero: ");
	fflush(stdout);
	scanf("%d", &otro_numero);
	mostrar = raiz(numero);
	if (mostrar != numero)
	{
		printf("La raiz cuadrada de %d es: %d y la de %d es: ", numero, mostrar, otro_numero);
		mostrar = raiz(otro_numero);
		if (mostrar != otro_numero)
		{
			printf("%d", mostrar);
		}
		else
		{
			printf("[No existe la raiz cuadrada de %d en los numeros enteros]", otro_numero);
		}
	}
	else
	{
		printf("[No existe la raiz cuadrada de %d en los numeros naturales]", numero);
	}
}
int raiz(int numero)
{
	int i = 0;
	while (i < numero)
	{
		if ((i * i) == numero && i != numero)
		{
			break;
		}
		i++;
	}
	return i;
}