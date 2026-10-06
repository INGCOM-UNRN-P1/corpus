/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
   if (minimo == NULL || maximo == NULL || promedio == NULL)
   {
      return false;
   }
   if (cantidad == 0)
   {
      return false;
   }
   if (!obtener_min_max(arreglo, cantidad, minimo, maximo))
   {
      return false;
   }
   long long suma = 0;
   const int *punt = arreglo;
   const int *ptr_fin = arreglo + cantidad;

   while (punt < ptr_fin)
   {
      suma += *punt;
      punt++;
   }

   double suma_prom = suma;
   double cantidad_prom = cantidad;
   *promedio = suma_prom / cantidad_prom;

   return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
   if (arreglo == NULL || coincidencias == NULL)
   {
      return false;
   }
   if (limite_inf > limite_sup)
   {
      intercambiar(&limite_inf, &limite_sup);
   }

   size_t cont_coincidir = 0;
   const int *punt = arreglo;
   const int *ptr_fin = arreglo + cantidad;

   while (punt < ptr_fin)
   {
      if (*punt >= limite_inf && *punt <= limite_sup)
      {
         cont_coincidir++;
      }
      punt++;
   }
   *coincidencias = cont_coincidir;

   return true;
}

// La herramineta gaff detecto los errores
// 0x0009h, 0x200Bh, 0x1001h
// las cuales considero que no se aplican
// a mi codigo.
