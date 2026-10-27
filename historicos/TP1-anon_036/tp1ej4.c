
#include <stdio.h>

int es_primo(int numero)
{
    // Evitar pensar en numeros negativos tratándolos como positivos
    if (numero < 0)
        numero = -numero;
    // 0 y 1 no son primos
    if (numero == 0 || numero == 1)
        return 0;
    for (int divisor = 2; divisor < numero; ++divisor)
        if (numero % divisor == 0)
            return 0;
    return 1;
}

int main()
{
    int numero = 0;
    printf("Ingrese numero: ");
    if (scanf("%d", &numero) != 1)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    if (es_primo(numero))
        puts("Es primo.");
    else
        puts("No es primo.");
    return 0;
}
