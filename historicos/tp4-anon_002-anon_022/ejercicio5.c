#include <stdio.h> 
#define SIZE 100





/**
 * Calcula estadisticas sobre un arreglo de enteros.
 * @param arreglo Arreglo de enteros sobre el cual se calcularan las estadisticas.
 * @param longitud Longitud del arreglo.
 * @param minimo Puntero al entero donde se almacenara el valor minimo.
 * @param maximo Puntero al entero donde se almacenara el valor maximo.
 * @param suma Puntero al entero donde se almacenara la suma de los valores.
 * @param promedio Puntero al valor double donde se almacenara el promedio.
 * @pre arreglo es un arreglo valido de enteros y longitud es mayor o igual a cero.
 * @post minimo contiene el valor minimo, maximo contiene el valor maximo,
 *       suma contiene la suma de los valores y promedio contiene el promedio de los valores del arreglo.
*/
void estadisticas (int arreglo[], int longitud, int * minimo, int * maximo, int * suma, double * promedio)
{
    int i;
    double aux_promedio;
    if (longitud == 0)
    {
        *minimo = 0;
        *maximo = 0;
        *suma = 0;
        *promedio = 0.0;
        return;
    }
    *minimo = arreglo[0];
    *maximo = arreglo [0];
    *suma = 0;
    for (i = 0 ; i<longitud; i++)
    {
        if (arreglo[i] < *minimo)
        {
            *minimo = arreglo[i];
        }
        if (arreglo[i] > *maximo)
        {
            *maximo = arreglo[i];
        }
        *suma = *suma + arreglo[i];
    }
    *promedio = (double)*suma / longitud;
}

int main ()
{
    int arreglo[SIZE];
    int longitud; 
    int minimo;
    int maximo;
    int suma;
    double promedio;
    int i;
    printf("Ingrese la longitud del arreglo: ");
    scanf("%d", &longitud);
    for (i=0; i<longitud;i++)
    {
        scanf("%d", &arreglo[i]);
    }
    printf("El arreglo es: \n");
    for (i = 0; i<longitud; i++)
    {
        printf("Posicion [%d] -> %d\n", i, arreglo[i]);
    }
    estadisticas(arreglo,longitud, &minimo, &maximo, &suma, &promedio);
    printf("El minimo es: %d\n",minimo);
    printf("El maximo es: %d\n", maximo);
    printf("La suma es: %d\n",suma);
    printf("El promedio es: %.2lf",promedio);
    return 0;
}
