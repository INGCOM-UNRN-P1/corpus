

#include <stdio.h>


int es_primo(int numero)
{
    int i;
    int restos;

    if(numero < 2)
    {
        return 0;
    }

    for (i = 1;i <= numero; i++)
    {
        if (numero % i == 0)
        {
            restos++;
        }
    }

    if (restos == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int numero;
    int resultado;

    printf("Ingrese un numero entero para saber si es primo o no: \n");
    scanf("%d", &numero);

    resultado = es_primo(numero);

    if (resultado == 1)
    {
        printf("El numero ingresado es primo");
    }
    else
    {
        printf("El numero ingresado no es primo");
    }

    return 0;
}
