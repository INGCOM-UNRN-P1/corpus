
#include <stdio.h>

int suma_lenta(int numero, int otronumero);

int main(int argc, char *argv[])
{
    int numero;
    int otronumero;
    int result;

    printf("Ingrese el primer número a sumar: \n\t");
    scanf("%d", &numero);
    printf("Ingrese el segundo número a sumar: \n\t");
    scanf("%d", &otronumero);

    
    result = suma_lenta(numero,otronumero);

    printf("%d", result);

}


int suma_lenta(int numero, int otronumero)
{

    for(int i = 0; i < otronumero; i++)
    {
        numero = numero + 1;
    }

    return numero;

}