

#include <stdio.h>

/**
 * La función obtiene los valores mínimo, máximo, suma y promedio de un arreglo.
 *  @param arreglo a operar.
 *  @pre int válido.
 *  @param tamano a operar.
 *  @pre int sin signo válido.
 *  @param min almacena el valor mínimo de arreglo.
 *  @pre int válido.
 *  @param max almacena el valor mínimo de arreglo.
 *  @pre int válido.
 *  @param suma almacena la suma de valores de arreglo.
 *  @pre int válido.
 *  @param promedio almacena el promedio de valores de arreglo.
 *  @pre float válido.
 */
void estadisticas(int* arreglo, int tamano, int* min, int* max, int* suma, float* promedio)
{
    *min = arreglo[0];
    *max = arreglo[0];
    *suma = 0;

    for (int i = 0; i < tamano; i++)
    {
        if (arreglo[i] < *min)
        {
            *min = arreglo[i];
        }
        if (arreglo[i] > *max)
        {
            *max = arreglo[i];
        }
        *suma = *suma + arreglo[i];
    }
    *promedio = (float)*suma / tamano; //necesita ayudita
}

int main()
{
    int arreglo[] = {1, 8, 9, 5, 4, 6, 7};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    int min;
    int max;
    int suma;
    float promedio;
    
    estadisticas(arreglo, tamano, &min, &max, &suma, &promedio);

    printf("Mínimo; %d\nMaximo: %d\nSuma: %d\nPromedio: %.2f\n", min, max, suma, promedio);

    return 0;
}