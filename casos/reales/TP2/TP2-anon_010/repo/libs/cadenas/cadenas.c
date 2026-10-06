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
    size_t longitud = 0;

    if (cadena != NULL)
    {
        while (longitud < capacidad && cadena[longitud] != '\0')
        {
            longitud++;
        }
    }
    return longitud;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{    
    bool completa = false;

    if (destino != NULL && capacidad > 0 && origen != NULL)
    {
        size_t i = 0;

        while (i < capacidad - 1 && origen[i] != '\0')
        {
            destino[i] = origen[i];
            i++;
        }

        destino[i] = '\0';
        if (origen[i] == '\0')
        {
            completa = true;
        }
    }
    return completa;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    bool completa = false;

    if (destino != NULL && capacidad > 0 && origen != NULL)
    {
        size_t inicio = 0;
        size_t i = 0;

        while (inicio < capacidad && destino[inicio] != '\0')
        {
            inicio++;
        }

        while (inicio + i < capacidad - 1 && origen[i] != '\0')
        {
            destino[inicio + i] = origen[i];
            i++;
        }

        destino[inicio + i] = '\0';

        if (origen[i] == '\0')
        {
            completa = true;
        }
    }
    return completa;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t conversiones = 0;

    if (cadena != NULL)
    {
        size_t i = 0;

        while (i < capacidad && cadena[i] != '\0')
        {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 'a' + 'A';
                conversiones++;
            }
            i++;
        }
    }
    return conversiones;
}


bool subcadena_segura(char destino[], size_t capacidad, const char origen[], size_t capacidad_origen, size_t inicio, size_t cantidad)
{
    bool completa = false;

    if (destino != NULL && capacidad > 0 && origen != NULL)
    {
        size_t longitud_origen = cadena_longitud(origen, capacidad_origen);
        size_t i = 0;

        while (i < capacidad - 1 && i < cantidad && inicio + i < longitud_origen)
        {
            destino[i] = origen[inicio + i];
            i++;
        }

        destino[i] = '\0';

        if (i == cantidad)
        {
            completa = true;
        }
        else
        {
            completa = false;
        }
    }
    return completa;
}

bool cadena_entero(char destino[], size_t capacidad, int valor)
{
    bool completa = false;

    if (destino != NULL && capacidad > 0)
    {
        bool negativo = (valor < 0);
        long long magnitud = 0;

        if (negativo)
        {
            magnitud = -(long long)valor;
        }
        else
        {
            magnitud = (long long)valor;
        }

        char digitos[20];

        size_t cantidad_digitos = 0;
        if (magnitud == 0)
        {
            digitos[cantidad_digitos] = '0';
            cantidad_digitos++;
        }
        else
        {
            while (magnitud > 0)
            {
                digitos[cantidad_digitos] = '0' + (magnitud % 10);
                magnitud = magnitud / 10;
                cantidad_digitos++;
            }
        }

        size_t total_caracteres = cantidad_digitos;

        if (negativo)
        {
            total_caracteres = total_caracteres + 1;
        }

        size_t i = 0;

        if (negativo && i < capacidad - 1)
        {
            destino[i] = '-';
            i++;
        }

        size_t j = cantidad_digitos;

        while (j > 0 && i < capacidad - 1)
        {
            j--;
            destino[i] = digitos[j];
            i++;
        }

        destino[i] = '\0';

        if (i == total_caracteres)
        {
            completa = true;
        }
    }
    return completa;
}