/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo(const int *origen, int *destino, size_t cantidad)
{
   if (destino == NULL || origen == NULL)
   {
      return false;
   }

   int *ptr_dest = destino;
   const int *punt = origen;
   const int *ptr_fin = origen + cantidad;

   while (punt < ptr_fin)
   {
      *ptr_dest++ = *punt++;
   }

   return true;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
   if (arreglo == NULL)
   {
      return false;
   }
   if (cantidad <= 1)
   {
      return true;
   }
   int *ptr_in = arreglo;
   int *ptr_fin = arreglo + (cantidad - 1);

   while (ptr_in < ptr_fin)
   {
      intercambiar(ptr_in, ptr_fin);
      ptr_in++;
      ptr_fin--;
   }

   return true;
}
