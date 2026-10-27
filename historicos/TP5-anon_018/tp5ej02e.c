

#include <stdio.h>
#include "funciones_seguras.h"

#define LONGCADENA 200

int main(int argc, char *argv[])
{
    int resultado;
    char cadena1[LONGCADENA], cadena2[LONGCADENA];
    printf("Este invertira el contenido de la cadena origen\n");
    printf("y lo pegara en la cadena destino.\n");
    printf("Ingrese una cadena de texto: ");
    fgets(cadena1, LONGCADENA, stdin);
    fflush(stdin);
    resultado = inversor(cadena1, cadena2, LONGCADENA);
    printf("La seguna cadena es: %s", cadena2);
    printf("Longitud de la segunda cadena: %d\n", resultado);

    return 0;
}