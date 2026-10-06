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
#include <string.h>
#include <limits.h>


size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    for (size_t i = 0; i < capacidad; ++i)
    {
        if (cadena[i] == '\0')
        {
            return i;
        }
    }

    return capacidad;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    if (origen == NULL)
    {
        destino[0] = '\0';
        return true;
    }

    size_t i = 0;

    
    while (i + 1 < capacidad && origen[i] != '\0')
    {
        destino[i] = origen[i];
        ++i;
    }

    destino[i] = '\0';

    
    return origen[i] == '\0';
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    if (origen == NULL)
    {
        return true;
    }

    size_t dest_len = cadena_longitud(destino, capacidad);
    if (dest_len >= capacidad)
    {
        
        destino[capacidad - 1] = '\0';
        return false;
    }

    size_t avail = capacidad - dest_len - 1;
    size_t i = 0;

    while (i < avail && origen[i] != '\0')
    {
        destino[dest_len + i] = origen[i];
        ++i;
    }

    destino[dest_len + i] = '\0';

    return origen[i] == '\0';
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t convertidos = 0;

    for (size_t i = 0; i < capacidad; ++i)
    {
        char c = cadena[i];
        if (c == '\0')
        {
            break;
        }

        if (c >= 'a' && c <= 'z')
        {
            cadena[i] = (char)(c - ('a' - 'A'));
            ++convertidos;
        }
    }

    return convertidos;
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
        return true;
    }

    size_t origen_len = strlen(origen);
    if (inicio >= origen_len)
    {
        destino[0] = '\0';
        return true;
    }

    size_t max_copy = cantidad;
    size_t available = origen_len - inicio;
    size_t to_copy = max_copy < available ? max_copy : available;
    if (to_copy > 0)
    {
        size_t can_write = capacidad - 1;
        size_t actually = to_copy < can_write ? to_copy : can_write;
        for (size_t i = 0; i < actually; ++i)
        {
            destino[i] = origen[inicio + i];
        }

        destino[actually] = '\0';
        return actually == to_copy;
    }

    destino[0] = '\0';
    return true;
}



bool cadena_de_entero(char destino[], size_t capacidad, int valor)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    long long v = valor;
    bool negativo = false;
    if (v < 0)
    {
        negativo = true;
        v = -v;
    }

    
    char temp[32];
    size_t idx = 0;
    if (v == 0)
    {
        temp[idx++] = '0';
    }
    else
    {
        while (v > 0 && idx < sizeof(temp))
        {
            temp[idx++] = (char)('0' + (v % 10));
            v /= 10;
        }
    }

    size_t needed = idx + (negativo ? 1 : 0) + 1; 
    if (capacidad < needed)
    {
        destino[0] = '\0';
        return false;
    }

    size_t out = 0;
    if (negativo)
    {
        destino[out++] = '-';
    }

    
    for (size_t i = 0; i < idx; ++i)
    {
        destino[out + i] = temp[idx - 1 - i];
    }

    out += idx;
    destino[out] = '\0';
    return true;
}
