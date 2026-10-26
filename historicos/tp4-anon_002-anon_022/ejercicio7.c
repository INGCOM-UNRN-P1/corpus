#include <stdio.h>
#define SIZE 500 



/**
 * Calcula el largo seguro de una cadena de caracteres.
 *
 * @param str Puntero a la cadena de caracteres.
 * @return La longitud de la cadena o un valor negativo si hay un error.
 * @pre str es un puntero valido a una cadena de caracteres.
 * @post Se devuelve la longitud de la cadena o un valor negativo si ocurre un error.
 */
int largo_seguro (char * str)
{
    char* puntero = str;
    int longitud;
    while (*puntero != '\0')
    {
        puntero++;
    }
    longitud = puntero - str;
    return longitud;
}


int main()
{
    char cadena[SIZE];
    int longitud;
    printf("Ingrese la cadena: ");
    scanf("%s", cadena);
    longitud = largo_seguro(cadena);
    printf("La longitud es: %d",longitud);
    return 0;
}
