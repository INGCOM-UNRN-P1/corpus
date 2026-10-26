

#include <stdio.h>

int factorial(int numero);



int main()

{
    int numero;
    int fact;

    printf("Ingrese un numero positivo -> ");
    
    scanf("%d", numero);
    
    fact = factorial(numero);

    printf("El factorial de %d es %d", numero, fact);
    
    return 0;
}

int factorial(int numero)
{
    int i = 1;
    int facti = 1;
    
    if (numero == 0)
    {
        return 1;
    }

    while (i <= numero)
    {
        facti = facti * i;
        i++;
    }  
    return facti;
}