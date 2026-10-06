
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

    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    while (longitud < capacidad && cadena[longitud] != '\0')
    {
        longitud++;
    }

    return longitud;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    size_t indice = 0;
    bool copiado_completo = true;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    while (indice < capacidad - 1 && origen[indice] != '\0')
    {
        destino[indice] = origen[indice];
        indice++;
    }

    destino[indice] = '\0';

    if (origen[indice] != '\0')
    {
        copiado_completo = false;
    }

    return copiado_completo;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    size_t escritura = 0;
    size_t lectura = 0;
    bool concatenado = true;


    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    escritura = cadena_longitud(destino, capacidad);

    if (escritura >= capacidad)
    {
        return false;
    }

    while (escritura < capacidad - 1 && origen[lectura] != '\0')
    {
        destino[escritura] = origen[lectura];
        escritura++;
        lectura++;
    }

    destino[escritura] = '\0';

    if (origen[lectura] != '\0')
    {
        concatenado = false;
    }

    return concatenado;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t lectura = 0;
    size_t convertidos = 0;

    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    while (lectura < capacidad && cadena[lectura] != '\0')
    {
        if (cadena[lectura] >= 'a' && cadena[lectura] <= 'z')
        {
            cadena[lectura] = (char)(cadena[lectura] - ('a' - 'A'));
            convertidos++;
        }
        lectura++;
    }

    return convertidos;
}

bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
{
    size_t longitud = 0;
    size_t escritura = 0;
    size_t lectura = 0;
    size_t extraidos = 0;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    longitud = cadena_longitud(origen, (size_t)-1);

    if (inicio >= longitud)
    {
        destino[0] = '\0';
        return true;
    }

    lectura = inicio;

    while (escritura < capacidad - 1 && extraidos < cantidad && origen[lectura] != '\0')
    {
        destino[escritura] = origen[lectura];
        escritura++;
        lectura++;
        extraidos++;
    }

    destino[escritura] = '\0';

    if (extraidos < cantidad && origen[lectura] != '\0')
    {
        return false;
    }

    return true;
}

bool cadena_de_entero(char destino[], size_t capacidad, int valor)
{
    unsigned int magnitud = 0;
    char temporal[16];
    size_t invertido = 0;
    size_t escritura = 0;
    bool negativo = false;

    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    if (valor < 0)
    {
        negativo = true;
        magnitud = 0 - (unsigned int)valor;
    }
    else
    {
        magnitud = (unsigned int)valor;
    }

    do
    {
        temporal[invertido] = (char)('0' + (magnitud % 10));
        invertido++;
        magnitud /= 10;
    } while (magnitud > 0);

    if (negativo)
    {
        if (escritura >= capacidad - 1)
        {
            destino[0] = '\0';
            return false;
        }
        destino[escritura] = '-';
        escritura++;
    }

    while (invertido > 0)
    {
        if (escritura >= capacidad - 1)
        {
            destino[escritura] = '\0';
            return false;
        }
        invertido--;
        destino[escritura] = temporal[invertido];
        escritura++;
    }

    destino[escritura] = '\0';
    return true;
}
