
#include <stdio.h>

int compara(int numero_a, int numero_b)
{
    volatile int retorno;

    if(numero_a > numero_b)
    {
        retorno = 1;
    }
    else if (numero_a == numero_b)
    {
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}

int main()
{
    volatile int numero, otro_numero, resultado;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numero);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &otro_numero);

    resultado = compara(numero, otro_numero);

    printf("El resultado es: %d\n\n", resultado);

    return 0;
}
