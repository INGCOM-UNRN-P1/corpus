


#include <stdio.h>
#define TRUE 1
#define FALSE 0


int es_primo(int numero)
{
    int i;
    for (int i = 2; i * i <= numero; i++) 
    {
        if (numero % i == 0) 
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
   int numero;
   int evaluar;
   printf("Ingrese un numero: \n");
   scanf("%d",&numero);
   if ( numero <=1 )
   {
    printf("El numero no es primo");
   } 
   else 
   {
   evaluar = es_primo(numero);
   printf("Si sale 1 es primo, si sale 0 no lo es: %d \n",evaluar);
   }
   return 0;
}