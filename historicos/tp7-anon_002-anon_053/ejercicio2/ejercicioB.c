


#include<stdlib.h>
#include<stdio.h>

#define ERROR -1

int* duplica_arreglo(int* origen, int tamano);

// Uso de la función duplica_arreglo
int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    int* duplicado = duplica_arreglo(arreglo, tamano);

    printf("Arreglo duplicado: ");
    for (int i = 0; i < tamano; ++i) 
    {
        printf("%d ", duplicado[i]);
    }
    printf("\n");

    // Liberar la memoria del arreglo duplicado cuando ya no sea necesario
    free(duplicado);

    return 0;
}


int* duplica_arreglo(int* origen, int tamano) 
{
    // Reservar memoria para el nuevo arreglo dinámico
    int* duplicado = (int*)malloc(tamano * sizeof(int));
    
    // Verificar si la reserva de memoria fue exitosa
    if (duplicado == NULL) 
    {
        // Manejar el error, por ejemplo, imprimir un mensaje y salir del programa
        duplicado = ERROR;
    }
    
    // Copiar los elementos del arreglo de origen al arreglo duplicado
    for (int i = 0; i < tamano; ++i) 
    {
        duplicado[i] = origen[i];
    }
    
    return duplicado;
}