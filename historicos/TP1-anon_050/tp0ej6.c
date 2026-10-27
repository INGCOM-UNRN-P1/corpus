
#include <stdio.h>

int main()
{
    printf("Ingrese el valor de n: ");
    int numero = 0;
    if (scanf("%d", &numero) != 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    // >13 produce overflows
    if (numero < 0 || numero > 12)
    {
        printf("Fuera de rango.\n");
        return 1;
    }
    int resultado = 1;
    for (int indice = 2; indice <= numero; ++indice)
        resultado *= indice;
        
    printf("El factorial de %d!: %d\n", numero, resultado);
    return 0;
}
