/**
 * @file cadenas.c
 * @brief Implementación de la biblioteca libcadenas.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#include <string.h>
#include "cadenas.h"

enum
{
    CADENA_ITOA_MAX_DIGITOS = 20
};

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    if ((cadena == NULL) || (capacidad == 0))
    {
        return 0;
    }

    size_t indice = 0;

    while ((indice < capacidad) && (cadena[indice] != '\0'))
    {
        indice++;
    }

    return indice;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if ((destino == NULL) || (origen == NULL) || (capacidad == 0))
    {
        return false;
    }

    size_t indice = 0;

    while ((indice < capacidad - 1) && (origen[indice] != '\0'))
    {
        destino[indice] = origen[indice];
        indice++;
    }

    destino[indice] = '\0';

    return origen[indice] == '\0';
}

bool cadena_concatenar(char destino[], size_t capacidad,
                        const char origen[])
{
    if ((destino == NULL) || (origen == NULL) || (capacidad == 0))
    {
        return false;
    }

    size_t indice_destino = cadena_longitud(destino, capacidad);

    if (indice_destino > capacidad - 1)
    {
        indice_destino = capacidad - 1;
    }

    size_t indice_origen = 0;

    while ((indice_destino < capacidad - 1) &&
           (origen[indice_origen] != '\0'))
    {
        destino[indice_destino] = origen[indice_origen];
        indice_destino++;
        indice_origen++;
    }

    destino[indice_destino] = '\0';

    return origen[indice_origen] == '\0';
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL)
    {
        return 0;
    }

    size_t conversiones = 0;
    size_t indice = 0;

    while ((indice < capacidad) && (cadena[indice] != '\0'))
    {
        if ((cadena[indice] >= 'a') && (cadena[indice] <= 'z'))
        {
            cadena[indice] = (char)(cadena[indice] - 'a' + 'A');
            conversiones++;
        }
        indice++;
    }

    return conversiones;
}

bool cadena_subcadena(char destino[], size_t capacidad,
                       const char origen[], size_t inicio,
                       size_t cantidad)
{
    if ((destino == NULL) || (origen == NULL) || (capacidad == 0))
    {
        return false;
    }

    size_t longitud_origen = strlen(origen);
    size_t disponibles = 0;

    if (inicio < longitud_origen)
    {
        disponibles = longitud_origen - inicio;
    }

    size_t a_copiar = cantidad;

    if (a_copiar > disponibles)
    {
        a_copiar = disponibles;
    }

    bool entro_completo = true;

    if (a_copiar > capacidad - 1)
    {
        a_copiar = capacidad - 1;
        entro_completo = false;
    }

    for (size_t indice = 0; indice < a_copiar; indice++)
    {
        destino[indice] = origen[inicio + indice];
    }
    destino[a_copiar] = '\0';

    return entro_completo;
}

bool cadena_desde_entero(char destino[], size_t capacidad, int valor)
{
    if ((destino == NULL) || (capacidad == 0))
    {
        return false;
    }

    long long valor_amplio = valor;
    bool es_negativo = valor_amplio < 0;
    unsigned long long magnitud = 0;

    if (es_negativo == true)
    {
        magnitud = (unsigned long long)(-valor_amplio);
    }
    else
    {
        magnitud = (unsigned long long)valor_amplio;
    }

    char digitos[CADENA_ITOA_MAX_DIGITOS];
    size_t cantidad_digitos = 0;

    do
    {
        digitos[cantidad_digitos] = (char)('0' + (magnitud % 10));
        magnitud = magnitud / 10;
        cantidad_digitos++;
    } while (magnitud > 0);

    size_t longitud_total = cantidad_digitos;

    if (es_negativo == true)
    {
        longitud_total++;
    }

    bool entro_completo = (longitud_total <= capacidad - 1);
    size_t indice_destino = 0;

    if ((es_negativo == true) && (indice_destino < capacidad - 1))
    {
        destino[indice_destino] = '-';
        indice_destino++;
    }

    for (size_t indice_digito = cantidad_digitos; indice_digito > 0;
         indice_digito--)
    {
        if (indice_destino < capacidad - 1)
        {
            destino[indice_destino] = digitos[indice_digito - 1];
            indice_destino++;
        }
    }

    destino[indice_destino] = '\0';

    return entro_completo;
}
