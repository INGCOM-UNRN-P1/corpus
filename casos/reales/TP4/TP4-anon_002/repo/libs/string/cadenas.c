/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include "cadenas.h"
#include <stdlib.h>

/**
 * @brief [completar: qué hace cadena_duplicar_segura]
 *
 * @param origen [completar: qué representa origen]
 * @param capacidad_max [completar: qué representa capacidad_max]
 * @return [completar: qué devuelve]
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    char *cadena_duplicada = NULL;
    if (origen == NULL || capacidad_max == 0)
    {
        cadena_duplicada = NULL;
    }
    else
    {
        size_t longitud = cadena_longitud(origen, capacidad_max);
        cadena_duplicada = malloc((longitud + 1) * sizeof(char));

        if (cadena_duplicada != NULL)
        {
            cadena_copiar(cadena_duplicada, longitud + 1, origen);
        }
    }
    return cadena_duplicada;
}

/**
 * @brief [completar: qué hace cadena_unir_dinamica]
 *
 * @param primera [completar: qué representa primera]
 * @param cap_primera [completar: qué representa cap_primera]
 * @param segunda [completar: qué representa segunda]
 * @param cap_segunda [completar: qué representa cap_segunda]
 * @return [completar: qué devuelve]
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    char *cadena_unida = NULL;

    if (primera == NULL || segunda == NULL)
    {
        cadena_unida = NULL;
    }
    else if (cap_primera == 0 || cap_segunda == 0)
    {
        cadena_unida = NULL;
    }
    else
    {
        size_t largo_primero = cadena_longitud(primera, cap_primera);
        size_t largo_segundo = cadena_longitud(segunda, cap_segunda);
        size_t largo_total = (largo_primero + largo_segundo) + 1;

        cadena_unida = malloc(largo_total * sizeof(char));

        if (cadena_unida != NULL)
        {
            cadena_copiar(cadena_unida, largo_total, primera);
            cadena_concatenar(cadena_unida, largo_total, segunda);
        }
    }
    return cadena_unida;
}

/**
 * @brief [completar: qué hace cadena_liberar_segura]
 *
 * @param puntero_cadena [completar: qué representa puntero_cadena]
 */
void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena != NULL && *puntero_cadena != NULL)
    {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}

/**
 * @brief [completar: qué hace cadena_subcadena_dinamica]
 *
 * @param origen [completar: qué representa origen]
 * @param capacidad_max [completar: qué representa capacidad_max]
 * @param inicio [completar: qué representa inicio]
 * @param cantidad [completar: qué representa cantidad]
 * @return [completar: qué devuelve]
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    char *subcadena = NULL;
    if (origen == NULL || capacidad_max == 0)
    {
        subcadena = NULL;
    }
    else
    {
        size_t largo_origen = cadena_longitud(origen, capacidad_max);

        if (inicio >= largo_origen)
        {
            subcadena = malloc(1);
            if (subcadena != NULL)
            {
                *subcadena = '\0';
            }
        }
        else
        {
            size_t disponible = largo_origen - inicio;
            size_t largo_extraido = 0;

            if (cantidad < disponible)
            {
                largo_extraido = cantidad;
            }
            else
            {
                largo_extraido = disponible;
            }
            subcadena = malloc((largo_extraido + 1) * sizeof(char));

            if (subcadena != NULL)
            {
                const char *origen_subcadena = origen + inicio;
                char *destino = subcadena;

                for (size_t i = 0; i < largo_extraido; i++)
                {
                    *destino = *origen_subcadena;
                    destino++;
                    origen_subcadena++;
                }
                *destino = '\0';
            }
        }
    }
    return subcadena;
}

/**
 * @brief [completar: qué hace cadena_invertir_dinamica]
 *
 * @param origen [completar: qué representa origen]
 * @param capacidad_max [completar: qué representa capacidad_max]
 * @return [completar: qué devuelve]
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    char *cadena_invertida = NULL;
    if (origen == NULL || capacidad_max == 0)
    {
        cadena_invertida = NULL;
    }
    else
    {
        size_t largo_origen = cadena_longitud(origen, capacidad_max);

        cadena_invertida = malloc((largo_origen + 1) * sizeof(char));

        if (cadena_invertida != NULL)
        {
            if (largo_origen == 0)
            {
                *cadena_invertida = '\0';
            }
            else
            {
                const char *lectura = origen + (largo_origen - 1);

                char *escritura = cadena_invertida;

                for (size_t i = 0; i < largo_origen; i++)
                {
                    *escritura = *lectura;
                    escritura++;
                    lectura--;
                }
                *escritura = '\0';
            }
        }
    }
    return cadena_invertida;
}

/**
 * implementacion de funciones reutilizadas del tp2
 * las agrego acá por fallo en compliacion, posible falla del makefile a la hora
 * de buscar librerias.
 */

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    size_t largo = 0;

    if (cadena == NULL || capacidad == 0)
    {
        largo = 0;
    }
    else
    {
        for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
        {
            largo++;
        }
    }
    return largo;
}


bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    bool cadena_copiada = false;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t largo = cadena_longitud(origen, capacidad - 1);

        for (size_t i = 0; i < largo; i++)
        {
            destino[i] = origen[i];
        }

        destino[largo] = '\0';

        if (origen[largo] == '\0')
        {
            cadena_copiada = true;
        }
    }

    return cadena_copiada;
}


bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    bool exito = false;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t largo_destino = cadena_longitud(destino, capacidad);
        size_t largo_origen = cadena_longitud(origen, capacidad);

        if (largo_destino < capacidad)
        {
            size_t largo_copiable =
                cadena_longitud(origen, capacidad - largo_destino - 1);

            for (size_t i = 0; i < largo_copiable; i++)
            {
                destino[largo_destino + i] = origen[i];
            }

            destino[largo_destino + largo_copiable] = '\0';

            if (largo_copiable == largo_origen)
            {
                exito = true;
            }
        }
    }

    return exito;
}
