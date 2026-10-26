

#include <stdio.h>
int suma_lenta(int numero, int otro_numero)
{
    int i;
    if (otro_numero >= 0)
    {
        for (i = 0; i < otro_numero; i++)
        {
            numero++;
        }
    return numero;
    }
    else
    {
        for (i = otro_numero; i < 0; i++)
        {
            numero--;
        }
    return numero;
    }
    
}

int main()
{
    int valor_a;
    int valor_b;
    printf("Ingrese el primer número entero: ");
    scanf("%d", &valor_a);
    printf("Ingrese el segundo número entero: ");
    scanf("%d", &valor_b);

    printf("El resultado es: %d\n", suma_lenta(valor_a, valor_b));
    return 0;
}