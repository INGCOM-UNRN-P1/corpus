/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
   printf("ejercicio 2: estadisticas con punteros\n");

   int datos[] = {5, 12, 18, 25, 30, 42};
   size_t cantidad = sizeof(datos) / sizeof(datos[0]);

   int minimo = 0;
   int maximo = 0;
   double promedio = 0.0;

   if (calcular_estadisticas(datos, cantidad, &minimo, &maximo, &promedio))
   {
       printf("minimo: %d\n", minimo);
       printf("Maximo: %d\n", maximo);
       prinf("promedio: %.2f\n", promedio);
   }

   size_t coincidencias = 0;
   if (contar_en_rango(datos, cantidad, 10, 30, &coincidencias))
   {
       printf("elementos en [10, 30]: %zu\n", &coincidencias);
   }

   return 0;
}