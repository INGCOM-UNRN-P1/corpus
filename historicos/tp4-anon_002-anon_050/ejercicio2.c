

#include <stdio.h>
#define BUFFER_SIZE 100

/**
 * La función intercambia posiciones en un arreglo, usando punteros.
 *  @param izquierda valor que termina a la derecha.
 *  @pre int válido.
 *  @param derecha valor que termina a la izquierda.
 *  @pre int válido.
 */
void intercambia(int* izquierda, int* derecha)
{
    int temp;

    temp = *izquierda;
    *izquierda = *derecha;
    *derecha = temp;
}

/**
 * La ordena un arreglo de menor a mayor.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param arreglo la cadena a promediar.
 *  @pre int válido con signo.
 */
int ordernar_arreglo(int capacidad, int* arreglo)
{
    int i;
    int j;
    for (i = 0; i < capacidad - 1; ++i)
    {
        for (j = i + 1; j < capacidad; ++j)
        {
            if (arreglo[i] > arreglo[j])
            {
                intercambia(&arreglo[i], &arreglo[j]);
            }
            
        }
    }
    return 0;
}

int main()
{
    int i;
    int capacidad;
    int arreglo[BUFFER_SIZE];

    printf("Por favor ingrese el largo de la cadena a cargar: ");
    scanf("%d", &capacidad);

    if (capacidad > BUFFER_SIZE)
    {
        printf("Límite excedido.\n");
        return 1;
    }

    for (i = 0; i < capacidad; i++)
    {
        printf("Ingrese el elemento número %d: ", i+1);
        scanf("%d", &arreglo[i]);
    }
    ordernar_arreglo(capacidad, arreglo);

    printf("El arreglo es:\n");
    for (int i = 0; i < capacidad; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");

    return 0;
}