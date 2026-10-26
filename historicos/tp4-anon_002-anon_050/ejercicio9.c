

#include <stdio.h>

/**
 * La función elimina duplicados de un arreglo.
 * @param arreglo a invertir.
 * @pre int válido.
 * @param tamano tamaño del arreglo.
 * @pre int sin signo válido.
 * @return largo de la nueva cadena sin duplicados
 * @post int sin signo válido
 */
int matacopia(int* arreglo, int tamano)
{
    int *p = arreglo;
    int *q = arreglo + 1;
    int largo = tamano;

    while (q < arreglo + tamano)
    {
        if (*p == *q)
        {
            q++;
            largo--;
        }
        else
        {
            p++;
            *p = *q;
            q++;
        }
    }
    return largo;
}

int main()
{
    int i;
    int nuevo_tamano;
    int arreglo[] = {1, 2, 3, 3, 2, 5};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Cadena antes de limpiar: ");
    for (i = 0; i < tamano; i++)
    {
        printf("%d ", *(arreglo + i));
    }
    printf("\n");
    nuevo_tamano = matacopia(arreglo, tamano);

    printf("Cadena luego de ser limpiada: ");
    for (i = 0; i < nuevo_tamano; i++)
    {
        printf("%d ", *(arreglo + i));
    }
    printf("\nNuevo tamaño de la cadena: %d", nuevo_tamano);

    return 0;
}