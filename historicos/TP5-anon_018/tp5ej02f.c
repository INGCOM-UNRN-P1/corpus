

#include <stdio.h>
#include "funciones_seguras.h"

#define LONGCADENA 200

int main(int argc, char *argv[])
{
    int resultado;
    char cadena1[LONGCADENA], cadena2[LONGCADENA];
    printf("El siguiente programa compara dos cadenas de caracteres\n");
    printf("Ingrese una cadena de texto: ");
    fgets(cadena1, LONGCADENA, stdin);
    fflush(stdin);
    printf("Ingrese otra cadena de texto: ");
    fgets(cadena2, LONGCADENA, stdin);
    fflush(stdin);
    resultado = compara(cadena1, cadena2);
    printf("%d\n", resultado);
    if(resultado == -1)
    {
        printf("La primer cadena va antes de la segunda.\n");
    }
    if(resultado == 1)
    {
        printf("La segunda cadena va antes de la.\n");
    }
    else
    {
        printf("Ambas cadenas son iguales.\n");
    }

    return 0;
}