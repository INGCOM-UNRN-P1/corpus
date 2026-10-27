
#include <stdio.h>

int factorial(int numero);
 
int main(int argc, char *argv[])
{
    int i;
    int entrada;
    int resultado;


    printf("Ingrese el número factorial: \n\t");
    scanf("%d", &entrada);

    if (entrada == 0)
    {
        printf("El factorial de 0! es: 1");
    }

    for(i = entrada; i >= 1; i--)
    {
        resultado = factorial(i);
        printf("El factorial de %d! es: %d \n", i, resultado);
    }

}

int factorial(int numero)
{
    int i;
    int resultado = 1;

    for(i = 1; i <= numero; i++)
    {
        resultado = resultado * i;
    }

    return resultado;
}