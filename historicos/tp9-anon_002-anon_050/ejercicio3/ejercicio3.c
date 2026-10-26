



#include <stdio.h>

/**
 * Imprime los elementos de un arreglo en orden.
 *
 * @pre tamaño >= 0
 * @param arre El arreglo que se desea imprimir.
 * @param tamaño El tamaño del arreglo.
 */
void mostrar_arreglo(int arre[], int tamaño)
{
    if (tamaño == 0)
    {
        printf("\n");
    }
    else
    {
        printf("%d ", arre[0]);
        mostrar_arreglo(arre + 1, tamaño - 1);
    }
}

/**
 * Imprime los elementos de un arreglo en orden inverso.
 *
 * @pre tamaño >= 0
 * @param arre El arreglo que se desea imprimir.
 * @param tamaño El tamaño del arreglo.
 */
void mostrar_invertido(int arre[], int tamaño)
{
    if (tamaño == 0)
    {
        printf("\n");
    }
    else 
    {
        printf("%d ", arre[tamaño - 1]);
        mostrar_invertido(arre, tamaño - 1);
    }
}

/**
 * Calcula la suma de los elementos de un arreglo.
 *
 * @pre tamaño >= 0
 * @param arre El arreglo cuyos elementos se desean sumar.
 * @param tamaño El tamaño del arreglo.
 * @return La suma de los elementos del arreglo.
 */
int sumar_arreglo(int arre[], int tamaño)
{
    int ret;
    if (tamaño == 0)
    {
        ret = 0;
    }
    else 
    {
        ret = arre[0] + sumar_arreglo(arre + 1, tamaño - 1);
    }
    return ret;
}

int main() 
{
    int arre[] = {1, 2, 3, 4, 5};
    int tamaño = sizeof(arre) / sizeof(arre[0]);
    printf("Arreglo: ");
    mostrar_arreglo(arre, tamaño);
    printf("Arreglo invertido: ");
    mostrar_invertido(arre, tamaño);
    printf("Suma de valores: %d\n", sumar_arreglo(arre, tamaño));
    return 0;
}