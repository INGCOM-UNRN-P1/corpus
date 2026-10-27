
#include <stdio.h>


int main()
{
    volatile int numero, i;
    volatile int factorial = 1;

    printf("Ingrese el valor de n:");
    scanf("%d", &numero);

    for(i = 1;i <= numero; i++)
    {
        factorial *= i;
    }

    printf("El factorial de %d! es: %d\n", numero, factorial);
    return 0;
}
