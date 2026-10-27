
#include <stdio.h>

#define MAX_INDICE 12

int main()
{
    // clang-tidy se queja de que scanf es inseguro
    printf("Ingrese el valor de n: ");
    int numero = 0;
    if (scanf("%d", &numero) != 1)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    // Evitar overflow
    if (numero < 0 || numero > MAX_INDICE)
    {
        fprintf(stderr, "Número fuera de rango.\n");
        return 1;
    }
    int temporales[MAX_INDICE];
    temporales[0] = 1;
    temporales[1] = 2;
    int producto = 1;
    for (int indice = 2; indice <= numero; ++indice)
    {
        producto *= indice;
        temporales[indice - 1] = producto;
    }
    for (int indice = numero - 1; indice >= 0; --indice)
        printf("El factorial de %2d!: %d\n", indice + 1, temporales[indice]);
    return 0;
}
