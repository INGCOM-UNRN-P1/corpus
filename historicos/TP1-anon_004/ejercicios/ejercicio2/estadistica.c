#include "estadistica.h"

float calcular_promedio(float suma, int cantidad)
{
    if (cantidad <= 0)
    {
        return 0.0f;
    }
    return suma / (float)cantidad;
}

float actualizar_minimo(float actual_min, float nuevo_valor)
{
    if (nuevo_valor < actual_min)
    {
        return nuevo_valor;
    }
    return actual_min;
}

float actualizar_maximo(float actual_max, float nuevo_valor)
{
    if (nuevo_valor > actual_max)
    {
        return nuevo_valor;
    }
    return actual_max;
}
