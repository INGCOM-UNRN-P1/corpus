/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
   if (arreglo == NULL)
   {
      return NULL;
   }
   const int *punt = arreglo;
   const int *ptr_fin = arreglo + cantidad;

   while (punt < ptr_fin)
   {
      if (*punt == valor)
      {
         return punt;
      }
      punt++;
   }

   return NULL;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
   if (inicio == NULL || elemento == NULL)
   {
      return -1;
   }
   if (elemento < inicio)
   {
      return -1;
   }

   return elemento - inicio;
}

// La herramienta gaff detecto los errores
// 0x0009h, 0x2003h, 0x2008h, 0x0004h
// los cuales considero que no se aplican
// a mi codigo.
