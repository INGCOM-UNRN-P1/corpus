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
    for (size_t i = 0; i < capacidad; i++)
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
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }
    size_t recorrer_arreglo = 0;
    while (recorrer_arreglo < capacidad-1 && origen[recorrer_arreglo] != '\0')
    {
        destino[recorrer_arreglo] = origen[recorrer_arreglo];
        recorrer_arreglo++;
    }
    if (origen[recorrer_arreglo] == '\0')
    {
        destino[recorrer_arreglo] = origen[recorrer_arreglo];
        return true;
    }
    else
    {
        destino[recorrer_arreglo] = '\0';
        return false;
    }
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }
    size_t comienzo_anexo = cadena_longitud(destino, capacidad);
    return cadena_copiar(&destino[comienzo_anexo], capacidad-comienzo_anexo, origen);
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    const int distancia_min_a_may = 'A'-'a';
    size_t cantidad_convertidos = 0;
    size_t recorrer_cadena = 0;

    while (recorrer_cadena < capacidad && cadena[recorrer_cadena] != '\0')
    {
        if (cadena[recorrer_cadena] >= 'a' && cadena[recorrer_cadena] <= 'z')
        {
            cadena[recorrer_cadena] = cadena[recorrer_cadena] + distancia_min_a_may;
            cantidad_convertidos++;
        }
        recorrer_cadena++;
    }
    return cantidad_convertidos;
}


bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
{
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }

    bool satisfactorio = true;

    size_t longitud_origen = 0;
    while (origen[longitud_origen] != '\0')
    {
        longitud_origen++;
    }

    if (inicio >= longitud_origen)
    {
        destino[0] = '\0';
        return true;
    }
    else
    {
        size_t longitud_porcion = cadena_longitud(&origen[inicio], cantidad);
        size_t copiar_hasta = 0;
        if (longitud_porcion < capacidad)
        {
            copiar_hasta = longitud_porcion;
        }
        else
        {
            copiar_hasta = capacidad-1;
            satisfactorio = false;
        }
        for (size_t i = 0; i < copiar_hasta; i++)
        {
            destino[i] = origen[i + inicio];
        }
        destino[copiar_hasta] = '\0';

        return satisfactorio;
    }
}


bool cadena_de_entero(char destino[], size_t capacidad, int valor)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    size_t cantidad_de_caracteres = 0;
    size_t comienzo = 0;
    int signo = 1;
    int copia = valor;

    if (valor == 0 && capacidad > 1)
    {
        destino[0] = '0';
        destino[1] = '\0';
        return true;
    }
    if (valor < 0)
    {
        cantidad_de_caracteres++;
        signo = -1;
        comienzo = 1;
        destino[0] = '-';
    }
    while (copia != 0)
    {
        cantidad_de_caracteres++;
        copia = copia / 10;
    }

    if (cantidad_de_caracteres >= capacidad)
    {
        destino[0] = '\0';
        return false;
    }
    else
    {
        for (size_t i = cantidad_de_caracteres; i > comienzo; i--)
        {
            destino[i-1] = '0' + (valor % 10) * signo;
            valor = valor / 10;
        }
        destino[cantidad_de_caracteres] = '\0';
        return true;
    }
}