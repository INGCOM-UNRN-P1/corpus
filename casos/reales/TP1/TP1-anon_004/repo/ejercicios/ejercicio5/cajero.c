#include "cajero.h"
#include <stdbool.h>

bool es_monto_valido(int monto)
{
    if (monto <= 0)
    {
        return false;
    }

    return (monto % DENOMINACION_MINIMA == 0);
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    if (denominacion <= 0 || monto < 0)
    {
        return 0;
    }

    return monto / denominacion;
}

int calcular_resto_monto(int monto, int denominacion)
{
    if (denominacion <= 0 || monto < 0)
    {
        return 0;
    }

    return monto % denominacion;
}