
#include <stdio.h>
int es_primo(int numero);
int main(int argc, char *argv[])
{
	int numero;
	int mostrar;
	printf("Ingrese un numero: ");
	fflush(stdout);
	scanf("%d", &numero);
	mostrar = es_primo(numero);
	printf("La comprobación dió [%d]", mostrar);
}
int es_primo(int numero)
{
	int i;
	if (numero < 2)
	{
		return 0;
	}
	for (i = 2; i < numero; i++)
		if (numero % i == 0)
		{
			return 0;
		}
	return 1;
}