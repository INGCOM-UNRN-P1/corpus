

#include <stdio.h>
//se declara funcion
int numero_defectivo (int numero);

int main()
{
   int numero = 105;
//se asigna funcion a variable para imprimir en pantalla segun la condicion 
   int suma = numero_defectivo(numero);

   if (suma < numero) 
   {
   printf("%d es un numero defectivo\n", numero);
   } 
   else 
   {
   printf("%d no es un numero defectivo\n", numero);
   }

   return 0;
}

//pre:recibe un numero entero
int numero_defectivo(int numero) 
{//funcion calcula la suma de los divisores para saber si es defectivo o no
   int suma = 0;

   for (int i = 1; i <= numero / 2; i++) 
   {
      if (numero % i == 0) 
      {
            suma = suma + i;
      }
   }

   return suma;
}//pos: calcula si el numero es defectivo o no

