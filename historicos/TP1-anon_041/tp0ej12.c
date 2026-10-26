/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>
int compara(int numero, int otronumero);

int main(int argc, char *argv[])
{
	int numero;
	int otronumero;
	int resultado;
	printf("Ingrese su primer numero a comparar: ");
    scanf("%d", &numero);
    printf("Ingrese su segundo numero a comparar: ");
    scanf("%d", &otronumero);
    resultado = compara(numero,otronumero);
    printf("%d", resultado);
	
	return 0;
}


int compara(int numero, int otronumero)
{
	if (numero < otronumero)
	{
        return -1;
	}
    else if (numero == otronumero)
    {
		return 0;
	}
    else
	{
		return 1;
	}
}