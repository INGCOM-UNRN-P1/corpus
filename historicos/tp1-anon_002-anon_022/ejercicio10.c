


#include <stdio.h>

long  factorial (int numero)
{
    int aux =1;
    long int resultado = 1;
    for (aux; aux <= numero; aux++)
    {
        resultado = resultado * aux;
    }
    return resultado;
}
int main()
{
   int numero;
   printf("Ingrese el numero para calcular su factorial: \n");
   scanf("%d", &numero);
   printf("Factorial de %d es %ld",numero,factorial(numero));
   return 0;
}
