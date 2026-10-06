

#include "ejercicio4.h"

int maximo_comun_divisor(int primer_numero, int segundo_numero)
{
    int temporal = 0;

    if (primer_numero == 0 && segundo_numero == 0)
    {
        return -1;
    }

    if (primer_numero < 0)
    {
        primer_numero = -primer_numero;
    }

    if (segundo_numero < 0)
    {
        segundo_numero = -segundo_numero;
    }

    while (segundo_numero != 0)
    {
        temporal = segundo_numero;
        segundo_numero = primer_numero % segundo_numero;
        primer_numero = temporal;
    }
    return primer_numero;
}

int minimo_comun_multiplo(int primer_numero, int segundo_numero)
{
    int mcd = 0;
    int resultado = 0;

    if (primer_numero <= 0 || segundo_numero <= 0)
    {
        return -1;
    }

    mcd = maximo_comun_divisor(primer_numero, segundo_numero);

    resultado = (primer_numero / mcd) * segundo_numero;

    return resultado;
}