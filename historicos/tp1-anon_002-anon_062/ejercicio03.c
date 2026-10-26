




#include <stdio.h>

int signo(int numero)
// @param ´numero´    un nro entero para identificar signo
// @param ´retorna´   devuelve -1, 0 o 1 según sea el sino del valor ingresado


{
   int retorna = 0;

   if (numero !=0)
   {
      if (numero > 0)
      {
          retorna = 1;
      }
      else
      {
         retorna = -1;
      }
   }

   return retorna;
}

// --------------- MAIN ---------------
int main()
{
   int numero;
   int resultado = 0;
   
   printf("Ingrese un enetero cualquiera: \n");
   scanf("%d", &numero);

   resultado = signo(numero);
   printf("el signo de su nro es %d", resultado);
   return 0;
}
