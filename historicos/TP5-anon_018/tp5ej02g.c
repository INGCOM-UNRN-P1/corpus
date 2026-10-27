

#include <stdio.h>
#include "funciones_seguras.h"

#define LONGCADENA 200

int main(int argc, char *argv[])
{
    int resultado;
    char cadena1[LONGCADENA], cadena2[LONGCADENA];
    printf("El siguiente programa le dira si la cadena ingresada es un palindromo\n");
    printf("Ingrese una cadena de texto: ");
    fgets(cadena1, LONGCADENA, stdin);
    fflush(stdin);
    resultado = es_palindromo(cadena1, LONGCADENA);
    
    if(resultado == -1)
    {
        printf("ERROR!!!\n");
    }
    if(resultado == 1)
    {
        printf("VERDADERO\n");
    }
    else
    {
        printf("FALSO\n");
    }

    return 0;
}