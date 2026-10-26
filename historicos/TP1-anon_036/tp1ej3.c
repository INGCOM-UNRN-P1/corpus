/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <stdio.h>
#include <assert.h>

int comparar(int numero, int otro_numero)
{
    if (numero < otro_numero)
        return -1;
    else if (otro_numero < numero)
        return 1;
    else
        return 0;
}

int main()
{
    int numero_a = 0;
    int numero_b = 0;

    printf("Ingrese primer numero: ");
    if (scanf("%d", &numero_a) != 1)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    printf("Ingrese segundo número: ");
    if (scanf("%d", &numero_b) != 1)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    printf("Resultado: %d\n", comparar(numero_a, numero_b));
    return 0;
}
