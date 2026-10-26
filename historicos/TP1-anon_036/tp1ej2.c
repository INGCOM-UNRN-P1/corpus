/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <stdio.h>
#include <assert.h>

int suma_lenta(int numero, int otro_numero)
{
    // Confirmar numeros naturales
    assert(numero > 0);
    assert(otro_numero > 0);

    while (otro_numero != 0)
    {
        ++numero;
        --otro_numero;
    }
    return numero;
}

int main()
{
    int numero_a = 0;
    int numero_b = 0;

    printf("Ingrese primer numero: ");
    if (scanf("%d", &numero_a) != 1 || numero_a <= 0)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    printf("Ingrese segundo número: ");
    if (scanf("%d", &numero_b) != 1 || numero_b <= 0)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    printf("Resultado: %d\n", suma_lenta(numero_a, numero_b));
    return 0;
}
