
#include <stdio.h>
int suma_lenta(int numero, int otronumero);

int main(int argc, char *argv[])
{
	int resultado;
	int numero;
	int otronumero;
	printf("Ingrese su primero numero a sumar: ");
    scanf("%d", &numero);
	printf("Ingrese su segundo numero a sumar: ");
	scanf("%d", &otronumero);
	printf("Se sumaran lentamente %d y %d\n", numero, otronumero);
	resultado = suma_lenta(numero,otronumero);
	printf("El resultado es %d", resultado);
	return 0;
}

int suma_lenta (int numero, int otronumero)
{
    int suma = numero + otronumero;
	while (numero < suma)
	{
		numero = numero + 1;
	}
	while (numero > suma)
	{
		numero = numero - 1;
	}
	if (numero == suma)
		return numero;
	return numero;
}

