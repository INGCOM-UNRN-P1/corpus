#include <stdio.h>
#define SIZE 500



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
 * Ordena el arreglo realizando el movimiento de izquierda a derecha en vez de hacer las asignaciones entre posiciones
 * @param arreglo Arreglo de enteros a ordenar.
 * @param longitud Longitud del arreglo.
 * @pre arreglo es un arreglo valido de enteros y longitud es mayor o igual a cero.
 * @post El arreglo se encuentra ordenado en orden 
 */
void ordenar_arreglos (int arreglo[], int longitud)
{
  int i;
    int j;
    for (i=0; i<longitud; i++)
    {
        for (j=0; j<longitud-i-1; j++)
        {
            if (arreglo[j]>arreglo[j+1])
            {
                intercambia(&arreglo[j],&arreglo[j+1]);
            }
        }
    }
}


int main()
{
    int arreglo[SIZE];
    int longitud;
    int i;
    int * ordena; 
    printf("Ingrese la longitud del arreglo: \n");
    scanf("%d",&longitud);
    printf("Ingrese el arreglo con sus valores: \n");
    for (i = 0; i<longitud;i++)
    {
        scanf("%d",&arreglo[i]);
    }
    for (i= 0; i<longitud;i++)
    {
        printf("Posicion [%d] -> %d\n", i,arreglo[i]);
    }
    ordenar_arreglos(arreglo,longitud);
    printf("\nArreglo ordenado:\n");
    for (i=0; i<longitud;i++)
    {
        printf("Posicion [%d] ->%d\n",i,arreglo[i]);
    }
    
    return 0;
}