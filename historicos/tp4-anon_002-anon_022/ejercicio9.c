#include <stdio.h>
#define SIZE 100




/**
 * Elimina duplicados de un arreglo de enteros.
 * @param arreglo Arreglo de enteros en el que se eliminaran los duplicados.
 * @param longitud Longitud del arreglo.
 * @return La nueva longitud del arreglo despues de eliminar los duplicados.
 * @pre arreglo es un arreglo valido de enteros y longitud es mayor o igual a cero.
 * @post Los duplicados en el arreglo han sido eliminados, y se devuelve la nueva longitud del arreglo.
 */
int eliminar_duplicados(int arreglo[], int longitud)
{
    int resultado;
    int nuevo_tamanio = 1;
    int i = 1;
    int es_duplicado = 0;
    if (longitud <= 1)
    {
        resultado = longitud; 
    }
    for (i; i < longitud; i++)
    { 
        for (int j = 0; j < nuevo_tamanio; j++)
        {
            if (arreglo[i] == arreglo[j])
            {
                es_duplicado = 1;
                break; 
            }
        }
        if (!es_duplicado)
        {
            arreglo[nuevo_tamanio] = arreglo[i];
            resultado = nuevo_tamanio++;
        }
    }
    return resultado;
}

int main() {
    int arreglo[SIZE];
    int longitud;
    int nuevo_tamanio;
    int i = 0;
    printf("Ingrese la longitud: ");
    scanf("%d",&longitud);
    printf("Ingrese arreglo: \n");
    for (int i = 0; i < longitud; i++)
    {
        scanf("%d",&arreglo[i]);
    }
    for (i=0; i<longitud;i++);
    {
        printf("%d", arreglo[i]);
    }
    nuevo_tamanio = eliminarDuplicados(arreglo, longitud);
    printf("Arreglo sin duplicados:\n");
    for (i; i < nuevo_tamanio; i++) {
        printf("%d]", arreglo[i]);
    } 
    printf("Nuevo tamanio del arreglo: %d\n", nuevo_tamanio);
    return 0;
}
