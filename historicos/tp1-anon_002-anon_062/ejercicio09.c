



#include <stdio.h>


int es_multiplo(int numero, int divisor)


{
   int descuento;
   int resulta = 0;

   descuento = numero;

   while (descuento >= divisor)
   {
      descuento = descuento - divisor;
   }

   if (descuento == 0)
   {
      resulta = 1;
   }

   return resulta;
}


int main()
{
   int numero = 0;
   int divisor = 0;            // forzar al divisor para que se ejecute el while
   int resultado = 0;

   printf("Ingrese su primer numero :  ");
   scanf("%d",&numero);
   
   while (divisor == 0)       //la 1ra vez div es cero, por eso el mje de ingreso
   {
      printf("Ingrese un divisor distinto de CERO : ");
      scanf("%d",&divisor);
   }
   
   resultado = es_multiplo(numero, divisor);
   printf("%d", resultado);
   return 0;
}
