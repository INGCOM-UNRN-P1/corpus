

#include <stdio.h>

typedef struct division
{
    int dividendo;
    int divisor;
    int cociente;
    int resto;
} division_t;


division_t division_lenta(int dividendo, int divisor);

int main()
{
    int dividendo;
    int divisor;
    division_t division1;

    printf("Digite 2 numeros enteros para dividirlos\n");
    printf("Dividendo: ");
    scanf("%d", &dividendo);
    do
    {
        printf("Divisor: ");
        scanf("%d", &divisor);
        if (divisor == 0)
        {
            printf("El divisor no puede ser cero. Reingrese el divisor\n");
        }
    } while (divisor == 0);

    division1 = division_lenta(dividendo, divisor);
    printf("\n");
    printf("Dividendo: %d\n", division1.dividendo);
    printf("Divisor: %d\n", division1.divisor);
    printf("Cociente: %d\n", division1.cociente);
    printf("Resto: %d\n", division1.resto);

    return 0;
}

division_t division_lenta(int dividendo, int divisor)
{
    division_t division;

    division.dividendo = dividendo;
    division.divisor = divisor;
    division.cociente = 0;

    if (division.dividendo == 0)
    {
        division.cociente = 0;
        division.resto = 0;
    }

    else if ((division.dividendo < 0) && (division.divisor < 0))
    {
        division.dividendo = division.dividendo * -1;
        division.divisor = division.divisor * -1;
        division.resto = division.dividendo;

        while (division.resto >= division.divisor)
        {
            division.resto = division.resto - division.divisor;
            division.cociente = division.cociente + 1;
        }
        division.dividendo = division.dividendo * -1;
        division.divisor = division.divisor * -1;
    }

    else if ((division.dividendo > 0) && (division.divisor > 0))
    {
        division.resto = division.dividendo;

        while (division.resto >= division.divisor)
        {
            division.resto = division.resto - division.divisor;
            division.cociente = division.cociente + 1;
        }
    }

    else if ((division.dividendo < 0) && (division.divisor > 0))
    {
        division.dividendo = division.dividendo * -1;
        division.resto = division.dividendo;

        while (division.resto >= division.divisor)
        {
            division.resto = division.resto - division.divisor;
            division.cociente = division.cociente + 1;
        }

        division.dividendo = division.dividendo * -1;
        division.cociente = division.cociente * -1;
    }

    else
    {
        division.divisor = division.divisor * -1;
        division.resto = division.dividendo;

        while (division.resto >= division.divisor)
        {
            division.resto = division.resto - division.divisor;
            division.cociente = division.cociente + 1;
        }
        division.cociente = division.cociente * -1;
        division.divisor = division.divisor * -1;
    }

    return division;
}
