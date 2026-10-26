

#include <stdio.h>

//se declara funcion
int mayor(int valor1, int valor2, int valor3);

int main()
{
   int valor1 = 18;
   int valor2 = 56;
   int valor3 = 74;

   printf("El valor mayor es: %d\n", mayor(valor1, valor2, valor3));
}

//pre: recibe tres numeros enteros
//pos: retorna el mayor de tres numeros enteros
int mayor(int valor1, int valor2, int valor3)
{// funcion verifica entre tres numeros cual es mayor
   int resolucion = 0;
   if ((valor1 > valor2) && (valor1 >= valor3))
   {
      resolucion = valor1;
   }
   else if ((valor2 > valor1) && (valor2 > valor3))
   {
      resolucion = valor2;
   }
   else
   {
      resolucion = valor3;
   }
   return resolucion;
}


