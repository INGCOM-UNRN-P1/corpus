

#include <stdio.h>
#define FALSE 0

int contador_circular (int numero, int limite)
{
   return (numero + 1) % limite;
}

int main()
{
   int numero;
   int limite;
   int evaluar;
   int cantidad;
   int i = 0;
   printf("Ingrese la cantidad de veces que va a funcionar el contador: ");
   scanf("%d", &cantidad);
   printf("Ingrese el numero donde empieza: ");
   scanf("%d", &numero);
   printf("Ingrese el limite para el contador: ");
   scanf("%d", &limite);
   if (limite< 0)
   {
      printf("El limite debe ser un numero positivo");
   }
   else 
   {
      evaluar = numero;
      for (i; i <= cantidad; i++)
         {
            printf("%d\n", evaluar);
            evaluar = contador_circular(evaluar, limite);
            
         }
   }
   return 0;
}
