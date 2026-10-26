
#include <stdio.h>
#include <stdbool.h>
#define LARGO 5

int cargar_arreglo(int cantidad, int arreglo[]);

int muestra_arreglo(int cantidad, int arreglo[]);


int promedio(int cantidad, int arreglo[]);

int minimo(int cantidad, int arreglo[]);

int maximo(int cantidad, int arreglo[]);

void orden_menor_mayor(int cantidad, int arreglo[]);

void orden_mayor_menor(int cantidad, int arreglo[]);




int main()

{
    int arr[LARGO];

    cargar_arreglo(LARGO, arr);
    muestra_arreglo(LARGO, arr);

    promedio(LARGO, arr);
    minimo(LARGO, arr);
    maximo(LARGO, arr);

    orden_menor_mayor(LARGO, arr);
    muestra_arreglo(LARGO, arr);
    
    orden_mayor_menor(LARGO, arr);
    muestra_arreglo(LARGO, arr);
   
    return 0;
}


int cargar_arreglo(int cantidad, int arreglo[])
{
    int i = 0;

    while (i < cantidad)
    {
        printf("Ingrese un valor para cargar al arreglo en la pos[%d]-> ", i);
        scanf("%d", &arreglo[i]);
        fflush(stdin);
        
        i++;
    }
}

int muestra_arreglo(int cantidad, int arreglo[])
{
    int contt = 0;

    printf("\nEl valor del arreglo en la posicion [%d] es: %d", contt, arreglo[contt]);
    contt++;

    while (contt < LARGO)
    {
        printf("\nEl valor del arreglo en la posicion [%d] es: %d", contt, arreglo[contt]);
        contt++;
    }
    printf("\n\n");
}


int promedio(int cantidad, int arreglo[])
{
    int i = 0;
    int suma = 0;
    int promedio;
    
    while (i < cantidad)
    {
        suma = suma + arreglo[i]; 
        i++;
    }

    promedio = suma / cantidad;
    printf("\n\nEl promedio es %d", promedio);
}

int minimo(int cantidad, int arreglo[])
{
    int i = 0;
    int minimo = arreglo[i];
    
    i++;
    while (i < cantidad)
    {
        if (arreglo[i] < minimo)
        {
            minimo = arreglo[i];
        }
        i++;
    }
    printf("\n\nEl minimo en la lista es %d", minimo);
}

int maximo(int cantidad, int arreglo[])
{
    int i = 0;
    int maximo = arreglo[i];
    
    i++;
    while (i < cantidad)
    {
        if (arreglo[i] > maximo)
        {
            maximo = arreglo[i];
        }
        i++;
    }
    printf("\n\nEl maximo en la lista es %d\n", maximo);
}


void orden_menor_mayor(int cantidad, int arreglo[])
{
    int i = 0;
    int contador;
    bool ordenado = true;
    int auxiliar;
    
    while (ordenado)
    {
        ordenado = false;
        while (i < cantidad-1)
        {
            if (arreglo[i] > arreglo[i+1])
            {
                auxiliar = arreglo[i];
                arreglo[i] = arreglo[i+1];
                arreglo[i+1] = auxiliar;
                ordenado = true;
            }
            i++;
        }
        i = 0;
    }
}

void orden_mayor_menor(int cantidad, int arreglo[])
{
    int i = 0;
    int contador;
    bool ordenado = true;
    int auxiliar;
    
    while (ordenado)
    {
        ordenado = false;
        while (i < cantidad-1)
        {
            if (arreglo[i] < arreglo[i+1])
            {
                auxiliar = arreglo[i];
                arreglo[i] = arreglo[i+1];
                arreglo[i+1] = auxiliar;
                ordenado = true;
            }
            i++;
        }
        i = 0;
    }
}