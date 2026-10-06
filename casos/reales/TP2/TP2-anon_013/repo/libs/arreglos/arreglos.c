/**
 * @file arreglos.c
 * @brief Esqueleto de implementación para la biblioteca libarreglos.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    else
    {
        long long suma = 0;
        for (size_t i = 0; i < cantidad; i++)
        {
            suma = suma + arreglo[i];
        }
        return suma;
    }
    // (void)arreglo;
    // (void)cantidad;
    // 
    // return 0;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t primera_aparicion = 0;
    bool encontrado = false;
    if (arreglo == NULL || cantidad == 0)
    {
        return -1;
    }

    for (size_t i = 0; i < cantidad && encontrado == false; i++)
    {
        if (arreglo[i] == buscado)
        {
            encontrado = true;
            primera_aparicion = i;
        }
    }
    if (encontrado == true)
    {
        return primera_aparicion;
    }
    else
    {
        return -1;
    }
    // (void)arreglo;
    // (void)cantidad;
    // (void)buscado;
    // 
    // return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }
    size_t inicio = 0;
    size_t fin = cantidad - 1;
    while (inicio < fin)
    {
        int auxiliar = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = auxiliar;
        inicio++;
        fin--;
    }
    // (void)arreglo;
    // (void)cantidad;
    // 
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }
    bool esta_ordenado = true;
    if (cantidad <= 1)
    {
        return true;
    }
    for (size_t i = 0; i < cantidad -1 && esta_ordenado == true; i++)
    {
        if (arreglo[i] > arreglo[i+1])
        {
            esta_ordenado = false;
        }
    }
    return esta_ordenado;
    // (void)arreglo;
    // (void)cantidad;
    // 
    // return false;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    size_t cantidad_ocurrencias = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        {
            cantidad_ocurrencias++;
        }
    }
    return cantidad_ocurrencias;
    // (void)arreglo;
    // (void)cantidad;
    // (void)buscado;
    // 
    // return 0;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    size_t indice_lector = 0;
    size_t indice_escritor = 0;
    // Compacta el arreglo al inicio
    for (; indice_lector < cantidad; indice_lector++)
    {
        if (arreglo[indice_lector] != valor)
        {
            arreglo[indice_escritor] = arreglo[indice_lector];
            indice_escritor++;
        }
    }
    // Coloca 0 en las posiciones finales
    for (size_t i = indice_escritor; i < cantidad; i++)
    {
        arreglo[i] = 0;
    }
    // Devuelve la cantidad de elementos válidos / largo del nuevo arreglo
    return indice_escritor;
}


size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad)
{
    if (primero == NULL || segundo == NULL || destino == NULL)
    {
        return 0;
    }
    size_t recorrer_primero = 0;
    size_t recorrer_segundo = 0;
    size_t recorrer_destino = 0;
    while (recorrer_primero < cantidad_uno && recorrer_segundo < cantidad_dos && recorrer_destino < capacidad)
    {
        if (primero[recorrer_primero] <= segundo[recorrer_segundo])
        {
            destino[recorrer_destino] = primero[recorrer_primero];
            recorrer_primero++;
        }
        else if (primero[recorrer_primero] > segundo[recorrer_segundo])
        {
            destino[recorrer_destino] = segundo[recorrer_segundo];
            recorrer_segundo++;
        }
        recorrer_destino++;
    }

    if (recorrer_primero == cantidad_uno)
    {
        while (recorrer_segundo < cantidad_dos && recorrer_destino < capacidad)
        {
            destino[recorrer_destino] = segundo[recorrer_segundo];
            recorrer_segundo++;
            recorrer_destino++;
        }
    }
    else if (recorrer_segundo == cantidad_dos)
    {
        while (recorrer_primero < cantidad_uno && recorrer_destino < capacidad)
        {
            destino[recorrer_destino] = primero[recorrer_primero];
            recorrer_primero++;
            recorrer_destino++;
        }
    }
    return recorrer_destino;
}

