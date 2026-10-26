

#include <stdio.h>
#include <string.h>

/**
 * La función intercambia caracteres en una cadena.
 *  @param cadena a operar.
 *  @pre char válido.
 *  @param capacidad_cadena, largo de la cadena.
 *  @pre int sin signo válido.
 *  @param origen caracter a modificar.
 *  @pre int sin signo válido.
 *  @param destino caracter a copiar en la posición de origen.
 *  @pre int sin signo válido.
 */
int intercambia(char cadena[], int capacidad_cadena, int origen, int destino)
{
    char temp;
    int ret;
    if (origen < 0 || origen >= capacidad_cadena || destino < 0 || destino >= capacidad_cadena)
    {
        ret = -1;
    }
    else
    {
        temp = *(cadena + destino);
        *(cadena + origen) = *(cadena + destino);
        *(cadena + destino) = temp;
        ret = 0;
    }
    return ret;
}

int main()
{
    char cadena[] = "Tengo sueño";
    int capacidad_cadena = strlen(cadena);
    
    printf("Cadena original: %s\n", cadena);
    intercambia(cadena, capacidad_cadena, 1, 4);
    printf("Nueva cadena: %s\n", cadena);
    
    return 0;
}