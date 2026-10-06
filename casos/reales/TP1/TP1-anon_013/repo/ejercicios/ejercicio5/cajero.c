#include "cajero.h"

bool es_monto_valido(int monto)
{
    if (monto > 0 && (monto % DENOMINACION_MINIMA) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // (void)monto;
    // return false;
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad_billetes = monto / denominacion;
    return cantidad_billetes;
    // (void)monto;
    // (void)denominacion;
    // return 0;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto = monto % denominacion;
    return resto;
    // (void)monto;
    // (void)denominacion;
    // return 0;
}
