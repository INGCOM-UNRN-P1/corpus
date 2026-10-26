/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>
#include "funciones_seguras.h"

#define LONGCADENA 200

int main(int argc, char *argv[])
{
    int resultado;
    char cadena1[LONGCADENA], cadena2[LONGCADENA];
    printf("Este programa limpiara el contenido de la primer cadena\n");
    printf("y lo pegara a continuacion de la segunda cadena.\n");
    printf("Ingrese una cadena de texto: ");
    fgets(cadena1, LONGCADENA, stdin);
    fflush(stdin);
    resultado = limpiadora(cadena1, cadena2, LONGCADENA);
    printf("La seguna cadena es: %s", cadena2);
    printf("Longitud de la segunda cadena: %d\n", resultado);
    return 0;
}