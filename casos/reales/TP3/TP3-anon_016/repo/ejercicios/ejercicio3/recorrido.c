/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"


bool copiar_arreglo(const int *origen, size_t cantidad, int *destino)
{
  if(origen == NULL || destino == NULL
     || cantidad == 0)
    {
      return false;
    }
  const int *actual = origen;
  const int *fin = origen + cantidad;
        
  while(actual != fin)
  {
    *destino = *actual;
    actual++;
    destino++;
  }
  return true;
}


bool invertir_arreglo( int *arreglo, size_t cantidad)
{
  if(arreglo == NULL|| cantidad == 0)
    {
      return false;
    }
  int *inicio = arreglo;
  int *fin = arreglo + cantidad -1;
        
  while(inicio <  fin)
  {
    intercambiar(inicio,fin);
    inicio++;
    fin--;
  }
  return true;
}


