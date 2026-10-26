#include "fecha.h"

#define DIAS_MES_LARGO 31
#define DIAS_MES_CORTO 30
#define DIAS_FEBRERO_BISIESTO 29
#define DIAS_FEBRERO_COMUN 28

bool es_bisiesto(int anio)
{
    bool regla_comun = (anio % 4 == 0 && anio % 100 != 0);
    bool regla_secular = (anio % 400 == 0);
    return (anio > 0 && (regla_comun || regla_secular));
}

int dias_en_mes(int mes, int anio)
{
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return DIAS_MES_LARGO;
        case 4:
        case 6:
        case 9:
        case 11:
            return DIAS_MES_CORTO;
        case 2:
            if (es_bisiesto(anio))
            {
                return DIAS_FEBRERO_BISIESTO;
            }
            return DIAS_FEBRERO_COMUN;
        default:
            return 0;
    }
}

bool es_fecha_valida(int dia, int mes, int anio)
{
    int dias_max;

    if (anio <= 0 || mes < 1 || mes > 12)
    {
        return false;
    }

    dias_max = dias_en_mes(mes, anio);
    return (dia >= 1 && dia <= dias_max);
}
