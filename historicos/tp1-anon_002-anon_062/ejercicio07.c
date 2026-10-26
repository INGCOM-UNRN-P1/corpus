




#include <stdio.h>
#include <math.h>

int es_primo(int numero)
{
   //@param ´numero´ es el valor que se desea conocer si es primo
   //@return ´flag´ devuelve 1 si es primo, 0 si es compuesto


   int flag = 1;       //supongo que es primo
   int laraiz;
   int divisor = 1;


   // el primer condicional es para filtrar numeros mayores que 2

   if (numero > 2)
   {

      //calculo la raiz para usarla de  primer divisor y encontrar el resto
      laraiz = sqrt(numero);
      divisor = laraiz + 1;

      while (divisor > 1)
      {

         if (numero % divisor == 0)
         {
            flag = 0;           //indico que es compuesto
            divisor = 1;        //forzar al divisor = 1 y salir
         }

         divisor = divisor - 1;
      }
   }

   return flag;
}


int main()
{
   int numero;
   int seraprimo;

   printf("Ingrese un numero : ");
   scanf("%d", &numero);
   
   seraprimo = es_primo(numero);
   printf("%d", seraprimo);

   return 0;
}
