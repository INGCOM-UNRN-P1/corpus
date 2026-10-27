
#include <stdio.h>

int es_primo(int numero)
{
    volatile int i, retorno;

    for(i = 2; i < numero; i++)
    {
        if(numero%i == 0 && numero != i)
        {
            retorno = 0;
            break;
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

int main()
{
    volatile int numero;
    
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    printf("El resultado de la verificacion de si es primo, devuelve: %d\n", es_primo(numero));

    return 0;
}
