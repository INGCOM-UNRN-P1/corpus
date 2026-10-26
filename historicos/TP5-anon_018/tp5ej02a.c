/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>
#include "funciones_seguras.h"

#define CADENACORTA -1
#define LONGCADENA 200

int main(int argc, char *argv[])
{
    int resultado;
    char cadena1[LONGCADENA];
    printf("El siguiente programa le devolvera el largo de la cadena.\n\n");
    printf("Ingrese una cadena de texto: ");
    fgets(cadena1, LONGCADENA, stdin);
    fflush(stdin);
    resultado = largo_cadena(cadena1, LONGCADENA);
    printf("La cadena tiene un largo de: %d\n", resultado);
    return 0;
}