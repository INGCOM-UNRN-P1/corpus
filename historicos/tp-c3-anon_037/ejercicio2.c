

#include <stdio.h>

typedef struct division{
    int cociente;
    int resto;
} division_t;

division_t division_completa(int dividendo, int divisor);

int main()
{
    division_t divission;
    int dividendo;
    int divisor;

    printf("Ingrese el dividendo -> ");
    scanf("%d", &dividendo);
    fflush(stdin);

    printf("Ingrese el divisor -> ");
    scanf("%d", &divisor);
    fflush(stdin);
    
    divission = division_completa(dividendo, divisor);

    printf("\nEl cociente es: ");
    printf("%d", divission.cociente);

    printf("\nEl resto es: ");
    printf("%d", divission.resto);
}

division_t division_completa(int dividendo, int divisor)
{
    division_t resultado;
    resultado.cociente = 0;

    while (dividendo>=divisor)
    {
        dividendo = dividendo - divisor;
        resultado.cociente++;
    }
    resultado.resto = dividendo;

    return resultado;
}