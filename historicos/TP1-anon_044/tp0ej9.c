
#include <stdio.h>

int main()
{
    volatile int numero = 0;
    
    while(numero < 100)
    {
        printf("Ingrese un numero n: ");
        scanf("%d", &numero);
        printf("El numero es ");
        if(numero < 100)
        {
            printf("menor a 100\n\n");
        }
        else
        {
            printf("mayor a 100\n");
        }
    }
    return 0;
}
