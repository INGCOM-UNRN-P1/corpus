
#include <stdio.h>
int compara(int numero, int otronumero);
int main(int argc, char *argv[])
{
    int numero,otronumero,resultado;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("Ingrese otro numero: ");
    scanf("%d", &otronumero);
    resultado = compara(numero,otronumero);
	switch(resultado)
    {
        case -1:
        printf("-1");
        break;

        case 0:
        printf("0");
        break;

        case 1:
        printf("1");
        break;
	}
	return 0;
}
int compara(int numero, int otronumero)
{
    if(numero < otronumero)
    {
        return -1;
	}
	else if(numero < otronumero)
    {
        return 1;
	}
	else
    {
        return 0;
	}
}
