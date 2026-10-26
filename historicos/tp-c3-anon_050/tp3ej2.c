

#include <stdio.h>

typedef struct division
{
    int cociente;
    int resto;
} division_t;

/**
 * @brief divide dos enteros.
 * @pre dividendo, todo entero.
 * @pre divisor, todo natural♣.
 * @post resultado.cociente, cualquier entero.
 * @post resultado.resto, cualquier entero.
 * @param dividendo el dividendo de la división.
 * @param divisor el divisor de la división.
 * @result resultado de la división entera, de tipo @ref division_t.
 */
division_t operar(int dividendo, int divisor)
{
    division_t resultado;
    resultado.cociente = 0;
    resultado.resto = 0;
    if (dividendo >= 0)
    {
        while (dividendo >= divisor)
        {
            dividendo -= divisor;
            ++resultado.cociente;
        }

    }
    else
    {
        while (dividendo <= -divisor)
        {
            dividendo += divisor;
            --resultado.cociente;
        }
    }
    resultado.resto = dividendo;
    return resultado;
}

int main()
{
    int dividendo = 0;
    int divisor = 0;
    int scanf_res;
    division_t res;

    printf("Ingrese dividendo: ");
    scanf_res = scanf("%d", &dividendo);
    if (scanf_res != 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }

    printf("Ingrese divisor: ");
    scanf_res = scanf("%d", &divisor);
    if (scanf_res  != 1 || divisor < 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    res = operar(dividendo, divisor);
    printf("Cociente: %d\nResto:    %d\n", res.cociente, res.resto);
    return 0;
}