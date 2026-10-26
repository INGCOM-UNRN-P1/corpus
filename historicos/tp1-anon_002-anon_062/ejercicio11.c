



#include <stdio.h>

int contador_circular(int i, int limite)

// @param i indica en qué valor de la vuelta voy (comenzando desde el cero)
// @param limite indica cuál es el límite donde debo devolver 0
// @return salida que es el numero que debo imprimir -el valor i aumentado en 1-

{	
   int salida = 0;

   salida = i;
   if (i != limite)
   {
      salida = i + 1;
   }

   return salida;
}


int main()
{
   int cant_vueltas = 0;
   int limite = 0;
   int i = 0;
   int indice = 0;
   int muestro = 5;
   int contador = 0;

   printf("ingrese la cantidad de vueltas que dará su contador : ");
   scanf("%d", &cant_vueltas);
   printf("Indique el límite donde su contador debe volver a comenzar : ");
   scanf("%d", &limite);

   while (i <= cant_vueltas)
   {
      while (indice != limite)
      {
         muestro = contador_circular(indice, limite);
      
         printf("es : %d \n", muestro);
         indice ++;
      }

      indice = 0;
      i++;
   }
}