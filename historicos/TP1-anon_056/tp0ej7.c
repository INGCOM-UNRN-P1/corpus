#include <stdio.h>

int main(int argc, char const *argv[])
{
    int factorial;
    int numero;

    printf("Ingrese el valor de n: ");
    scanf("%d", &numero);

    for (int i = numero ; i >= 1; i--)
    {
        factorial = 1;

        for (int j = 1; j <= i; j++)
        {
            factorial = (factorial*j);
        }

        printf("El factorial de %d! : %d\n", i, factorial);
        
    }
    
    
    return 0;
}
