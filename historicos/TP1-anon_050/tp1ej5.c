

#include <stdio.h>

struct pair
{
    int cociente;
    int resto;
};

struct pair division_lenta(int dividendo, int divisor)
{
    int cociente = 0;
    while (dividendo > divisor)
    {
        dividendo -= divisor;
        ++cociente;
    }
    return (struct pair) {
        .cociente = cociente,
        .resto = dividendo,
    };
}

int divide_lento(int dividendo, int divisor)
{
    return division_lenta(dividendo, divisor).cociente;
}

int resto_lento(int dividendo, int divisor)
{
    return division_lenta(dividendo, divisor).resto;
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
           divide_lento(dividendo, divisor),
           resto_lento(dividendo, divisor));
    return 0;
}