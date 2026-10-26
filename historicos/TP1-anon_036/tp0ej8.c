/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_036
*************************/
#include <stdio.h>

int main()
{
    // clang-tidy se queja de que scanf es inseguro
    printf("Ingrese un numero entero mayor a 100: n: ");
    int numero = 0;
    if (scanf("%d", &numero) != 1 || numero < 100)
    {
        fprintf(stderr, "Entrada inválida.\n");
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
            // Detectar overflow y detenerse
            printf("...");
            break;
        }
        printf("%llu, ", resultado);
    }
    putc('\n', stdout);
    return 0;
}
