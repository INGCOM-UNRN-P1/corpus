#include "cajero.h"

bool es_monto_valido(int monto)
{
    if (monto > 0 && 
        monto % 100 == 0)
    {
        return true;
    }
    return false;
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    return monto / denominacion;
}

int calcular_resto_monto(int monto, int denominacion)
{
    return monto % denominacion;
}
