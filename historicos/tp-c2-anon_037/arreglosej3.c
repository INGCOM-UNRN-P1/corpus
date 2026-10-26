#include <stdio.h>
#include <stdlib.h>
#define LARGO 5

int cargar_arreglo_prog(int cantidad, char *arreglo[], char *argv[]);
int muestra_arreglo(int cantidad, char *arreglo[]);


int main(int argc, char *argv[])
{
    char *arr[LARGO];

    cargar_arreglo_prog(LARGO, arr, argv);
    muestra_arreglo(LARGO, arr);
}


int cargar_arreglo_prog(int cantidad, char *arreglo[], char *argv[])
{
    int i = 0;

    for (i; i < cantidad; i++)
    {
        arreglo[i] = argv[i];
    }
    return 0;
}

int muestra_arreglo(int cantidad, char *arreglo[])
{
    int contt = 0;

    printf("\nEl valor del arreglo en la posicion [%d] es: %d", contt, arreglo[contt]);
    contt++;

    while (contt < LARGO)
    {
        printf("\nEl valor del arreglo en la posicion [%d] es: %d", contt, arreglo[contt]);
        contt++;
    }
    printf("\n\n");
}