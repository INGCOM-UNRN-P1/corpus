



#include <stdio.h>
#include <stdlib.h>

// Parte A - Dinámico
/**
 * @param tamano Tamaño del arreglo de enteros a reservar.
 * @pre Entero válido.
 * @post Reserva memoria para un arreglo de enteros de tamaño especificado.
 * @return Puntero al arreglo de enteros recién asignado o NULL si falla la asignación de memoria.
 */
int* reserva_arreglo_enteros(int tamano) 
{
    int* arreglo = (int*)malloc(sizeof(int) * tamano);
    if (arreglo == NULL)
    {
        fprintf(stderr, "Error reservando memoria.\n");
        exit(1);
    }
    return arreglo;
}

/**
 * @param arreglo Puntero al arreglo de enteros a liberar.
 * @pre El puntero "arreglo" debe haber sido previamente asignado con reserva_arreglo_enteros.
 * @post Libera la memoria previamente reservada para el arreglo de enteros.
 */
void libera_arreglo_enteros(int* arreglo) 
{
    free(arreglo);
}

// Parte B - Duplicadora
/**
 * @param origen Puntero al arreglo de enteros original.
 * @pre El puntero "origen" debe apuntar a un arreglo de enteros válido.
 * @param tamano Tamaño del arreglo de enteros original.
 * @post Crea una copia del arreglo de enteros original en un nuevo arreglo dinámico.
 * @return Puntero al nuevo arreglo de enteros o NULL si falla la asignación de memoria.
 */
int* duplica_arreglo(int* origen, int tamano) 
{
    int* copia = (int*)malloc(tamano * sizeof(int));
    if (copia == NULL) 
    {
        return NULL;
    }

    for (int i = 0; i < tamano; i++) 
    {
        copia[i] = origen[i];
    }

    return copia;
}

// Parte C - Eliminadora
/**
 * @param arreglo Puntero al arreglo de enteros del cual se eliminará un elemento.
 * @pre El puntero "arreglo" debe apuntar a un arreglo de enteros válido.
 * @param tamano Tamaño del arreglo de enteros original.
 * @param posicion Posición del elemento a eliminar (debe estar en el rango [0, tamano-1]).
 * @post Elimina el elemento en la posición especificada y devuelve un nuevo arreglo.
 * @return Puntero al nuevo arreglo de enteros resultante o el mismo puntero "arreglo" si falla la asignación de memoria.
 */
int* elimina_elemento(int* arreglo, int tamano, int posicion) 
{
    if (posicion < 0 || posicion >= tamano) 
    {
        return arreglo;
    }

    int* nuevo_arreglo = (int*)malloc((tamano - 1) * sizeof(int));
    if (nuevo_arreglo == NULL) 
    {
        return arreglo;
    }

    for (int i = 0, j = 0; i < tamano; i++) 
    {
        if (i != posicion) 
        {
            nuevo_arreglo[j++] = arreglo[i];
        }
    }

    free(arreglo);
    return nuevo_arreglo;
}

// Parte D - Inserción
/**
 * @param arreglo Puntero al arreglo de enteros al que se agregará un elemento.
 * @pre El puntero "arreglo" debe apuntar a un arreglo de enteros válido.
 * @param tamano Puntero al tamaño del arreglo (se actualiza después de la inserción).
 * @param posicion Posición en la que se insertará el elemento (debe estar en el rango [0, *tamano]).
 * @param valor Valor del elemento a insertar.
 * @post Inserta un elemento en la posición especificada y devuelve un nuevo arreglo.
 * @return Puntero al nuevo arreglo de enteros resultante o el mismo puntero "arreglo" si falla la asignación de memoria.
 */
int* insertaElemento(int* arreglo, int* tamano, int posicion, int valor) 
{
    if (posicion < 0 || posicion > *tamano) 
    {
        return arreglo;
    }

    (*tamano)++;
    int* nuevo_arreglo = (int*)malloc((*tamano) * sizeof(int));
    if (nuevo_arreglo == NULL) 
    {
        return arreglo;
    }

    int i, j;
    for (i = 0, j = 0; i < *tamano; i++) 
    {
        if (i == posicion) 
        {
            nuevo_arreglo[i] = valor;
        } 
        else 
        {
            nuevo_arreglo[i] = arreglo[j++];
        }
    }

    free(arreglo);
    return nuevo_arreglo;
}

// Parte E - Fusionadora
/**
 * @param arreglo1 Puntero al primer arreglo de enteros.
 * @param tamano1 Tamaño del primer arreglo de enteros.
 * @param arreglo2 Puntero al segundo arreglo de enteros.
 * @param tamano2 Tamaño del segundo arreglo de enteros.
 * @pre Ambos punteros "arreglo1" y "arreglo2" deben apuntar a arreglos de enteros ordenados en orden ascendente.
 * @post Fusiona los dos arreglos ordenados en orden ascendente y devuelve un nuevo arreglo.
 * @return Puntero al nuevo arreglo de enteros resultante o NULL si falla la asignación de memoria.
 */
int* fusiona_arreglos(int* arreglo1, int tamano1, int* arreglo2, int tamano2) 
{
    int* resultado = (int*)malloc((tamano1 + tamano2) * sizeof(int));
    if (resultado == NULL) 
    {
        return NULL;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < tamano1 && j < tamano2) 
    {
        if (arreglo1[i] < arreglo2[j]) 
        {
            resultado[k++] = arreglo1[i++];
        } 
        else 
        {
            resultado[k++] = arreglo2[j++];
        }
    }

    while (i < tamano1) 
    {
        resultado[k++] = arreglo1[i++];
    }

    while (j < tamano2) 
    {
        resultado[k++] = arreglo2[j++];
    }

    return resultado;
}

int main()
{
    int tamano1 = 5;
    int* arreglo1 = reserva_arreglo_enteros(tamano1);
    for (int i = 0; i < tamano1; i++) 
    {
        arreglo1[i] = i * 2;
    }

    int tamano2 = 3;
    int* arreglo2 = reserva_arreglo_enteros(tamano2);
    for (int i = 0; i < tamano2; i++) 
    {
        arreglo2[i] = i * 3;
    }

    printf("Arreglo1: ");
    for (int i = 0; i < tamano1; i++) 
    {
        printf("%d ", arreglo1[i]);
    }
    printf("\n");

    printf("Arreglo2: ");
    for (int i = 0; i < tamano2; i++) 
    {
        printf("%d ", arreglo2[i]);
    }
    printf("\n");

    int* arreglo_fusionado = fusiona_arreglos(arreglo1, tamano1, arreglo2, tamano2);

    printf("Arreglo fusionado: ");
    for (int i = 0; i < tamano1 + tamano2; i++) 
    {
        printf("%d ", arreglo_fusionado[i]);
    }
    printf("\n");

    libera_arreglo_enteros(arreglo1);
    libera_arreglo_enteros(arreglo2);
    libera_arreglo_enteros(arreglo_fusionado);

    return 0;    
}