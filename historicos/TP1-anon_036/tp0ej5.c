
#include <stdio.h>

// Versión triste de std::swap<int> de C++
void swap(int* a, int* b)
{
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int main()
{
    // clang-tidy se queja de que scanf es inseguro
    int a = 0;
    int b = 0;
    printf("primer numero: ");
    if (scanf("%d", &a) != 1)
    {
        fprintf(stderr, "Primer entrada inválida\n");
        return 1;
    }
    printf("segundo numero: ");
    if (scanf("%d", &b) != 1)
    {
        fprintf(stderr, "Segunda entrada inválida\n");
        return 1;
    }
    // Asegurarse que ambos números estén ordenados
    if (b < a)
        swap(&a, &b);
    while (a <= b)
    {
        printf("%d\n", a);
        ++a;
    }
    return 0;
}
