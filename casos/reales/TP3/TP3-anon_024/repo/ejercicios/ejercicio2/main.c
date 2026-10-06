/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
   printf("Ejercicio 2: Estadísticas con punteros\n");
   int arrmain[] = {17, -22, 8, 72, 0, -52, 34, -9};
   size_t cantidad = sizeof(arrmain) / sizeof(arrmain[0]);
   int val_min = 0;
   int val_max = 0;
   double val_prom = 0.0;

   printf("Demostracion de obtener_min_max\n");
   if (obtener_min_max(arrmain, cantidad, &val_min, &val_max))
   {
      printf("Valor minimo encontrado: %d\n", val_min);
      printf("Valor maximo encontrado: %d\n", val_max);
   }

   printf("Demostracion de calcular_estadisticas\n");
   if (calcular_estadisticas(arrmain, cantidad, &val_min, &val_max, &val_prom))
   {
      printf("Valor minimo: %d\n", val_min);
      printf("Valor maximo: %d\n", val_max);
      printf("Promedio de ambos valores: %.2f\n", val_prom);
   }
   return 0;
}

// La herramienta gaff detecto los errores
// 0x001Eh, 0x300Dh, 0x1001h, 0x001Dh
// los cuales considero que no se aplican
// a mi codigo.
