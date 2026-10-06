#include "cajero.h"

bool es_monto_valido(int monto)
{
    if (monto > 0){
        if (monto % 100 == 0) {
            return true;
        }else{
            return false;
        }

    }else{
        return false;
    }

}

int calcular_cantidad_billetes(int monto, int denominacion)
{
    int cantidad_billetes = 0;
    if (monto > 0 && denominacion > 0){
        cantidad_billetes = (monto / denominacion);
        return cantidad_billetes;
    }else{
        return 0;
    }   
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto_monto = 0;
    if (monto > 0 && denominacion > 0)
    {
        resto_monto = monto % denominacion;
        return resto_monto;
    }else{
        return 0;
    }
    
    
}
