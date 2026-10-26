

#include <stdio.h>
int es_primo(int numero)
{
    int i;
    int trigger = 0;
    for (i = 2; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            trigger = 1;
        }
    }

    if (numero == 1)
    {
        printf("1 no es ni primo ni compuesto\n");
        return 0;
    }
    else
    {
        if (trigger == 0)
            return 1;
        else
            return 0;
    }
}

int main()
{
    int valor;
    int resultado;
    printf("Ingrese un número: ");
    scanf("%d", &valor);
    resultado = es_primo(valor);
    printf("El resultado es: %d\n", resultado);
    return 0;
}