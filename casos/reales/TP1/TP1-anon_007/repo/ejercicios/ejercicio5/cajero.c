#include "cajero.h"

bool es_monto_valido(int monto)
{
    bool validacion = false;
    if (monto > 0 && (monto % 100) == 0)
    {
        validacion = true;
    }
    return validacion;
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad = 0;
    if (es_monto_valido(monto))
    {
        cantidad = monto / denominacion;
    }
    return cantidad;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto = monto;
    if (es_monto_valido(monto))
    {
        resto = monto - ((monto / denominacion) * denominacion);
    }
    return resto;
}
