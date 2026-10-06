/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"


bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
   if(destino == NULL || origen == NULL || capacidad == 0)
   {
    return false;
   }

   bool completo = true;
   const char  *actual = origen;
   const char *limite = destino + capacidad - 1;
         
   while(*actual != '\0' && destino < limite)
   {
     *destino = *actual;
     actual++;
     destino++;
   }
   if(*actual != '\0')
   {
    completo = false;
   }

   *destino = '\0';
   
   return completo;
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if(destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }
    
    char *limite = destino + capacidad - 1;
    const char  *actual = origen;
         
   while(*destino != '\0')
   {
     destino++;
   }
   while(*actual != '\0' && destino < limite)
   {
     *destino = *actual;
     actual++;
     destino++;
   }
   if(*actual != '\0')
   {
    *destino = '\0';
    return false;
   }
   *destino = '\0';
   return true;
}