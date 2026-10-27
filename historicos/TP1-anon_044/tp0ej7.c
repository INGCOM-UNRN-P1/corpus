
#include <stdio.h>

int main()
{
    volatile int numero;
    volatile int j, i;
    volatile int factorial = 1;

    printf("Ingrese el valor de n:");
    scanf("%d", &numero);

    for(j = numero; j > 0; j--)
    {
        for(i = 1;i <= j; i++)
        {
            factorial *= i;
        }

        printf("El factorial de %d!: %d \n", j, factorial);
        factorial = 1;
    }
    return 0;
}
