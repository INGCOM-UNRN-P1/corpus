/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
   if (inicio == NULL || fin == NULL || inicio > fin)
   {
      return NULL;
   }
   const int *ptr_min = inicio;
   const int *ptr = inicio + 1;

   while (ptr <= fin)
   {
      if (*ptr < *ptr_min)
      {
         ptr_min = ptr;
      }
      ptr++;
   }

   return ptr_min;
}

void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
   if (arreglo == NULL || cantidad < 2)
   {
      return;
   }
   int *ptr_actual = arreglo;
   int *ptr_limite = arreglo + cantidad - 1;

   while (ptr_actual < ptr_limite)
   {
      const int *ptr_min = buscar_puntero_minimo(ptr_actual, ptr_limite);
      if (ptr_min != NULL && ptr_min != ptr_actual)
      {
         int *dest_min = ptr_actual + (ptr_min - ptr_actual);
         int valor = *ptr_actual;
         *ptr_actual = *ptr_min;
         *dest_min = valor;
      }
      ptr_actual++;
   }
}
