#include "cajero.h"

bool es_monto_valido(int monto)
{
    bool monto_valido = false;

    if (monto > 0)
    {
        if (monto % 100 == 0)
        {
            monto_valido = true;
        }
        else 
        {
            monto_valido = false;
        }
    }
    return monto_valido;
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad_billetes = 0;

    cantidad_billetes = monto / denominacion;

    return cantidad_billetes;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto_monto = 0;

    resto_monto = monto % denominacion;

    return resto_monto;
}
