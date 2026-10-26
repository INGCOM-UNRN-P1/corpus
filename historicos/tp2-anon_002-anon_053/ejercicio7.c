

#include <stdio.h>

int sumas(int base, int veces);
int potencia_lenta(int base, int exponente);

int main()
{
   int base = 3;
   int exponente = 3;
   
   printf("%d a la %d es igual a: %d", base, exponente, potencia_lenta(base, exponente));
}

//pre:recibe dos valores enteros
int sumas(int base, int veces)
{//funcion calcula la suma hasta veces
   int resultado = 0;
   int i;
   for (i = 0; i < veces; i++)
   {
      resultado = resultado + base;
   }
   return resultado;
}//pos: devuelve resultado de la suma de ambos enteros

//pre:recibe dos numeros enteros 
int potencia_lenta(int base, int exponente)
{//funcion calcula la potencia usando sumas sucesivas
   if (exponente == 0)
   {
      return 1; //Si el exponente es cero se retorna un valor de uno
   }

   int resultado = base;
   int j;
   for (j = 2; j <= exponente; j++)
   {
      resultado = sumas(resultado, base);
   }
   return resultado;
}//pos: calcula la potencia utilizando sumas 

