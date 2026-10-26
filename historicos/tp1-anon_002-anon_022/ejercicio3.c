



#include <stdio.h>
#define TRUE 1 
#define FALSE 0

int signo (int numero)
{
    if (numero > 0)
    {
        return 1;
    } 
    else if (numero < 0)
    {
        return -1;
    } 
    else 
    {
        return 0;
    }
}

int main()
{
   int numero;
   int resultado;
   printf("Ingrese un numero: \n");
   scanf("%d",&numero);
   resultado = signo(numero);
   printf("%d\n",resultado);
   return 0;
}