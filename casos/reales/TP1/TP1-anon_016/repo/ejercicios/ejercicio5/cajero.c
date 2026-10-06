#include "cajero.h"

bool es_monto_valido(int monto)
{
    if(monto > 0 && monto % 100 == 0 )
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

    if (es_monto_valido(monto) == true)
    {
        cantidad = monto / denominacion;
        return cantidad;
    }
    
    
    return 0;
}

int calcular_resto_monto(int monto, int denominacion)
{
     int resto = 0;

    if (es_monto_valido(monto) == true)
    {
        resto = monto % denominacion;
        return resto;
    }
    
    
    return monto;
}
