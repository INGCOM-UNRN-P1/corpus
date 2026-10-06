

#include "ejercicio3.h"

long long factorial(int numero)
{
    long long resultado = 1;

    if (numero < 0)
    {
        return -1;
    }
    for (int i = 2; i <= numero; i++)
    {
        resultado = resultado * i;

    }
    return resultado;
}

long long combinatorio(int cantidad_elementos, int elementos_grupos)
{
    long long factorial_elementos = 0;
    long long factorial_grupos = 0;
    long long factorial_diferencia = 0;
    long long resultado = 0;

    if (elementos_grupos < 0)
    {
        return -1;
    }

    if (elementos_grupos > cantidad_elementos)
    {
        return -1;
    }

    if (cantidad_elementos < 0)
    {
        return -1;
    }

    factorial_elementos = factorial(cantidad_elementos);
    factorial_grupos = factorial(elementos_grupos);
    factorial_diferencia = factorial(cantidad_elementos - elementos_grupos);

    resultado = factorial_elementos / (factorial_grupos * factorial_diferencia);

    return resultado;
}