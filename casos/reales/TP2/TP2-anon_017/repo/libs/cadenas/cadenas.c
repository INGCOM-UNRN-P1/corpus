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
    (void)cadena;
    (void)capacidad;
    

    size_t total = 0;
    if((cadena == NULL) || (capacidad == 0))
    {
        total = 0;
    }
    else
    {
        size_t contador = 0;
        while((cadena[contador] != '\0') && (contador < capacidad))
        {
            contador = contador + 1;
        }
        total = contador;
    }
    return total;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    (void)destino;
    (void)capacidad;
    (void)origen;
    

    bool modificado = true;

    if((destino == NULL) || (capacidad == 0))
    {
        modificado = false;
    }
    else
    {
        size_t total_caracteres = cadena_longitud(origen, capacidad);
        size_t indice = 0;
        if(total_caracteres < capacidad)
        {
            while((indice < capacidad) && (origen[indice] != '\0'))
            {
                destino[indice] = origen[indice];
                indice = indice + 1;
            }
            destino[indice] = '\0';
            modificado = true;
        }
        else
        {
            size_t terminar = capacidad - 1;
            while(indice < terminar)
            {
                destino[indice] = origen[indice];
                indice = indice + 1;
            }
            destino[indice] = '\0';
            modificado = false;
        }
    }
    return modificado;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    (void)destino;
    (void)capacidad;
    (void)origen;
    

    bool modificado = true;
    bool terminador_encontrado = false;
    size_t indice = 0;
    size_t indice_origen = 0;

    while((indice < capacidad) && (destino[indice] != '\0'))
    {
        if(destino[indice + 1] == '\0')
        {
            terminador_encontrado = true;
        }
        indice = indice + 1;
    }

    size_t capacidad_sobrante = capacidad - indice;
    size_t total_caracteres = cadena_longitud(origen, capacidad_sobrante);

    if(total_caracteres < capacidad_sobrante)
    {
        while((indice < capacidad) && (terminador_encontrado == true))
        {
            if(origen[indice_origen] == '\0')
            {
                terminador_encontrado = false;
            }
            destino[indice] = origen[indice_origen];
            indice_origen = indice_origen + 1;
            indice = indice + 1;
        }
    }
    else
    {
        size_t terminar = capacidad - 1;
        while(indice < terminar)
        {
            destino[indice] = origen[indice_origen];
            indice = indice + 1;
            indice_origen = indice_origen + 1;
        }
        destino[indice] = '\0';
        modificado = false;
    }

    return modificado;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    (void)cadena;
    (void)capacidad;
    
    size_t total_convertidos = 0;
    if((cadena != NULL) && (capacidad > 0))
    {
        size_t contador = 0;
        while((contador < capacidad) && (cadena[contador] != '\0'))
        {
            if((cadena[contador] >= 97) && (cadena[contador] <= 122))
            {
                cadena[contador] = toupper(cadena[contador]);
                total_convertidos = total_convertidos + 1;
            }
            contador = contador + 1;
        }
    }

    return total_convertidos;
}



bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t desde, size_t hasta)
{
    bool recortado = true;
    if((destino == NULL) || (origen == NULL) || (capacidad == 0))
    {
        recortado = false;
    }
    else
    {
        size_t largo_origen = cadena_longitud(origen, capacidad);
        if(desde >= largo_origen)
        {
            destino[0] = '\0';
        }
        else
        {
            size_t contador = 0;
            while((contador < hasta) && (contador < capacidad - 1) && (origen[desde] != '\0'))
            {
                destino[contador] = origen[desde];
                contador = contador + 1;
                desde = desde + 1;
            }
            destino[contador] = '\0';
        }
    }

    return recortado;
}



