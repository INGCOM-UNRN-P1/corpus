

#include <stdio.h>
int compara(int numero, int otro_numero)
{
    if (numero < otro_numero)
    {
        return -1;
    }
    else if (otro_numero < numero)
    {
        return 1;
    }   
    else
    {
        return 0;
    }
}

int main()
{
    int valor_a;
    int valor_b;
    printf("Ingrese el primer número: ");
    scanf("%d", &valor_a);
    printf("Ingrese el segundo número: ");
    scanf("%d", &valor_b);

    printf("El resultado es: %d\n", compara(valor_a, valor_b));
    return 0;
}