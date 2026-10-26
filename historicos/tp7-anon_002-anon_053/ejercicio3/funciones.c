#include <stdio.h>

int largo_seguro(char* cadena) 
{
    int longitud = 0;
    while (cadena[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}
