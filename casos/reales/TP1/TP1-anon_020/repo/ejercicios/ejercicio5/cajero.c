#include "cajero.h"

bool es_monto_valido(int monto)
{
    bool es_valido = false;
    if (monto > 0)
    {
        if ((monto % DENOMINACION_MINIMA) == 0)
        {
            es_valido = true;
        }
    }
    return es_valido;
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad = monto / denominacion;
    return cantidad;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto = monto % denominacion;
    return resto;
}
