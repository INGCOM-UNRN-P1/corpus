

#include "ejercicio5.h"

int contar_digitos(int numero)
{
    int contador = 0;

    if (numero == 0)
    {
        return 1;
    }
    while (numero != 0)
    {
        numero = numero / 10;
        contador++;
    }
    return contador;
}

int sumar_digitos(int numero)
{
    int suma = 0;
    int digito = 0;

    if (numero < 0)
    {
        numero = -numero;
    }
    while (numero != 0)
    {
        digito = numero % 10;
        suma = suma + digito;
        numero = numero / 10;
    }

    return suma;
}

int invertir_numero(int numero)
{
    int invertido = 0;
    int digito = 0;

    while (numero != 0)
    {
        digito = numero % 10;
        invertido = (invertido * 10) + digito;
        numero = numero / 10;
    }
    return invertido;
}

int es_capicua(int numero)
{
    if (numero == invertir_numero(numero))
    {
        return 1;
    }
    return 0;
}