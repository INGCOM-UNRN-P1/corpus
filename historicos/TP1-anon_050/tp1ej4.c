

#include <stdio.h>

int es_primo(int numero)
{
    int i, trigger = 0;
    for (i = 2; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            trigger = 1;
        }
    }

    if (numero == 1)
    {
        printf("1 no es ni primo ni compuesto");
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
    printf("Ingrese un número: ");
    scanf("%d", &valor);

    printf("El resultado es: %d\n", es_primo(valor));
    return 0;
}