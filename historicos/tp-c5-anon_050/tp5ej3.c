

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE* archivo = fopen(argv[1], "w");
    int cantidad = atoi(argv[2]);
    int inicio = atoi(argv[3]);
    int salto = atoi(argv[4]);
    int i;

    for (i = 0; i <= cantidad; i++, inicio += salto)
    {
        fprintf(archivo, "%d\n", inicio);
    }

    return 0;
}