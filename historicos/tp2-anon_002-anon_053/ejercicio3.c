

#include <stdio.h>
//se declara funcion
void tabla (int numero);

int main()
{
   int numero = 10;

   printf("La tabla de %d es:\n", numero);
   
   tabla(numero);

   return 0;
}

//recibe un numero entero
void tabla (int numero)
{//funcion que imprime tabla de multiplicar de numero ingresado
   if((numero > 0) && (numero <= 10))
   {
      for(int i = 1; i <= 10; i++)
      {
         printf("%d x %d = %d\n", numero,i ,numero * i );
      }      
   }
   else
   {
      printf("Numero fuera del rango");
   }
   
}//pos: imprime por pantalla tabla de multiplicar


