#include <stdio.h>

int main()
{
    int numero;
    int fib1 = 0;
    int fib2 = 1;
    int fibonacci;

    printf("Ingrese el valor de n mayor a 100: ");
    scanf("%d", &numero);

    if (numero<100)
    {
        printf("Numero invalido, debe ser mayor a 100.\n");
    }
    else{

        printf("Los numeros de la sucesion de fibonacci menor a %d son : %d, %d", numero, fib1, fib2);
        fibonacci = fib1+fib2;


        while (fibonacci<numero)
        {
            printf(", %d", fibonacci);
            fib1 = fib2;
            fib2 = fibonacci;
            fibonacci = fib1+fib2;
        
        }
        printf("\n");
    }
    
    return 0;
}