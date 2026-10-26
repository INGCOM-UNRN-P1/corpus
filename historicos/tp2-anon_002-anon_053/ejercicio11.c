

#include <stdio.h>
//se declara la funcion
int numeros_perfectos (int numero);

int main()
{
   int numero = 46;
   //condicion donde se imprime si es correcto el retorno
   if (numeros_perfectos(numero)) 
   {
      printf("El numero %d es un numero perfecto", numero);
   }
   else 
   {
      printf("El numero %d no es un numero perfecto", numero);
   }
   return 0;

}
//pre: recibe un numero entero
int numeros_perfectos(int numero)
{//funcion donde verifica si la suma es igual al numero indica es perfecto
   int suma = 1;
   int contador = 2;
   
   while (contador <= numero / 2)
   {
      if (numero % contador == 0)
      {
         suma = suma + contador;
      }
      contador = contador + 1;
   }

   return(suma == numero);   
}//pos:retorna perfecto si cumple la condicion o no es perfecto si no la cumple


