/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
   printf("Ejercicio 3: Recorrido e inversión con punteros\n");
   int arr_origen[] = {10, 20, 30, 40, 50};
   size_t cantidad = sizeof(arr_origen) / sizeof(arr_origen[0]);
   int arr_destino[5];
   printf("Demostracion de copiar_arreglo.\n");
   if (copiar_arreglo(arr_origen, arr_destino, cantidad))
   {
      printf("Arreglo de origen: ");
      const int *ptr_orig = arr_origen;
      const int *ptr_fin_orig = arr_origen + cantidad;
      while (ptr_orig < ptr_fin_orig)
      {
          printf("%d ", *ptr_orig++);
      }

      printf("\nArreglo de destino (copiado): ");
      const int *ptr_dest = arr_destino;
      const int *ptr_fin_dest = arr_destino + cantidad;
      while (ptr_dest < ptr_fin_dest)
      {
         printf("%d ", *ptr_dest++);
      }
   }

   printf("\nDemostracion de invertir_arreglo.\n");
   if (invertir_arreglo(arr_destino, cantidad))
   {
      printf("Arreglo de destino (invertido in-place): ");
      const int *ptr_inv = arr_destino;
      const int *ptr_fin_inv = arr_destino + cantidad;
      while (ptr_inv < ptr_fin_inv)
      {
         printf("%d ", *ptr_inv++);
      }
   }
   printf("\nFinalizado.\n");
   return 0;
}

// La herramienta gaff detecto los errores
// 0x2009h, 0x001Eh, 0x0017h, 0x300Dh,
// 0x0003h, 0x1001h los cuales considero
// que no se aplican en mi codigo.
