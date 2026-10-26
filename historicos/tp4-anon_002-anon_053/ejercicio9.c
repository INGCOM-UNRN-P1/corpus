

#include <stdio.h>

#define ERROR -1

int invertir(int arreglo[], int tamaño);

int main() 
{
    int arreglo[] = {2, 4, 6, 8, 10};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Arreglo original:\n");
    int contador;
    for (int contador = 0; contador < tamaño; contador++) 
    {
        printf("%d ", arreglo[contador]);
    }
    printf("\n");

    int resultado = invertir(arreglo, tamaño);

    if (resultado == 0) 
    {
        printf("Arreglo invertido:\n");
        for (int contador = 0; contador < tamaño; contador++) 
        {
            printf("%d ", arreglo[contador]);
        }
        printf("\n");
    } 
    else
    {
        printf("Tamaño no válido.\n");
    }

    return 0;
}


int invertir(int arreglo[], int tamaño) 
{
    int resultado = 0;
    if (tamaño <= 0) 
    {
        resultado = ERROR;// Error: tamaño no válido
    }

    int *inicio = arreglo; // Puntero al primer elemento
    int *fin = arreglo + tamaño - 1; // Puntero al último elemento

    while (inicio < fin) 
    {
        // Intercambio los elementos apuntados por inicio y fin
        int auxiliar;
        auxiliar = *inicio;
        *inicio = *fin;
        *fin = auxiliar;

        //contadores entre cambios de elementos desde el extremo hacia el centro
        inicio++;
        fin--;
    }

    return resultado;
}
