

#include <stdio.h>
// se declara funcion
int menor(int valor1, int valor2, int valor3);

int main()
{
   int valor1 = 40;
   int valor2 = 20;
   int valor3 = 50;

   printf("El valor menor es: %d\n", menor(valor1, valor2, valor3));
}

//pre: recibe tres numeros enteros
//pos: devuelve el menor de tres numeros
int menor(int valor1, int valor2, int valor3)
{//verifica entre tres numeros cual es menor
   int decision = 0;
   if ((valor1 < valor2) && (valor1 <= valor3))
   {
      decision = valor1;
   }
   else if ((valor2 < valor1) && (valor2 < valor3))
   {
      decision = valor2;
   }
   else
   {
      decision = valor3;
   }
   return decision;
}


