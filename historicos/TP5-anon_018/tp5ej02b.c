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
    char cadena1[LONGCADENA], cadena2[LONGCADENA];
    printf("Este programa insertara la primer cadena dentro de otra en la posicion requerida.\n");
    printf("Ingrese una cadena de texto: ");
    fgets(cadena1, LONGCADENA, stdin);
    fflush(stdin);
    printf("Ingrese otra cadena de texto: ");
    fgets(cadena2, LONGCADENA, stdin);
    fflush(stdin);
    //funcion encargada de confirmar que el numero ingresado sea >0
    int pos = lee_numero_natural("Ingrese un numero natural para la posicion: ", 2);
    printf("La posicion leida es %d\n", pos);
    resultado = insercion(cadena2, LONGCADENA, cadena1, pos);
    printf("El largo de la cadena destino es: %d\n", resultado);
    printf("La cadena modificada es: %s\n", cadena2);
    return 0;
}