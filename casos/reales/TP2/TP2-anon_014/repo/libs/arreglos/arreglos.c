/**
 * @file arreglos.c
 * @brief Implementación de la biblioteca libarreglos.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL)
    {
        return 0;
    }

    long long suma = 0;

    for (size_t indice = 0; indice < cantidad; indice++)
    {
        suma = suma + arreglo[indice];
    }

    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL)
    {
        return ARREGLO_INDICE_NO_ENCONTRADO;
    }

    int indice_encontrado = ARREGLO_INDICE_NO_ENCONTRADO;
    size_t indice = 0;
    bool se_encontro = false;

    while ((se_encontro == false) && (indice < cantidad))
    {
        if (arreglo[indice] == buscado)
        {
            se_encontro = true;
            indice_encontrado = (int)indice;
        }
        indice++;
    }

    return indice_encontrado;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if ((arreglo == NULL) || (cantidad <= 1))
    {
        return;
    }

    for (size_t indice = 0; indice < cantidad / 2; indice++)
    {
        size_t indice_opuesto = cantidad - 1 - indice;
        int temporal = arreglo[indice];

        arreglo[indice] = arreglo[indice_opuesto];
        arreglo[indice_opuesto] = temporal;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }

    bool esta_ordenado = true;
    size_t indice = 1;

    while ((esta_ordenado == true) && (indice < cantidad))
    {
        if (arreglo[indice - 1] > arreglo[indice])
        {
            esta_ordenado = false;
        }
        indice++;
    }

    return esta_ordenado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL)
    {
        return 0;
    }

    size_t coincidencias = 0;

    for (size_t indice = 0; indice < cantidad; indice++)
    {
        if (arreglo[indice] == buscado)
        {
            coincidencias++;
        }
    }

    return coincidencias;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    if (arreglo == NULL)
    {
        return 0;
    }

    size_t escritura = 0;

    for (size_t lectura = 0; lectura < cantidad; lectura++)
    {
        if (arreglo[lectura] != valor)
        {
            arreglo[escritura] = arreglo[lectura];
            escritura++;
        }
    }

    return escritura;
}

size_t arreglo_fusionar(const int primero[], size_t cantidad_primero,
                         const int segundo[], size_t cantidad_segundo,
                         int destino[], size_t capacidad)
{
    if ((primero == NULL) || (segundo == NULL) || (destino == NULL))
    {
        return 0;
    }

    size_t indice_primero = 0;
    size_t indice_segundo = 0;
    size_t indice_destino = 0;

    while ((indice_primero < cantidad_primero) &&
           (indice_segundo < cantidad_segundo) &&
           (indice_destino < capacidad))
    {
        bool toma_del_primero =
            primero[indice_primero] <= segundo[indice_segundo];

        if (toma_del_primero == true)
        {
            destino[indice_destino] = primero[indice_primero];
            indice_primero++;
        }
        else
        {
            destino[indice_destino] = segundo[indice_segundo];
            indice_segundo++;
        }
        indice_destino++;
    }

    while ((indice_primero < cantidad_primero) &&
           (indice_destino < capacidad))
    {
        destino[indice_destino] = primero[indice_primero];
        indice_primero++;
        indice_destino++;
    }

    while ((indice_segundo < cantidad_segundo) &&
           (indice_destino < capacidad))
    {
        destino[indice_destino] = segundo[indice_segundo];
        indice_segundo++;
        indice_destino++;
    }

    return indice_destino;
}
