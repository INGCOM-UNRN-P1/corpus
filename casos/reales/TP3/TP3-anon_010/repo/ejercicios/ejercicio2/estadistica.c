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
    bool calculo_validado = false;
    double divisor = cantidad;

    if (promedio != NULL)
    {
        bool funcion_validada = obtener_min_max(arreglo, cantidad, minimo, maximo);
        if (funcion_validada != false)
        {
            long long resultado_suma = 0;
            const int *inicio = arreglo;
            const int *fin = arreglo + cantidad;

            while ( inicio < fin)
            {
                resultado_suma += *inicio;
                inicio++;
            }
            *promedio = resultado_suma / divisor;
            calculo_validado = true;
        }
    }
    return calculo_validado;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    bool validado = false;

    if (arreglo != NULL && coincidencias != NULL)
    {
        size_t contador_coincidencias = 0;
        const int *actual = arreglo;
        const int *fin = arreglo + cantidad;
        
        while (actual < fin)
        {
            const int valor_actual = *actual;
            if (valor_actual >= limite_inf && valor_actual <= limite_sup)
            {
                contador_coincidencias++;
            }
            actual ++;
        }

        *coincidencias = contador_coincidencias;        
        validado = true;
    }
    return validado;
}
