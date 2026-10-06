/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
   printf("Ejercicio 6: Ordenamiento por selección con punteros\n");
   int arrmain[] = {64, 25, 12, 22, 11};
   size_t cantidad = sizeof(arrmain) / sizeof(arrmain[0]);
   printf("Arreglo original: ");
   for (size_t iterar = 0; iterar < cantidad; iterar++)
   {
      printf("%d ", *(arrmain + iterar));
   }

   ordenar_seleccion_punteros(arrmain, cantidad);
   printf("\nArreglo ordenado: ");
   for (size_t iterar = 0; iterar < cantidad; iterar++)
   {
      printf("%d ", *(arrmain + iterar));
   }
   printf("\nFinalizado.\n");

   return 0;
}

// La herramienta gaff detecto los errores
// 0x001Eh, 0x300Dh, 0x001Dh los cuales
// considero que no se aplican a mi codigo. 
