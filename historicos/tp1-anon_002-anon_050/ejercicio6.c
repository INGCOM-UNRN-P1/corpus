

#include <stdio.h>
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

int division_lenta(int dividendo, int divisor)
{
    while (dividendo >= divisor)
    {
        dividendo -= divisor;
    }
    return dividendo;
}

int main()
{
    int dividendo;
    int divisor;

    printf("Ingrese dividendo: ");
    scanf("%d", &dividendo);
    if (dividendo == 0)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    printf("Ingrese divisor: ");
    scanf("%d", &divisor);
    if (divisor < 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    printf("Cociente: %d\n"
           "Resto:    %d\n", 
            cociente_lento(dividendo, divisor), 
            division_lenta(dividendo, divisor));
    return 0;
}