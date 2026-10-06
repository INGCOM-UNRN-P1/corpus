#include "cajero.h"

bool es_monto_valido(int monto)
{
    bool es_positivo = (monto > 0);
    bool es_multiplo = (monto % DENOMINACION_MINIMA == 0);

    return (es_positivo && es_multiplo);
}

int calcular_cantidad_billetes(int monto, int denominacion)
{
   int cantidad = 0;
   
   if (monto > 0 && denominacion > 0)
   {
        cantidad = monto / denominacion;
   }

   return cantidad;
}

int calcular_resto_monto(int monto, int denominacion)
{
    int resto = 0;

    if (monto > 0 && denominacion > 0)
    {
        resto = monto % denominacion;
    }

    return resto;
}
