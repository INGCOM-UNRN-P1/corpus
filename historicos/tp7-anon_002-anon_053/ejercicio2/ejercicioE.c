

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1


int* fusiona_arreglos(int* arreglo1, int tamano1, int* arreglo2, int tamano2);

int main()
{
    int tamano1 = 5;
    int* arreglo1 = (int*)malloc(tamano1 * sizeof(int));
    
    // Inicializar el primer arreglo
    for (int i = 0; i < tamano1; ++i) 
    {
        arreglo1[i] = i * 2;
    }

    int tamano2 = 4;
    int* arreglo2 = (int*)malloc(tamano2 * sizeof(int));
    
    // Inicializar el segundo arreglo
    for (int i = 0; i < tamano2; ++i) 
    {
        arreglo2[i] = i * 3 + 1;
    }

    printf("Arreglo 1: ");
    for (int i = 0; i < tamano1; ++i) 
    {
        printf("%d ", arreglo1[i]);
    }
    printf("\n");

    printf("Arreglo 2: ");
    for (int i = 0; i < tamano2; ++i) 
    {
        printf("%d ", arreglo2[i]);
    }
    printf("\n");

    // Fusionar los arreglos
    int* fusionado = fusiona_arreglos(arreglo1, tamano1, arreglo2, tamano2);

    printf("Arreglo fusionado: ");
    for (int i = 0; i < tamano1 + tamano2; ++i) 
    {
        printf("%d ", fusionado[i]);
    }
    printf("\n");

    // Liberar la memoria de los arreglos y el arreglo fusionado
    free(arreglo1);
    free(arreglo2);
    free(fusionado);

    return 0;
}


int* fusiona_arreglos(int* arreglo1, int tamano1, int* arreglo2, int tamano2) 
{
    // Reservar memoria para el nuevo arreglo dinámico fusionado
    int* fusionado = (int*)malloc((tamano1 + tamano2) * sizeof(int));
    
    // Verifica si la reserva de memoria fue exitosa
    if (fusionado == NULL)  
    {
        fusionado = ERROR;
    }
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    // Fusionar los arreglos ordenados
    while (i < tamano1 && j < tamano2) 
    {
        if (arreglo1[i] < arreglo2[j]) 
        {
            fusionado[k++] = arreglo1[i++];
        } 
        else 
        {
            fusionado[k++] = arreglo2[j++];
        }
    }
    
    // Copiar los elementos restantes del arreglo1 
    while (i < tamano1) 
    {
        fusionado[k++] = arreglo1[i++];
    }
    
    // Copiar los elementos restantes del arreglo2 
    while (j < tamano2) 
    {
        fusionado[k++] = arreglo2[j++];
    }
    
    return fusionado;
}
