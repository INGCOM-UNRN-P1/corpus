#include <stdio.h>
#define SIZE 100




/**
 * Intercambia los valores de dos punteros a enteros.
 * @param izquierda Puntero al primer entero a intercambiar.
 * @param derecha Puntero al segundo entero a intercambiar.
 * @pre izquierda y derecha son punteros validos a enteros.
 * @post Los valores apuntados por izquierda y derecha han sido intercambiados.
 */
void intercambia (int * izquierda, int * derecha)
{
    int temp = *izquierda;
    *izquierda = *derecha;
    *derecha = temp;
}




/**
 * Invierte un arreglo de enteros.
 * @param arreglo Arreglo de enteros que se invertira.
 * @param tamaño Tamaño del arreglo.
 * @pre arreglo es un arreglo valido de enteros y tamaño es mayor o igual a cero.
 * @post Los elementos del arreglo han sido invertidos.
 */

void invertir (int arreglo[], int tamaño)
{
    int inicio = 0;
    int fin = tamaño - 1;
    while(inicio < fin)
    {
        intercambia(&arreglo[inicio], &arreglo[fin]);
        inicio++;
        fin--;
    }
}

int main()
{
    int arreglo[SIZE];
    int tamaño;
    int i;
    printf("Ingrese el tamanio del arreglo: ");
    scanf("%d", &tamaño);
    for (i = 0; i< tamaño; i++)
    {
        scanf("%d", &arreglo[i]);
    }
    printf("El arreglo es: \n");
    for (i=0;i<tamaño;i++)
    {
        printf(" %d ", arreglo[i]);
    }
    invertir(arreglo,tamaño);
    printf("\nEl arreglo invertido es: \n");
    for (i=0;i<tamaño;i++)
    {
        printf(" %d ",arreglo[i]);
    }
    return 0;
}