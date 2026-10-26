

#include <stdio.h>
#define BUFFER_SIZE 100

/**
 * La función cuenta la cantidad de elementos en una cadena.
 *  @param str, cadena a operar.
 *  @pre char válido.
 *  @param largo, largo a determinar de la cadena.
 *  @pre int sin signo válido.
 *  @post int sin signo válido.
 *  @return el largo de la cadena.
**/
int largo_seguro(char *str, int capacidad)
{
    int largo = 0;
    while (largo < capacidad && *(str + largo) != '\0')
    {
        largo++;
    }
    return largo;
}

int main()
{
    int capacidad = BUFFER_SIZE;
    char str[] = "Es tarde";
    printf("La longitud es %d\n", largo_seguro(str, capacidad));
    return 0;
}