#include <stdio.h>

int main()
{
    int numero = 0;
    

    while (numero<100)
    {
        printf("Ingrese el valor de n mayor a 100: ");
        scanf("%d", &numero);

        if (numero<100)
        {
            printf("El numero es menor a 100.\n");
        }
        else{
            printf("El numero es mayor a 100.\n");
        }
        
    }
    

    return 0;
}