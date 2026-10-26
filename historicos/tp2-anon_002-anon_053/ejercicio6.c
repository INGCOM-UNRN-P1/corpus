

#include <stdio.h>

int serPrimo(int numero);
int suma_primos(int resultado);

int main()
{
   int numero = 3; 
   int resultado = 11;

   if (serPrimo(numero) == 1)
   {
      printf("Retorna %d por lo tanto es primo\n", serPrimo(numero));
   }
   else
   {
      printf("Este numero no es primo");
   }

   printf("La suma de los numeros primos es: %d\n", suma_primos(resultado));
   return 0;
}

//pre: recibe un numero entero mayor a 1
//pos:retornara si el numero es primo o no lo es
int serPrimo(int numero) //funcion calcula si un numreo mayor a 1 es primo
{
   int resolucion = 1;
   if(numero <= 1)
   {
      resolucion;
   }
   int i;
    for(i = 2; i * i <= numero; i++)
   {
      if (numero % i == 0)
      {
         resolucion;
      }
   }
   return resolucion; 
}

//pre:recibe un numero entero
//pos:retorna suma de numero primos
int suma_primos(int resultado) //funcion que suma cada digito de de los primeros n numeros primos
{   
   int suma = 0;
   int i;
   for (i = 2; i<= resultado; i++)
   {
      if (serPrimo(i))
      {
         suma = suma + i;
      }
   }
   return suma;
}




