/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"

bool copiar_arreglo(const int *fuente, int *destino, size_t cantidad)
{
    bool resultado = false;

    if (fuente == NULL || destino == NULL)
    {
        resultado = false;
    }
    else if (cantidad == 0)
    {
        resultado = false;
    }
    else
    {
        const int *p_fuente = fuente;
        int *p_destino = destino;

        size_t contador = 0;

        while (contador < cantidad)
        {
            *p_destino = *p_fuente;

            p_fuente++;
            p_destino++;
            contador++;
        }
        resultado = true;
    }
    return resultado;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    bool exito = false;
    if (arreglo == NULL)
    {
        exito = false;
    }
    else if (cantidad == 0)
    {
        exito = false;
    }
    else
    {
        int *inicio = arreglo;

        int *final = arreglo + (cantidad - 1);

        while (inicio < final)
        {
            intercambiar(inicio, final);
            inicio++;

            final--;
        }
        exito = true;
    }
    return exito;
}