

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    FILE* archivo = fopen(argv[1], "w");
    int cantidad = atoi(argv[2]);
    int inicio = atoi(argv[3]);
    int fin = atoi(argv[4]);
    int random;
    int i;

    srand(time(NULL));

    for(i = 0; i < cantidad; i++)
    {
        random = rand() % (fin + 1 - inicio) + inicio;
        fprintf(archivo, "%d\n", random);
    }

    return 0;
}