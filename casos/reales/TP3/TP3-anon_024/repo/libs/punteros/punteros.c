/**
 * @file punteros.c
 * @brief Esqueleto de implementación para la biblioteca libpunteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
   if (primer == NULL || segundo == NULL)
   {
      return;
   }
   if (primer == segundo)
   {
      return;
   }

   int valor_temp = *primer;
   *primer = *segundo;
   *segundo = valor_temp;
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
   if (arreglo == NULL || cantidad == 0)
   {
      return false;
   }
   if (minimo == NULL || maximo == NULL)
   {
      return false;
   }

   const int *punt = arreglo;
   const int *ptr_fin = arreglo + cantidad;
   *minimo = *punt;
   *maximo = *punt;
   punt++;

   while (punt < ptr_fin)
   {
      if (*punt < *minimo)
      {
         *minimo = *punt;
      }
      if (*punt > *maximo)
      {
         *maximo = *punt;
      }
      punt++;
   }
   return true;
}
