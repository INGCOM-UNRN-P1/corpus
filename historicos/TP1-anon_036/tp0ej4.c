/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <stdio.h>

int main()
{
    // clang-tidy se queja de que scanf es inseguro
    const int divisores[] = {2, 3, 4, 5, 6};
    const int numero_divisores = sizeof(divisores) / sizeof(int);

    printf("Ingrese un numero entero mayor a 100: A = ");
    int entrada = 0;
    if (scanf("%d", &entrada) != 1 || entrada < 100)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    for (int indice = 0; indice < numero_divisores; ++indice)
    {
        const int divisor = divisores[indice];
        const char* const resultado = entrada % divisor == 0 ? "SI" : "NO";
        printf("Es multiplo de %d: %s\n", divisor, resultado);
    }
    return 0;
}
