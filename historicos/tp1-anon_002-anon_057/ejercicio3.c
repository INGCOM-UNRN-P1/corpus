

#include <stdio.h>



#define NEGATIVO -1
#define CERO 0
#define POSITIVO 1


int signo(int numero)
{
    int retorno;
    if (numero < 0)
    {
        retorno = NEGATIVO;
    }
    else if (numero > 0)
    {
        retorno = POSITIVO;
    }
    else
    {
        retorno = CERO;
    }
    return retorno;
}

int main()
{
    int valor = -5;
    int resultado = signo(valor);
    printf("negativo %d => %d\n", valor, resultado);
    
    valor = 0;
    resultado = signo(valor);
    printf("cero %d => %d\n", valor, resultado);
    
    valor = 5;
    resultado = signo(valor);
    printf("positivo %d => %d\n", valor, resultado);
    
    return 0;
}
