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

    size_t posicion = 0;
    while (posicion < capacidad && cadena[posicion] != '\0')
    {
        posicion++;
    }
    return posicion;
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
        return false;
    }

    size_t posicion = 0;
    while (posicion < capacidad - 1 && origen[posicion] != '\0')
    {
        destino[posicion] = origen[posicion];
        posicion++;
    }
    destino[posicion] = '\0';

    return origen[posicion] == '\0';
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    size_t len_dest = 0;
    while (len_dest < capacidad && destino [len_dest] != '\0')
    {
        len_dest++;
    }

    if (len_dest == capacidad)
    {
        destino[capacidad - 1] = '\0';
        return false;
    }

    size_t i = 0;
    while (origen[i] != '\0' && len_dest + i < capacidad - 1)
    {
        destino[len_dest + i] = origen [i];
        i++;
    }
    destino[len_dest + i] = '\0';

    return origen[i] == '\0';
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t convertidos = 0;

    for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = (char)(cadena[i] - 'a' + 'A');
            convertidos++;
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
    destino[0] = '\0';

    if (origen == NULL)
    {
        return false;
    }

    size_t pos = 0;
    while (pos < inicio && origen[pos] != '\0')
    {
        pos++;
    }

    if (pos < inicio)
    {
        return false;
    }

    size_t copiados = 0;
    while (copiados < cantidad && origen[inicio + copiados] != '\0' && copiados < capacidad - 1)
    {
        destino[copiados] = origen[inicio + copiados];
        copiados++;
    }
    destino[copiados] = '\0';

    return !(copiados < cantidad && origen[inicio + copiados] != '\0');
}



bool cadenas_de_entero(char destino [], size_t capacidad, int valor)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    bool negativo = valor < 0;

    size_t digitos = 0;
    int temp = valor;
    do 
    {
        digitos++;
        temp /= 10;
    }
    while (temp != 0);

    size_t longitud = digitos;
    if (negativo)
    {
        longitud++;
    }

    if (longitud >= capacidad)
    {
        destino[0] = '\0';
        return false;
    }

    destino[longitud] = '\0';
    size_t pos = longitud;
    int resto = valor;
    do 
    {
        pos--;
        int digito = resto % 10;
        if (digito < 0)
        {
            digito = -digito;
        }
        destino[pos] = (char)('0' + digito);
        resto /= 10;
    }
    while (resto != 0);

    if (negativo) 
    {
        destino[0] = '-';
    }
    
    return true;
}
