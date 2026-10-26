#include <stdlib.h>
#include <stdio.h>

int *reserva_arreglo_enteros(int tamano)
{
    int *arreglo = (int *)malloc(tamano * sizeof(int));
    return arreglo;
}

void libera_arreglo_enteros(int *arreglo)
{
    free(arreglo);
}

int *duplica_arreglo(int *origen, int tamano)
{
    int *destino = (int *)malloc(tamano * sizeof(int));
    for (int i = 0; i < tamano; i++)
    {
        destino[i] = origen[i];
    }
    return destino;
}

int *elimina_elemento(int *arreglo, int tamano, int posicion)
{
    arreglo[posicion] = arreglo[tamano - 1];
    int *nuevo_arreglo = (int *)malloc((tamano - 1) * sizeof(int));
    for (int i = 0; i < tamano - 1; i++)
    {
        nuevo_arreglo[i] = arreglo[i];
    }
    free(arreglo);
    return nuevo_arreglo;
}

int *insertaElemento(int *arreglo, int *tamano, int posicion, int valor)
{
    int *nuevo_arreglo = (int *)malloc((*tamano + 1) * sizeof(int));
    for (int i = 0; i < posicion; i++)
    {
        nuevo_arreglo[i] = arreglo[i];
    }
    nuevo_arreglo[posicion] = valor;
    for (int i = posicion + 1; i < *tamano + 1; i++)
    {
        nuevo_arreglo[i] = arreglo[i - 1];
    }
    free(arreglo);
    *tamano += 1;
    return nuevo_arreglo;
}

int *fusiona_arreglos(int *arreglo1, int tamano1, int *arreglo2, int tamano2)
{
    int *nuevo_arreglo = (int *)malloc((tamano1 + tamano2) * sizeof(int));
    for (int i = 0; i < tamano1; i++)
    {
        nuevo_arreglo[i] = arreglo1[i];
    }
    for (int i = 0; i < tamano2; i++)
    {
        nuevo_arreglo[tamano1 + i] = arreglo2[i];
    }
    free(arreglo1);
    free(arreglo2);
    return nuevo_arreglo;
}

int main()
{
    int tamano1 = 5;
    int tamano2 = 3;
    int *arreglo1 = reserva_arreglo_enteros(tamano1);
    int *arreglo2 = reserva_arreglo_enteros(tamano2);
    for (int i = 0; i < tamano1; i++)
    {
        arreglo1[i] = i + 1;
    }

    for (int i = 0; i < tamano2; i++)
    {
        arreglo2[i] = (i + 1) * 10;
    }

    printf("Arreglo 1:\n");
    for (int i = 0; i < tamano1; i++)
    {
        printf("%d ", arreglo1[i]);
    }
    printf("\n");

    printf("Arreglo 2:\n");
    for (int i = 0; i < tamano2; i++)
    {
        printf("%d ", arreglo2[i]);
    }
    printf("\n");

    int *duplicado = duplica_arreglo(arreglo1, tamano1);
    printf("Arreglo duplicado:\n");
    for (int i = 0; i < tamano1; i++)
    {
        printf("%d ", duplicado[i]);
    }
    printf("\n");
    int posicion_a_eliminar = 2;
    int *arreglo_sin_elemento = elimina_elemento(arreglo2, tamano2, posicion_a_eliminar);
    printf("Arreglo 2 sin el elemento en la posición %d:\n", posicion_a_eliminar);
    for (int i = 0; i < tamano2 - 1; i++)
    {
        printf("%d ", arreglo_sin_elemento[i]);
    }
    printf("\n");
    int valor_a_insertar = 42;
    int posicion_a_insertar = 1;
    int nuevo_tamano = tamano2;
    int *arreglo_con_elemento = inserta_elemento(arreglo2, &nuevo_tamano, posicion_a_insertar, valor_a_insertar);
    printf("Arreglo 2 con el valor %d insertado en la posición %d:\n", valor_a_insertar, posicion_a_insertar);
    for (int i = 0; i < nuevo_tamano; i++)
    {
        printf("%d ", arreglo_con_elemento[i]);
    }
    printf("\n");
    int *arreglo_fusionado = fusiona_arreglos(arreglo1, tamano1, arreglo2, tamano2);
    printf("Arreglo fusionado:\n");
    for (int i = 0; i < tamano1 + tamano2; i++)
    {
        printf("%d ", arreglo_fusionado[i]);
    }
    printf("\n");
    libera_arreglo_enteros(arreglo1);
    libera_arreglo_enteros(arreglo2);
    libera_arreglo_enteros(duplicado);
    libera_arreglo_enteros(arreglo_sin_elemento);
    libera_arreglo_enteros(arreglo_con_elemento);
    libera_arreglo_enteros(arreglo_fusionado);

    return 0;
}
