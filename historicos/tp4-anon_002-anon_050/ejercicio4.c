

#include <stdio.h>

/**
 * La función realiza divisiones lentas con restas sucesivas.
 *  @param dividendo a operar.
 *  @pre int sin signo válido.
 *  @param divisor a operar.
 *  @pre int sin signo válido.
 *  @param cociente resultante de la división.
 *  @pre int sin signo válido.
 *  @param resto resultante de la división.
 *  @pre int sin signo válido.
 */
void division_lenta2(int dividendo, int divisor, int* cociente, int* resto)
{
    *cociente = 0;
    *resto = dividendo;
    while (*resto >= divisor)
    {
        *resto -= divisor;
        *cociente = *cociente + 1;
    }
}

int main()
{
    int num1;
    int num2;
    int cociente;
    int resto;

    printf("Ingrese dividendo: ");
    scanf("%d", &num1);
    if (num1 == 0)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    printf("Ingrese divisor: ");
    scanf("%d", &num2);
    if (num2 < 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }

    division_lenta2(num1, num2, &cociente, &resto);

    printf("Cociente: %d\nResto: %d\n", cociente, resto);

    return 0;
}