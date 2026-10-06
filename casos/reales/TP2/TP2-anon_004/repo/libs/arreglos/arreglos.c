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
    long long suma = 0LL;
    size_t contador = 0;

    if (cantidad == 0 || arreglo == NULL)
    {
        return 0LL;
    }
    
    for (contador = 0; contador < cantidad; contador++)
    {
        suma = suma + arreglo[contador];
    }

    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t contador = 0;

    if (cantidad == 0 || arreglo == NULL)
    {
        return -1;
    }

    for (contador = 0; contador < cantidad; contador++)
    {
        if (buscado == arreglo[contador])
        {
            return contador;
        }
    }
    
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    size_t inicio = 0;
    size_t fin = 0;
    int temporal = 0;

    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    fin = cantidad - 1;

    while (inicio < fin)
    {
        temporal = arreglo[inicio];

        arreglo[inicio] = arreglo[fin];

        arreglo[fin] = temporal;

        inicio++;
        fin--;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    size_t posicion = 0;

    if (arreglo == NULL)
    {
        return false;
    }

    if (cantidad <= 1)
    {
        return true;
    }
    
    
    for (posicion = 0; posicion < cantidad - 1; posicion++)
    {
        if (arreglo[posicion] > arreglo[posicion + 1])
        {
            return false;
        }
        
    }

    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t contador = 0;
    size_t posicion = 0;

    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    
    for (posicion = 0; posicion < cantidad; posicion++)
    {
        if (arreglo[posicion] == buscado)
        {
            contador++;
        }
    }

    return contador;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t lectura = 0;
    size_t escritura = 0;

    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    
    for (lectura = 0; lectura < cantidad; lectura++)
    {
        if (arreglo[lectura] != valor)
        {
            arreglo[escritura] = arreglo[lectura];
            escritura++;
        }
    }

    return escritura;
}

size_t arreglo_fusionar(const int primero[], size_t cantidad_uno,
                        const int segundo[], size_t cantidad_dos,
                        int destino[], size_t capacidad)
{
    size_t indice_uno = 0;
    size_t indice_dos = 0;
    size_t escritura = 0;

    if (destino == NULL || capacidad == 0)
    {
        return 0;
    }
    if (primero == NULL && cantidad_uno > 0)
    {
        return 0;
    }
    if (segundo == NULL && cantidad_dos > 0)
    {
        return 0;
    }

    
    while (escritura < capacidad && indice_uno < cantidad_uno && indice_dos < cantidad_dos)
    {
        if (primero[indice_uno] <= segundo[indice_dos])
        {
            destino[escritura] = primero[indice_uno];
            indice_uno++;
        }
        else
        {
            destino[escritura] = segundo[indice_dos];
            indice_dos++;
        }
        escritura++;
    }

    
    while (escritura < capacidad && indice_uno < cantidad_uno)
    {
        destino[escritura] = primero[indice_uno];
        indice_uno++;
        escritura++;
    }

    
    while (escritura < capacidad && indice_dos < cantidad_dos)
    {
        destino[escritura] = segundo[indice_dos];
        indice_dos++;
        escritura++;
    }

    return escritura;
}
