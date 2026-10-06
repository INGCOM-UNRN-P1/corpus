#include "cajero.h"

bool es_monto_valido(int monto)
{
    bool monto_positivo = monto > 0;
    bool multiplo_denominacion_minima = monto % DENOMINACION_MINIMA == 0;

    return monto_positivo && multiplo_denominacion_minima;
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad_billetes = 0;

    if (denominacion > 0)
    {
        cantidad_billetes = monto / denominacion;
    }

    return cantidad_billetes;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto = monto;

    if (denominacion > 0)
    {
        resto = monto % denominacion;
    }

    return resto;
}