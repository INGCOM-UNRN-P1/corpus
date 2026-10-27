

#include <stdio.h>

#include "funciones_seguras.h"



#define LONGCADENA 200

int main(int argc, char *argv[])
{
    char buscador[LONGCADENA];
    char string[LONGCADENA] = "implementar una funcion que retorne un puntero de una cadena a la primera ocurrencia de un string.\n";
    printf("Este programa buscara la palabra deseada dentro de la siguiente cadena:\n");
    printf("%s\n", string);
    printf("Que palabra u oracion desea buscar? ");
    fgets(buscador, LONGCADENA, stdin);
    fflush(stdin);
    int longitud = largo_cadena(string, LONGCADENA);
    char *puntero = busqueda(string, longitud+1, buscador);
    printf("La direccion del puntero es: 0x%x\n", puntero);
    if (puntero != NULL)
    {
        printf("Cadena encontrada.\n");
        printf("%s\n", puntero);
    }
    else
    {
        printf("Cadena no encontrada.\n");
    }
    return 0;
}