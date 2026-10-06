/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"

void ordenar_par(int *menor, int *mayor)
{
   if (menor == NULL || mayor == NULL)
   {
      return;
   }
   if (*menor > *mayor)
   {
      intercambiar(menor, mayor);
   }
}

void ordenar_tria(int *ptr_a, int *ptr_b, int *ptr_c)
{
   if (ptr_a == NULL || ptr_b == NULL || ptr_c == NULL)
   {
      return;
   }
   ordenar_par(ptr_a, ptr_b);
   ordenar_par(ptr_b, ptr_c);
   ordenar_par(ptr_a, ptr_b);
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
   if (arreglo == NULL || resultado == NULL)
   {
      return false;
   }
   long long suma_acum = 0;
   const int *punt = arreglo;
   const int *ptr_fin = arreglo + cantidad;

   while (punt < ptr_fin)
   {
      suma_acum += *punt;
      punt++;
   }

   *resultado = suma_acum;
   return true;
}

// La herramienta gaff detecto los errores
// 0x0009h la cual considero no es el
// caso de mi codigo.
