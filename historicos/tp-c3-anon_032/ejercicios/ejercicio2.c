

#include <stdio.h>

typedef struct division
{
    int cociente, resto;
} division_t;

division_t division_lenta(int dividendo, int divisor)
// Precondiciones: Los valores de entrada "dividendo" y "divisor" tiene que ser de tipo entero
// Postcondiciones: Devuelve el cociente y resto resultantes de realizar la división entre el dividendo y el divisor
// Argumentos: Recibe los argumentos "dividendo" y "divisor" las cuales son numero de tipo entero
// Retorno: Esta función retorna una estructura nombrada "division_t" que contiene 2 valores enteros,
// "cociente" y "resto"
{
    division_t division = {0, dividendo};
    if (dividendo > 0 && divisor > 0)
    {
        while (division.resto >= divisor)
        {
            division.resto = division.resto - divisor;
            division.cociente++;
        }
        return division;
    }
    else if (dividendo < 0 && divisor > 0)
    {
        while (division.resto <= divisor * -1)
        {
            division.resto = division.resto + divisor;
            division.cociente--;
        }
        return division;
    }
    else if (dividendo > 0 && divisor < 0)
    {
        while (division.resto >= divisor * -1)
        {
            division.resto = division.resto + divisor;
            division.cociente--;
        }
        return division;
    }
    else if (dividendo < 0 && divisor < 0)
    {
        while (division.resto <= divisor)
        {
            division.resto = division.resto - divisor;
            division.cociente++;
        }
        return division;
    }
}
int main()
{
    int dividendo;
    float dividendoFloat;
    int divisor;
    float divisorFloat;
    division_t division = {.cociente = 0, .resto = 0};
    printf("Ejercicio 2: Division lenta II\n");
    printf("Mediante el ingreso de dos números enteros, indicar el valor del cociente y el resto entre ellos\n\n");
    printf("Introduzca el dividendo: ");
    fflush(stdout);
    scanf("%f", &dividendoFloat);
    dividendo = dividendoFloat;
    if (dividendoFloat - dividendo)
    {
        printf("Error! Debes ingresar un número entero\n");
    }
    else
    {
        printf("Introduzca el divisor: ");
        fflush(stdout);
        scanf("%f", &divisorFloat);
        divisor = divisorFloat;
        if (divisorFloat - divisor)
        {
            printf("Error! Debes ingresar un número entero\n");
        }
        else
        {
            if (divisor != 0)
            {
                division = division_lenta(dividendo, divisor);
                printf("%d / %d = %d\n", dividendo, divisor, division.cociente);
                printf("Resto: %d\n", division.resto);
            }
            else
            {
                printf("Error! El divisor no puede ser 0\n");
            }
        }
    }
    return 0;
}