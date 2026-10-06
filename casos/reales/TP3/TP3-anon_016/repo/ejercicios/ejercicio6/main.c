/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

static void imprimir_arreglo(const int *arreglo, size_t cantidad)
{
  for (size_t i = 0; i < cantidad; i++)
  {
    printf("%d ", arreglo[i]);
  }
  printf("\n");
}

int main(void)
{
  printf("Ejercicio 6: Ordenamiento por seleccion con punteros\n");

  int numeros[] = {40, 10, 30, 20, 50};
  size_t cantidad = 5;

  printf("  antes:   ");
  imprimir_arreglo(numeros, cantidad);

  ordenar_seleccion_punteros(numeros, cantidad);

  printf("  despues: ");
  imprimir_arreglo(numeros, cantidad);

  int rango[] = {8, 3, 9, 1};
  const int *minimo = buscar_puntero_minimo(&rango[0], &rango[3]);
  printf("  buscar_puntero_minimo en {8,3,9,1}: %d\n", *minimo);

  return 0;

}
