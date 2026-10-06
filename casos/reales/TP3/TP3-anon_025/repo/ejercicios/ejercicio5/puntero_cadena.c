/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *puntero_destino, size_t capacidad_destino, const char *puntero_origen)
{
    if (puntero_destino == NULL || puntero_origen == NULL || capacidad_destino == 0)
    {
        if (puntero_destino != NULL && capacidad_destino > 0)
        {
            *puntero_destino = '\0';
        }
        return false;
    }

    char *cursor_escritura = puntero_destino;
    const char *cursor_lectura = puntero_origen;
    size_t caracteres_escritos = 0;

    while (*cursor_lectura != '\0' && caracteres_escritos < capacidad_destino - 1)
    {
        *cursor_escritura = *cursor_lectura;

        cursor_escritura++;
        cursor_lectura++;
        caracteres_escritos++;
    }

    *cursor_escritura = '\0';
    return (*cursor_lectura == '\0');
}

bool concatenar_con_punteros(char *puntero_destino, size_t capacidad_destino, const char *puntero_origen)
{
   if (puntero_destino == NULL || puntero_origen == NULL || capacidad_destino == 0)
   {
    return false;
   } 

   char *cursor_escritura = puntero_destino;
   size_t longitud_actual = 0;

   while (*cursor_escritura != '\0' && longitud_actual < capacidad_destino)
   {
    cursor_escritura++;
    longitud_actual++;
   }
   if(longitud_actual >= capacidad_destino -1)
   {
    *(puntero_destino + capacidad_destino -1) = '\0';
    return false;
   }

   const char *cursor_lectura = puntero_origen;
   size_t espacio_restante = capacidad_destino - longitud_actual -1;
   size_t caracteres_escritos = 0;

   while (*cursor_lectura != '\0' && caracteres_escritos < espacio_restante)
   {
    *cursor_escritura = *cursor_lectura;

    cursor_escritura++;
    cursor_lectura++;
    caracteres_escritos++;
   }

   *cursor_escritura = '\0';
   return (*cursor_lectura == '\0');
}


