/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
   if (destino == NULL || origen == NULL || capacidad == 0)
   {
      return false;
   }
   char *ptr_dest = destino;
   const char *ptr_orig = origen;
   size_t copiar = 0;

   while (copiar < capacidad - 1 && *ptr_orig != '\0')
   {
      *ptr_dest++ = *ptr_orig++;
      copiar++;
   }
   *ptr_dest = '\0';
   return *ptr_orig == '\0';
}

bool concatenar_punteros(char *destino, size_t capacidad, const char *origen)
{
   if (destino == NULL || origen == NULL || capacidad == 0)
   {
      return false;
   }
   char *ptr_dest = destino;
   size_t ocupado = 0;

   while (ocupado < capacidad && *ptr_dest != '\0')
   {
      ptr_dest++;
      ocupado++;
   }
   if (ocupado >= capacidad)
   {
      return false;
   }
   const char *ptr_orig = origen;

   while (ocupado < capacidad - 1 && *ptr_orig != '\0')
   {
      *ptr_dest++ = *ptr_orig++;
      ocupado++;
   }
   *ptr_dest = '\0';
   return *ptr_orig == '\0';
}

// La herramienta gaff detecto los errores
// 0x001Dh, 0x001Eh, 0x0004h, 0x2003h
// los cuales considero no se aplican
// a mi codigo.
