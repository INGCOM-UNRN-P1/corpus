/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_050
*************************/
#include <stdio.h>

int main()
{
    printf("Ingrese un número entero mayor a 100: ");
    int numero = 0;
    if (scanf("%d", &numero) != 1 || numero < 100)
    {
        printf("Entrada inválida.\n");
        return 1;
    }
    unsigned long long acumulador_a = 0;
    unsigned long long acumulador_b = 1;
    unsigned long long resultado = 0;
    printf("Los numeros de la sucesion de fibonacci menor a %d son: 0, 1, ", numero);
    for (int indice = 0; indice <= numero; ++indice)
    {
        resultado = acumulador_a + acumulador_b;
        acumulador_a = acumulador_b;
        acumulador_b = resultado;

        if (acumulador_a > resultado || acumulador_b > resultado)
        {
            // Prevenir overflows
            printf("etc...");
            break;
        }
        printf("%llu, ", resultado);
    }
    putc('\n', stdout);
    return 0;
}
