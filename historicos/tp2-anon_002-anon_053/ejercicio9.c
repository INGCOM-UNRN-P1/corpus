

#include <stdio.h>
//se declaran funciones
int sumaDigitos(int numero);
long long fibonacci(int valor);

int main() 
{
   int valor = 10; 
// se llaman a funciones a imprimir por pantalla
   long long fibN = fibonacci(valor);
   int suma = sumaDigitos(fibN);

   printf("El %d-esimo termino de Fibonacci es: %lld\n", valor, fibN);
   printf("La suma de digitos en el termino es: %d\n", suma);

   return 0;
}

//pre:recibe numero entero 
int sumaDigitos(int numero) 
{//funcion calcula la suma de cada digito de la serie 
   int suma = 0;
   while (numero > 0) 
   {
      suma = suma + numero % 10;
      numero = numero / 10;
   }
   return suma;
}//pos: retorna la suma de digitos

//pre: recibe numero entero
//pos: retorna el enesimo termino de la serie
long long fibonacci(int valor) 
{
   int resolucion = 0;
   if (valor <= 0) 
   {
      resolucion;
   } 
   else if (valor == 1) 
   {
      resolucion = 1;
   } 
   else 
   {//parte del ciclo que calcula el enesimo termino de la serie
      long long a = 0;
      long long b = 1;
      long long fibon= 0;
      int contador;

      for (contador = 2; contador <= valor; contador++) 
      {
            fibon = a + b;
            a = b;
            b = fibon;
      }
      resolucion = fibon;
      
      return resolucion;
   }
}


