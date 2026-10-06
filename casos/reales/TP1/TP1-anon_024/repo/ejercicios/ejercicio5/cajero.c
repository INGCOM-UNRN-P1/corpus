#include "cajero.h"

bool es_monto_valido(int monto)
{
    if (monto > 0)
    {
        if (monto % DENOMINACION_MINIMA == 0)
        {
            return true;
        }
    }

    return false;
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad = monto / denominacion;
    return cantidad;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int residuo = monto % denominacion;
    return residuo;
}
