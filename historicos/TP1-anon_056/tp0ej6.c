#include <stdio.h>

int main()
{
    int factorial = 1;
    int numero;

    printf("Ingrese el valor de n: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
    {
        factorial = (factorial*i);
    }

    printf("El factorial de %d!: %d\n",numero, factorial);
    
    return 0;
}
