#include "cajero.h"

bool es_monto_valido(int monto)
{
    return (monto > 0) && (monto % DENOMINACION_MINIMA == 0);
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    if (denominacion <= 0)
    {
        return 0;
    }

    return monto / denominacion;
}

int calcular_resto_monto(int monto, int denominacion)
{
    if (denominacion <= 0)
    {
        return monto;
    }

    return monto % denominacion;
}