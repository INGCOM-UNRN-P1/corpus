
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    printf("Primer número: ");
    if (scanf("%d", &a) != 1)
    {
        printf("Primer entrada inválida\n");
        return 1;
    }
    printf("Segundo número: ");
    if (scanf("%d", &b) != 1)
    {
        printf("Segunda entrada inválida\n");
        return 1;
    }
    // Controlar que estén ordenados
    if (b < a)
    {
        int temporal = a;
        a = b;
        b = temporal;
    }
    while (a <= b)
    {
        printf("%d\n", a);
        ++a;
    }
    return 0;
}
