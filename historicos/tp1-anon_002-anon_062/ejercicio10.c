



#include <stdio.h>

long factorial(int numero)
{
   int resulta = 1;
   int incremento = 1;
   
   while (incremento <= numero)
   {
      resulta = resulta * incremento;
      incremento = incremento + 1;
   }

   return resulta;
}


int main()
{
   int numero = 0;
   int fact = 0;

   printf("Ingrese un valor : ");
   scanf("%d", &numero);                // cambiar tipo de dato a Long
   fact = factorial(numero);
   printf("%d", fact);                  //Long aqui
   
   return 0;
}
