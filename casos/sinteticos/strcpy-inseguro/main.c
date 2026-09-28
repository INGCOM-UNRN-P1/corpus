/**
 * Caso sintético del corpus: strcpy sin control del tamaño del destino.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char nombre[16];
    if (argc < 2)
    {
        return 1;
    }
    strcpy(nombre, argv[1]);
    printf("Hola, %s\n", nombre);
    return 0;
}
