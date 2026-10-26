

#include<stdio.h>

int cargar_arreglo(int capacidad, int arreglo[]);//1.1
void muestra_arreglo(int capacidad, int arreglo[]);//1.2
void union_arreglo(int capacidad, int arreglo[], int arreglo2[], int capacidad2, int arreglo_resultado[]);//1.3
float promedio(int capacidad, int arreglo[]);//1.4
int minimo(int capacidad, int arreglo[]);//1.4
int maximo(int capacidad, int arreglo[] );//1.4
int ordenar(int capacidad, int arreglo[]);//1.4

int main()
{
    int capacidad;
    printf("Ingrese tamaño del arreglo:\n");
    scanf("%d", &capacidad);

    int arreglo[capacidad];
    cargar_arreglo(capacidad, arreglo);
    
    printf("Elementos del arreglo \n");
    muestra_arreglo(capacidad, arreglo);
    
    int capacidad2;
    printf("\nIngrese tamaño del segundo arreglo:\n");
    scanf("%d", &capacidad2);

    int arreglo2[capacidad2];
    cargar_arreglo(capacidad2, arreglo2);

    int arreglo_resultado[capacidad + capacidad2]; // Tamaño suficiente para contener ambos arreglos
    union_arreglo(capacidad, arreglo, arreglo2, capacidad2, arreglo_resultado);

    // Mostrar el arreglo_resultado
    printf("Arreglo combinado:\n");
    muestra_arreglo(capacidad + capacidad2, arreglo_resultado);
    
        for (int i = 0; i < capacidad + capacidad2; i++) 
    {
        printf("%d ", arreglo_resultado[i]);
    }

    printf("\nEl valor del promedio es: %.2f",promedio(capacidad, arreglo));
    printf("\nEl valor minimo es:%d", minimo(capacidad, arreglo));
    printf("\nPosicion del valor maximo es: %d",maximo(capacidad, arreglo));
    
    ordenar(capacidad,arreglo);
    printf("\nArreglo ordenado ");
    for (int i=0; i<capacidad; i++)
    {
        printf("[%d]", arreglo[i]);
    }

    return 0;
}


int cargar_arreglo(int capacidad, int arreglo[])
{
    int i;
    for (i = 0 ;i < capacidad;i++)
    {
        printf("Ingrese valor a cargar:");
        scanf("%d", &arreglo[i]);
    }
    return 0;
}


void muestra_arreglo(int capacidad, int arreglo[])
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        printf("%d", arreglo[i]);
    }
}


void union_arreglo(int capacidad, int arreglo[], int arreglo2[], int capacidad2, int arreglo_resultado[])
{
    // Copiar elementos de arreglo al arreglo_resultado
    for (int i = 0; i < capacidad; i++) 
    {
        arreglo_resultado[i] = arreglo[i];
    }

    // Copiar elementos de arreglo2 al arreglo_resultado
    for (int i = 0; i < capacidad2; i++) {
        arreglo_resultado[capacidad + i] = arreglo2[i];
    }
}


float promedio(int capacidad, int arreglo[])
{
    int suma = 0;
    int i;
    float promedio;
    for(i=0;i<capacidad; i++)
    {
        suma = suma + arreglo[i];
    }
    promedio = suma/capacidad;
    return promedio;
}


int minimo(int capacidad, int arreglo[])
{
    int i;
    int minimo;

    minimo = arreglo[0];
    
    for(i=1; i<capacidad; i++)
    {
        if(arreglo[i]< minimo)
        {
            minimo = arreglo[i] ;
        }
    }
    return (minimo);
}


int maximo(int capacidad, int arreglo[])
{
    int i;
    int maximo = arreglo[0];
    int posicion_maximo = 0;

    for(i=1; i<capacidad; i++)
    {
        if(arreglo[i]>maximo)
        {
            maximo = arreglo[i];
            posicion_maximo=i;
        }
    }
    return posicion_maximo;
}


int ordenar(int capacidad, int arreglo[])
{
    int i;
    int j;
    int auxiliar;

    for(i=0; i<capacidad - 1; i++)
    {
        for(j=0; j<capacidad-i-1; j++)
        {
            if(arreglo[j]>arreglo[j+1])
            {
                auxiliar = arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=auxiliar;
            }
        }
    }
    return auxiliar;
}