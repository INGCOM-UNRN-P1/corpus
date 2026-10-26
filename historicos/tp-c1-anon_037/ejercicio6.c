

#include <stdio.h>

int division_lenta(int dividendo, int divisor);


int resto_lento(int dividendo, int divisor);



int main()

{
    int numero;
    int otro_numero;
    int cociente;
    int resto;

    printf("Ingrese el dividendo -> ");
    scanf("%d", &numero);

    printf("Ingrese el divisor -> ");
    scanf("%d", &otro_numero);
    
    printf("\nEl cociente es: ");
    cociente = division_lenta(numero, otro_numero);
    printf("%d", cociente);

    printf("\nEl resto es: ");
    cociente = resto_lento(numero, otro_numero);
    printf("%d", cociente);

    return 0;
}


int division_lenta(int dividendo, int divisor)
{
    int aux = divisor;
    int cociente = 0;

    while (dividendo>divisor)
     {
        dividendo = dividendo - divisor;
        cociente++;
    }
    return cociente;
}


int resto_lento(int dividendo, int divisor)
{
    int aux = divisor;
    int resto;

    while (dividendo>divisor)
     {
        dividendo = dividendo - divisor;
    }
    resto = dividendo;
    return resto;
}



