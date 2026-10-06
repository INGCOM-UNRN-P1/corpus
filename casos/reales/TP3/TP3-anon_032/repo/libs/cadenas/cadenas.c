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
#include <limits.h>


size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }
    
    size_t contador = 0;
    bool contando = true;
    while (contando == true && contador < capacidad)
    {
        if (cadena[contador] == '\0')
        {
            contando = false;
        }
        else
        {
            contador++;
        }
    }

    return contador;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    // Itera sobre todos los caracteres de origen que quepan en destino para 
    // buscar un caracter terminador, de no encontrarlo se entiende que no lo 
    // tenia u origen no cabe en destino y el retorno sera falso.
    bool origen_completo = false;
    size_t largo = 0;
    while(largo < capacidad && origen[largo] != '\0')
    {
        largo++;
    }
    if (largo < capacidad)
    {
        origen_completo = true;
    }
    else
    {
        largo--;
    }

    for (size_t i = 0; i < largo; i++)
    {
        destino[i] = origen[i];
    }
    destino[largo] = '\0';

    return origen_completo;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (origen == NULL || capacidad == 0)
    {
        return false;
    }

    bool cadena_completa = true;
    size_t largo_destino = cadena_longitud(destino, capacidad);
    size_t largo_origen = cadena_longitud(origen, capacidad);

    if((largo_destino + largo_origen) >= capacidad)
    {
        cadena_completa = false;
    }

    for (size_t i = 0; largo_destino < capacidad; i++)
    {
        destino[largo_destino] = origen[i];
        largo_destino++;
    }
    destino[largo_destino - 1] = '\0';

    return cadena_completa;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t convertidos = 0;
    size_t i = 0;
    while (i < capacidad || cadena[i] != '\0')
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            convertidos++;
            cadena[i] -= ('a' - 'A');
        }
        i++;
    }

    return convertidos;
}

bool cadena_subcadena(char destino[], size_t capacidad_destino, 
                    const char origen[], size_t capacidad_origen, 
                    size_t inicio, size_t cantidad)
{
    if(destino == NULL || 
        origen == NULL ||
        capacidad_destino == 0)
    {
        return false;
    }

    size_t largo_origen = cadena_longitud(origen, capacidad_origen);
    if (inicio > largo_origen)
    {
        destino[0] = '\0';
        return false;
    }

    bool estado_exitoso = true;
    if (cantidad > (capacidad_destino - 1))
    {
        cantidad = capacidad_destino - 1;
        estado_exitoso = false;
    }

    size_t i = 0;
    while(i < cantidad && origen[i + inicio] != '\0')
    {
        destino[i] = origen[i + inicio];
        i++;
    }

    destino[i] = '\0';
    return estado_exitoso;
}

bool cadena_de_entero(char destino[], size_t capacidad, int valor)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }
    if (valor == 0)
    {
        destino[0] = '0';
        destino[1] = '\0';
        return true;
    }


    bool es_negativo = false;
    bool es_intmin = false;
    if (valor == INT_MIN)
    {
        es_intmin = true;
        valor += 1;
    }
    if (valor < 0)
    {
        valor = -valor;
        es_negativo = true;
    }

    size_t digitos = 0;
    int valor_auxiliar = valor;
    while (valor_auxiliar != 0)
    {
        valor_auxiliar /= 10;
        digitos += 1;
    }
    int espacio_necesario = digitos + es_negativo + es_intmin + 1;
    if (espacio_necesario > capacidad)
    {
        return false;
    }

    size_t i = digitos + es_negativo;
    destino[i] = '\0';
    while(valor != 0)
    {
        int resto = valor % 10;
        // cascotazo salvaje aparece
        if (es_intmin)
        {
            resto++;
            es_intmin = false;
        }
        valor /= 10;
        destino[i - 1] = resto + '0';
        i--;
    }
    if (es_negativo)
    {
        destino[0] = '-';
    }

    return true;
}