
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    printf("Primer número: A = ");
    scanf("%d", &a);
    printf("Segundo número: A = ");
    scanf("%d", &b);
    if (b == 0)
    {
        printf("Segundo valor no puede ser 0.\n");
        return 1;
    }
    printf(
        "Operador multiplicacion: A*B = %d\n"
        "Operador divisón: A/B = %d\n"
        "Operador resto: A%%B = %d\n",
        a * b, a / b, a % b);
    return 0;
}