/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"



bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    (void)arreglo;
    (void)cantidad;
    (void)minimo;
    (void)maximo;
    (void)promedio;

    bool estado_parametros = obtener_min_max(arreglo, cantidad, minimo, maximo);
    if((estado_parametros == false) || (promedio == NULL))
    {
        estado_parametros = false;
    }
    else
    {
        size_t contador = 0;
        int suma_total = 0;
        while(contador < cantidad)
        {
            suma_total = suma_total + *arreglo;
            contador = contador + 1;
            arreglo = arreglo + 1;
        }
        *promedio = suma_total / contador;
    }
    return estado_parametros;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    (void)arreglo;
    (void)cantidad;
    (void)limite_inf;
    (void)limite_sup;
    (void)coincidencias;

    bool manejo_errores = true;
    if((arreglo == NULL) || (cantidad == 0) || (coincidencias == NULL))
    {
        manejo_errores = false;
    }
    else
    {
        *coincidencias = 0;
        bool terminar = false;
        size_t contador = 0;
        while((contador < cantidad) && !terminar)
        {
            if((*arreglo >= limite_inf) && (*arreglo <= limite_sup))
            {
                *coincidencias = *coincidencias + 1;
            }
            else if(*arreglo > limite_sup)
            {
                terminar = true;
            }
            arreglo = arreglo + 1;
            contador = contador + 1;
        }
    }
    return manejo_errores;
}
