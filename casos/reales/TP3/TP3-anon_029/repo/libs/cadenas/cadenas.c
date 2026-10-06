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
    size_t indice = 0;
    if (cadena == NULL)
    {
        return 0;
    }
    while (indice < capacidad && cadena[indice] != '\0')
    {
        indice++;
    }
    if (indice == capacidad)
    {
        return capacidad;
    }
    return indice;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    size_t largo = 0;
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }
    while (largo < capacidad - 1 && origen [largo] != '\0')
    {
        destino[largo] = origen[largo];
        largo ++;
    }
    destino[largo] = '\0';
    if (origen[largo] != '\0')
    {
        return false;
    }
    return true;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    size_t posicion = 0;
    size_t largo_destino = 0;
    if (destino == NULL || origen == NULL) 
    {
        return false;
    }
    while (destino[largo_destino] != '\0') 
    // calcula longitud de la cadena destino
    {
        largo_destino++;
    }
    if (largo_destino == capacidad)
    //destino no tenia un \0 valido dentro de la capacidad
    {
        return false;
    }
    
    while (origen[posicion] != '\0' &&
        (largo_destino + posicion) < capacidad - 1)
        //bucle de copia
        {
        destino[largo_destino + posicion] = origen[posicion];
        posicion ++;
    }
    destino[largo_destino + posicion] = '\0';
        if (origen[posicion] != '\0')
        {
            return false;
        }
        
    return true;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t indice = 0;
    size_t transformados = 0;
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }
    for (indice = 0; indice < capacidad && cadena[indice] != '\0'; indice ++)
    {
        if (cadena[indice] >= 'a' && cadena[indice] <= 'z')
        //cambia el valor de la letra en mediante el codigo ASCCI
        {
            cadena[indice] = cadena[indice] - 32;
            transformados ++;
        }
    }
    return transformados;
}

bool cadena_subcadena(char destino[], size_t capacidad,
                      const char origen[], size_t inicio, size_t cantidad)
{
    size_t indice = 0;
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    for (indice = 0; origen[inicio + indice] != '\0' &&
                     indice < capacidad - 1 && indice < cantidad;
         indice++)
    
    {
        destino[indice] = origen[inicio + indice];
    }
    destino[indice] = '\0';
    return true;
}

bool cadena_de_entero(char destino[], size_t capacidad, int valor)
{

    if (destino == NULL || capacidad == 0)
    {
        return false;
    }
    if (capacidad < 2)
    {
        destino[0] = '\0';
        return false;
    }
    if (valor == 0)
    {
        destino[0] = '0';
        destino[1] = '\0';
        return true;
    }

    long long numero = valor;
    bool es_negativo = false;
    size_t indice = 0;

    if (numero < 0)
    {
        es_negativo = true;
        numero = -numero;
    }
    while (numero > 0)
    {
        if (indice >= capacidad - 1)
        {
            return false;
        }
        destino[indice] = (numero % 10) + '0';
        // extraigo el digito y lo paso a ASCCI
        numero = numero / 10;
        // saco el ultimo digito a numero
        indice++;
        // avanzo en destino
    }
    if (es_negativo == true)
    {
        if (indice >= capacidad - 1)
        {
            return false;
        }
        destino[indice] = '-';
        indice++;
    }
    destino[indice] = '\0';
    size_t inicio = 0;
    size_t fin = indice - 1;
    char temp = '\0';
    while (inicio < fin)
    {
        temp = destino[inicio];
        destino[inicio] = destino[fin];
        destino[fin] = temp;
        inicio++;
        fin--;
    }
    destino[indice] = '\0';
    return true;
}