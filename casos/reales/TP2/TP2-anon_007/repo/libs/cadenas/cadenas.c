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


bool cadena_segura(const char cadena[], const size_t capacidad)
{
    bool es_segura = false;
    size_t contador = 0;
    if (cadena != NULL && capacidad > 0)
    {
        es_segura = true;
    }
    return es_segura;
}



size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    size_t largo = 0;
    if (cadena_segura(cadena, capacidad))
    {
        while (largo < capacidad && cadena[largo] != '\0')
        {
            largo++;
        }
    }
    return largo;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    size_t cadena_completa = false;
    size_t contador = 0;
    if (destino != NULL && cadena_segura(origen,capacidad))
    {
        //mientras contador sea menor a capacidad -1 y origen[contador] no sea el caracter terminador
        //copia los caracteres de origen a destino y aumenta el contador
        while (contador < capacidad - 1 && origen[contador] != '\0')
        {
            destino[contador] = origen[contador];
            contador++;
        }
        destino[contador] = '\0';
        //Si al final origen[contador] es el caracter terminador, se copió toda la cadena origen asique se copio correctamente! 
        if (origen[contador] == '\0')
        {
            cadena_completa = true;
        }
    }
    return cadena_completa;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    bool es_segura = false;
    if (destino != NULL && cadena_segura(origen, capacidad))
    {
        size_t largo_destino = cadena_longitud(destino, capacidad);
        size_t largo_origen = cadena_longitud(origen, capacidad);
        if ((largo_destino + largo_origen) < capacidad)
        {
            for (size_t i = 0; i < largo_origen; i++)
            {
                destino[largo_destino + i] = origen[i];
            }
            destino[largo_destino + largo_origen] = '\0';
            es_segura = true;
        }
        else if ((largo_destino + largo_origen) > capacidad)
        {
            for (size_t i = 0; i < capacidad - 1; i++)
            {
                destino[largo_destino + i] = origen[i];
            }
            destino[capacidad - 1] = '\0';
        }
    }
    return es_segura;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t cantidad = 0;
    char temp;
    if (cadena_segura(cadena, capacidad))
    {
        size_t largo_cadena = cadena_longitud(cadena,capacidad);
        for (size_t i = 0; i < largo_cadena; i++)
        {
            if (isalpha(cadena[i]))
            {
                if (islower(cadena[i]))
                {
                    temp = toupper(cadena[i]);
                    cadena[i] = temp;
                    cantidad++;
                }
            }   
        }
    }
    return cantidad;
}


bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
{
    bool es_seguro = false;
    if (cadena_segura(origen,capacidad) && destino != NULL)
    {
        size_t largo_origen = cadena_longitud(origen, capacidad);
        if (inicio < largo_origen)
        {
            for (size_t i = 0; i < cantidad && i < capacidad; i++)
            {
                destino[i] = origen[inicio + i];
            }
            destino[largo_origen] = '\0';
            es_seguro = true;
        }
        else
        {
            destino[0] = '\0';
        }
    }
    
    return es_seguro;
}

