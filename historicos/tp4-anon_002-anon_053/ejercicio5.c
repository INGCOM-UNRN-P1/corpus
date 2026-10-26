

#include <stdio.h>

#define ERROR -1

void MinimoMaximoSumaPromedio(int arreglo[], int longitud, int *minimo, int *maximo, int *suma, double *promedio);

int main() {
    int arreglo[] = {12, 5, 8, 23, 14};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    int minimo, maximo, suma;
    double promedio;

    MinimoMaximoSumaPromedio(arreglo, longitud, &minimo, &maximo, &suma, &promedio);

    printf("Mínimo: %d\n", minimo);
    printf("Máximo: %d\n", maximo);
    printf("Suma: %d\n", suma);
    printf("Promedio: %.2lf\n", promedio);

    return 0;
}



void MinimoMaximoSumaPromedio(int arreglo[], int longitud, int *minimo, int *maximo, int *suma, double *promedio) 
{
    int error = 0;
    if (longitud <= 0) 
    {
        error = ERROR;
    }

    *minimo = arreglo[0];
    *maximo = arreglo[0];
    *suma = arreglo[0];

    for (int i = 1; i < longitud; i++) 
    {
        if (arreglo[i] < *minimo) 
        {
            *minimo = arreglo[i];//contiene el minimo del arreglo
        }
        if (arreglo[i] > *maximo) 
        {
            *maximo = arreglo[i];//mostrara el maximo del arreglo 
        }
        *suma = *suma + arreglo[i];//mostrara la suma del arreglo
    }

    *promedio = (double)*suma / longitud;//mostrara el promedio del arreglo con coma
}