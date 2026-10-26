

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int qsort_ascendente(const void* a, const void* b)
{
    int lhs = *(int*)a;
    int rhs = *(int*)b;

    if (lhs < rhs) return -1;
    if (lhs > rhs) return 1;
    return 0;
}

int qsort_descendente(const void* a, const void* b)
{
    int lhs = *(int*)a;
    int rhs = *(int*)b;

    if (lhs < rhs) return 1;
    if (lhs > rhs) return -1;
    return 0;
}

int* leer_elementos(int cantidad, FILE* entrada)
{
    int* elementos = malloc(cantidad * sizeof(int));
    int i;

    for (i = 0; i < cantidad; i++)
    {
        fscanf(entrada, "%d", &elementos[i]);
    }

    return elementos;
}

int ordenar(FILE* entrada, FILE* salida, int (*funcion_ordenar)(const void *, const void *))
{
    int i;
    int cantidad;
    int* elementos;

    fscanf(entrada, "%d", &cantidad);
    
    elementos = leer_elementos(cantidad, entrada);
    qsort(elementos, cantidad, sizeof(int), funcion_ordenar);

    for (i = 0; i < cantidad; i++)
    {
        fprintf(salida, "%d\n", elementos[i]);
    }
    
    free(elementos);

    return 0;
}

int main(int argc, char *argv[])
{
    int resultado;


    FILE* archivo = fopen(argv[1], "r");
     if (!archivo)
    {
        fprintf(stderr, "Archivo no disponible.\n");
        return 0;
    }

    FILE* ordenado = fopen(argv[3], "w");
     if (!ordenado)
    {
        fprintf(stderr, "Archivo no escribible.\n");
        return 0;
    }

    if (strcmp(argv[2], "asc") == 0)
    {
        resultado = ordenar(archivo, ordenado, qsort_ascendente);
    }
    else if (strcmp(argv[2], "des") == 0)
    {
        resultado = ordenar(archivo, ordenado, qsort_descendente);
    }
    else
    {
        printf("Argumento invalido.\n");
        return 0;
    }

    return 0;
}