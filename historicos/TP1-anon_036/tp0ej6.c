
#include <stdio.h>

int main()
{
    printf("Ingrese el valor de n: ");
    int numero = 0;
    if (scanf("%d", &numero) != 1)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    // Evitar overflow cuando se calcula 13!
    if (numero < 0 || numero > 12)
    {
        fprintf(stderr, "Número fuera de rango.\n");
        return 1;
    }
    int resultado = 1;
    for (int indice = 2; indice <= numero; ++indice)
        resultado *= indice;
        
    printf("El factorial de %d!: %d\n", numero, resultado);
    return 0;
}
