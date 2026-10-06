/**
 * @file arreglos.c
 * @brief Esqueleto de implementación para la biblioteca libarreglos.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
   if (arreglo == NULL || cantidad == 0)
   {
      return 0;
   }

   long long suma = 0;

   for (size_t iterar = 0; iterar < cantidad; iterar++)
   {
      suma += arreglo[iterar];
   }

   return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
   if (arreglo == NULL || cantidad == 0)
   {
      return -1;
   }

   for (size_t iterar = 0; iterar < cantidad; iterar++)
   {
      if (arreglo[iterar] == buscado)
      {
         int encontrado = iterar;
         return encontrado;
      }
   }
   return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
   if (arreglo == NULL || cantidad <= 1)
   {
      return;
   }

   size_t inicio_inv = 0;
   size_t fin_inv = cantidad - 1;
   int valor_temp = 0;
   while (inicio_inv < fin_inv)
   {
      valor_temp = arreglo[inicio_inv];
      arreglo[inicio_inv] = arreglo[fin_inv];
      arreglo[fin_inv] = valor_temp;
      inicio_inv++;
      fin_inv--;
   }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
   if (arreglo == NULL)
   {
      return false;
   }
   if (cantidad <= 1)
   {
      return true;
   }

   for (size_t iterar = 0; iterar < cantidad - 1; iterar++)
   {
      if (arreglo[iterar] > arreglo[iterar + 1])
      {
         return false;
      }
   }
   return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
   if (arreglo == NULL || cantidad == 0)
   {
     return 0;
   }

   size_t ocurrencias = 0;
   for (size_t iterar = 0; iterar < cantidad; iterar++)
   {
      if (arreglo[iterar] == buscado)
      {
         ocurrencias++;
      }
   }
   return ocurrencias;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
   if (arreglo == NULL || cantidad == 0)
   {
      return 0;
   }

   size_t restantes = 0;
   for (size_t recorrido = 0; recorrido < cantidad; recorrido++)
   {
      if (arreglo[recorrido] != valor)
      {
         arreglo[restantes] = arreglo[recorrido];
         restantes++;
      }
   }
   return restantes;
}

size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad)
{
   if (destino == NULL || capacidad == 0)
   {
      return 0;
   }
   if (primero == NULL && cantidad_uno > 0)
   {
      return 0;
   }
   if (segundo == NULL && cantidad_dos > 0)
   {
      return 0;
   }

   size_t in_uno = 0;
   size_t in_dos = 0;
   size_t in_fin = 0;
   while (in_uno < cantidad_uno && in_dos < cantidad_dos && in_fin < capacidad)
   {
      if (primero[in_uno] <= segundo[in_dos])
      {
         destino[in_fin++] = primero[in_uno++];
      }
      else
      {
         destino[in_fin++] = segundo[in_dos++];
      }
   }

   while (in_uno < cantidad_uno && in_fin < capacidad)
   {
      destino[in_fin++] = primero[in_uno++];
   }

   while (in_dos < cantidad_dos && in_fin < capacidad)
   {
      destino[in_fin++] = segundo[in_dos++];
   }

   return in_fin;
}

// Al utilizar la herramienta gaff me retorna las
// siguientes violaciones a las reglas de estilo:
// 0x2008h; 0x0004h; 0x200Bh; 0x0009h. Considero
// que no aplica en este codigo por lo solicitado
// y lo planteado.
