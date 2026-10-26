



#include <stdio.h>

int suma_rango(int n, int m)
// @param "n" y "m" son las cotas dentro del cual se suma
// @param "resulta"  devuelve la suma segun el requerimmiento

{
   int intercambio;         //sospecho que m será menor que n
   int resulta;
   int aumentador;

   if (m < n)
   {
      intercambio = m;
      m = n;
      n = intercambio;
   }

   resulta = n;
   aumentador = n + 1;

   while (aumentador < m)
   {
      resulta = resulta + aumentador;
      aumentador = aumentador + 1;
   }

   return resulta;
}



int main()
{
   int m, n, suma;

   printf("ingrese cota inferior : ");
   scanf("%d", &n);
   printf("ingrese cota superior : ");
   scanf("%d", &m);

   suma = suma_rango(n, m);
   printf("resulta : %d \n", suma);

   return 0;
}
