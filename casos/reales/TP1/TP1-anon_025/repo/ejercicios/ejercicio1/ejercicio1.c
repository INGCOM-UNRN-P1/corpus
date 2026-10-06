

#include<stdio.h>
#include "ejercicio1.h"

int es_primo(int numero)
{
    if (numero <= 1)
{
    return 0;
}
else 
{
    for(int i = 2; numero > i; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
}

int proximo_primo(int numero_base)
{
    int candidato = numero_base + 1;
    while (es_primo(candidato) == 0)
    {
    candidato++;
    }
return candidato;
}
int cantidad_divisores(int numero)
{
    int contador = 0;

    for(int i = 1;  i <= numero; i++)
    {
    if (numero %i == 0)
    {
        contador++;
    }
}
return contador;
}