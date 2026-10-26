

#include <stdio.h>
// Pre: dividendo >= 0
// Pre: divisor > 0
// Post: cociente entero
int cociente_lento(int dividendo, int divisor)
{
    int cociente = 0;
    while (dividendo >= divisor)
    {
        dividendo -= divisor;
        ++cociente;
    }
    return cociente;
}

// Pre: dividendo >= 0
// Pre: divisor > 0
// Post: resto entero
int resto_lento(int dividendo, int divisor)
{
    while (dividendo >= divisor)
    {
        dividendo -= divisor;
    }
    return dividendo;
}

int main()
{
    int dividendo = 0;
    int divisor = 0;

    printf("Ingrese dividendo: ");
    if (scanf("%d", &dividendo) != 1 || dividendo < 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    printf("Ingrese divisor: ");
    if (scanf("%d", &divisor) != 1 || divisor < 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    printf("Cociente: %d\n"
           "Resto:    %d\n",
           cociente_lento(dividendo, divisor),
           resto_lento(dividendo, divisor));
    return 0;
}