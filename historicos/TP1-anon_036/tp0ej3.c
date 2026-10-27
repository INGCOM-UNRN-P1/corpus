
#include <stdio.h>

int main()
{
    // clang-tidy se queja de que scanf es inseguro
    int a = 0;
    int b = 0;
    printf("primer numero: A = ");
    if (scanf("%d", &a) != 1)
    {
        fprintf(stderr, "Primer entrada inválida.\n");
        return 1;
    }
    printf("segundo numero: A = ");
    if (scanf("%d", &b) != 1)
    {
        fprintf(stderr, "Segunda entrada inválida.\n");
        return 1;
    }
    if (b == 0)
    {
        fprintf(stderr, "Segundo valor no puede ser 0.\n");
        return 1;
    }
    printf(
        "Operador multiplicacion: A*B = %d\n"
        "Operador divisón: A/B = %d\n"
        "Operador resto: A%%B = %d\n",
        a * b, a / b, a % b);
    return 0;
}
