/**
 * @file cadenas.c
 * @brief Esqueleto de implementación para la biblioteca libcadenas.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "cadenas.h"

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
   if (cadena == NULL || capacidad == 0)
   {
      return 0;
   }

   size_t contador = 0;

   while (contador < capacidad && cadena[contador] != '\0')
   {
      contador++;
   }

   return contador;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
   if (destino == NULL || origen == NULL || capacidad == 0)
   {
      return false;
   }

   size_t iterar = 0;

   while (iterar < capacidad - 1 && origen[iterar] != '\0')
   {
      destino[iterar] = origen[iterar];
      iterar++;
   }

   destino[iterar] = '\0';
   return origen[iterar] == '\0';
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
   if (destino == NULL || origen == NULL || capacidad == 0)
   {
      return false;
   }

   size_t lon_destino = cadena_longitud(destino, capacidad);
   if (lon_destino >= capacidad)
   {
      return false;
   }
   size_t iterar = 0;
   while (lon_destino + iterar < capacidad - 1 && origen[iterar] != '\0')
   {
      destino[lon_destino + iterar] = origen[iterar];
      iterar++;
   }

   destino[lon_destino + iterar] = '\0';
   return origen[iterar] == '\0';
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
   if (cadena == NULL || capacidad == 0)
   {
      return 0;
   }

   size_t cambios = 0;
   size_t iterar = 0;
   while (iterar < capacidad && cadena[iterar] != '\0')
   {
      if (cadena[iterar] >= 'a' && cadena[iterar] <= 'z')
      {
         char convertido = cadena[iterar] - ('a' - 'A');
         cadena[iterar] = convertido;
         cambios++;
      }
      iterar++;
   }
   return cambios;
}

bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
{
   if (destino == NULL || capacidad == 0)
   {
      return false;
   }
   if (origen == NULL)
   {
      destino[0] = '\0';
      return false;
   }

   size_t largo = cadena_longitud(origen, (size_t)-1);
   if (inicio >= largo)
   {
      destino[0] = '\0';
      return false;
   }

   bool finalizado = true;
   size_t copias = 0;
   while (copias < cantidad - 1 && origen[inicio + copias] != '\0')
   {
      if (copias < capacidad - 1)
      {
         destino[copias] = origen[inicio + copias];
      }
      else
      {
         finalizado = false;
      }
      copias++;
   }

   if (copias < capacidad)
   {
      destino[copias] = '\0';
   }
   else
   {
      destino[capacidad - 1] = '\0';
   }

   return finalizado;
}

// Ejercicio 6: No realizado, hago la entrega con
// los requisitos mínimos.

// Al utilizar la herramienta gaff me retorna las
// siguientes violaciones a las reglas de estilo:
// 0x001Dh; 0x001Eh; 0x0002h; 0x200Bh; 0x0009h.
// Considero que no aplica en este codigo por lo
// solicitado y lo planteado.
