
#include <stdio.h>

int main()
{
    const int divisores[] = {2, 3, 4, 5, 6};
    const int numero_divisores = sizeof(divisores) / sizeof(int);

    printf("Ingrese un número entero mayor a 100: A = ");
    int entrada = 0;
    if (scanf("%d", &entrada) != 1 || entrada < 100)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    for (int indice = 0; indice < numero_divisores; ++indice)
    {
        const int divisor = divisores[indice];
        printf("Es multiplo de %d: %s\n", divisor, entrada % divisor == 0 ? "SI" : "NO");
    }
    return 0;
}
