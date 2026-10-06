#include "cajero.h"

bool es_monto_valido(int monto)
{
    if (monto > 0 && monto % DENOMINACION_MINIMA == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad = 0;
    if (denominacion == 0)
    {
        return -1;
    }
    cantidad = monto / denominacion;
    return cantidad;
    return 0;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto = 0;
    if (denominacion < 0)
    {
        return -1;
    }

    int cantidad = calcular_cantidad_billetes(monto, denominacion);
    resto = monto - (denominacion * cantidad);

    return resto;
    return 0;
}
