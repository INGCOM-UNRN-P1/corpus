/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"
#include <stdbool.h>

 
int main(void)
{
  int datos[] = {7, -3, 12, 5, 0, 9, 21, 4};
  size_t cantidad = sizeof(datos) / sizeof(datos[0]);
 
  int minimo = 0;
  int maximo = 0;
  double promedio = 0.0;
 
  printf("Ejercicio 2: Estadísticas, Promedio y Filtrado por Rango con Punteros\n");

  if (calcular_estadisticas(datos, cantidad, &minimo, &maximo, &promedio))
  {
    printf("Minimo:   %d\n", minimo);
    printf("Maximo:   %d\n", maximo);
    printf("Promedio: %.2f\n", promedio);
  }
  else
  {
    printf("Error: no se pudieron calcular las estadisticas.\n");
  }
 
  int limite_inf = 0;
  int limite_sup = 10;
  size_t coincidencias = 0;
 
  if (contar_en_rango(datos, cantidad, limite_inf, limite_sup, &coincidencias))
  {
    printf("Elementos en el rango [%d, %d]: %zu\n",
           limite_inf, limite_sup, coincidencias);
  }
  else
  {
    printf("Error: no se pudo contar en el rango.\n");
  }
}