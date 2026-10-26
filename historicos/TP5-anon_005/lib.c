#include "lib.h"

#define CADENA_CORTA -1

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i = 0;
    int largo = 0;
    while(i < capacidad_cadena)
    {
        if(cadena[i] == '\0')
        {
            return i;
        }
        else
        {
            largo = largo+1;
        }
        i++;
    }    
    if (largo > 1)
    {
        return largo;
    }
    else
    {
        return CADENA_CORTA;
    }
}