



#include <stdio.h>





void tabla_multiplicar (int numero) 
{
    int resultado;
    int i =1;
    for (i ; i <= 10; i++)
    {
        resultado = numero * i;
        printf("%d x %d = %d\n",numero,i,resultado);
    }
}

int main()
{
   int numero;
   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   printf("TABLA DE MULTIPLICAR \n");
   tabla_multiplicar(numero);
   return 0;
}
