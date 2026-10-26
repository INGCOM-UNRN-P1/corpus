

#include <stdio.h>
int factorial(int numero)
{
    
    int i = 1;
    int factor = 1;
    while (i <= numero)
    {
        factor = factor * i;
        i = i+1;
    }
    return factor;
}
int main()
{
   int numero, factor;
   printf("Ingrese un numero para ver su factorial: \n");
   scanf("%d", &numero);
   factor = factorial(numero);
   printf("El factorial es %d", factor);
}
