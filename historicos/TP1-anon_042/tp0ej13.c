/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_042 de GitHub
*************************/
#include <stdio.h>

int es_primo(int numero);
int main(int argc, char *argv[])
{
    int numero = 0;
    int resultado;
    printf("Ingrese un numero para saber si es primo: ");
    scanf("%d", &numero);
    resultado = es_primo(numero);
    return resultado;
}
int es_primo(int numero)
{
    int contador = 0;
    int i = 0;
    int primo = 1;
    int noprimo = 0;
    int retorno;
    for(i=1 ; i<=numero ; i++)
    {
        if (numero % i == 0)
        {
            contador++;
        }
    }
    if (contador == 2)
    {
        retorno = printf("%d", primo);
        return retorno;
    }
    else
    {
        retorno = printf("%d", noprimo);
        return retorno;
    }
}
