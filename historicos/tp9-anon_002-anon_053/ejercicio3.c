

#include <stdio.h>

void mostrar_arreglo(int arreglo[], int tamano, int posicion);
void mostrar_arreglo_invertido(int arreglo[], int tamano, int posicion);
int sumar_valores(int arreglo[], int tamano, int posicion);

int main() 
{
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Arreglo original: ");
    mostrar_arreglo(arreglo, tamano, 0);

    printf("\nArreglo invertido: ");
    mostrar_arreglo_invertido(arreglo, tamano, tamano - 1);

    printf("\nSuma de valores: %d\n", sumar_valores(arreglo, tamano, 0));

    return 0;
}


void mostrar_arreglo(int arreglo[], int tamano, int posicion) 
{
    if (posicion < tamano) 
    {
        printf("%d ", arreglo[posicion]);
        mostrar_arreglo(arreglo, tamano, posicion + 1);
    }
}


void mostrar_arreglo_invertido(int arreglo[], int tamano, int posicion) 
{
    if (posicion >= 0) 
    {
        printf("%d ", arreglo[posicion]);
        mostrar_arreglo_invertido(arreglo, tamano, posicion - 1);
    }
}


int sumar_valores(int arreglo[], int tamano, int posicion) 
{
    if (posicion < tamano) 
    {
        return arreglo[posicion] + sumar_valores(arreglo, tamano, posicion + 1);
    } 
    else 
    {
        return 0;
    }
}

