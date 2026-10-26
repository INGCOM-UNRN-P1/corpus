

#include <stdlib.h>
#include <stdio.h>

#define MAX 32

int cargar_arreglo(int cantidad, int arreglo[])
{
    // Pre: 
    // ((all) i: int)
    // Post:
    // ((all) arreglo: int)
    
    int i;
    int valor;
    for (i = 0; i < cantidad; i++)
    {
        printf("Ingrese el elemento %d: \n", i);
        scanf("%d", &valor);
        arreglo[i] = valor;
    }
    return 0;
}

int muestra_arreglo(int cantidad, int arreglo[])
{
    // Pre: 
    // ((all) i: int)
    // Post:
    // ((all) arreglo: int)
    
    int i;
    printf("Here be array: \n");                        //HERE BE DRAGONS
    for (i = 0; i < cantidad; i++)
    {
        printf("Valor %d: %d.\n", i, arreglo[i]);
    }
    return 0;
}

int promedio(int cantidad, int arreglo[])
{
    // Pre: 
    // ((all) i: int)
    // ((all) resultado: int)
    // Post:
    // ((all) arreglo: int)
    
    int i;
    float resultado = 0;
    
    for (i = 0; i < cantidad; i++)
    {
        resultado = resultado + arreglo[i];
    }
    resultado = (resultado / cantidad);
    printf("El promedio de la función es: %.2f.\n", resultado);
    return 0;
}

int minimo(int cantidad, int arreglo[])
{
    // Pre: 
    // ((all) i: int)
    // ((all) resultado: int)
    // Post:
    // ((all) arreglo: int)
    
    int i;
    int resultado = arreglo[1];
    
    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] < resultado)
        {
            resultado = arreglo[i];
        } 
    }
    printf("El mínimo de la función es: %d.\n", resultado);
    return 0;
}

int maximo(int cantidad, int arreglo[])
{
    // Pre: 
    // ((all) i: int)
    // ((all) resultado: int)
    // Post:
    // ((all) arreglo: int)
    
    int i;
    int resultado = arreglo[1];
    
    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] > resultado)
        {
            resultado = arreglo[i];
        } 
    }
    printf("El máximo de la función es: %d.\n", resultado);
    return 0;
}

int minmax(int cantidad, int arreglo[])
{
    // Pre: 
    // ((all) x: int)
    // ((all) y: int)
    // ((all) temp: int)
    // Post:
    // ((all arreglo: int)
    
    int x;
    int y;
    int temp;

    for (x = 0; x < cantidad - 1; x++)
    {
        for (y = 0; y < cantidad - x - 1; y++)
        {
            if (arreglo[y] > arreglo[y + 1])
            {
                temp = arreglo[y];
                arreglo[y] = arreglo[y + 1];
                arreglo[y + 1] = temp;
            }
        }
    }
    printf("Arreglo ordenado de menor a mayor:\n");
    muestra_arreglo(cantidad, arreglo);
    return 0;
}

int maxmin(int cantidad, int arreglo[])
{
    // Pre: 
    // ((all) x: int) (0<largo<MAX)
    // ((all) y: int)
    // ((all) temp: int)
    // Post:
    // ((all arreglo: int)
    
    int x;
    int y;
    int temp;

    for (x = 0; x < cantidad - 1; x++)
    {
        for (y = 0; y < cantidad - x - 1; y++)
        {
            if (arreglo[y] < arreglo[y + 1])
            {
                temp = arreglo[y];
                arreglo[y] = arreglo[y + 1];
                arreglo[y + 1] = temp;
            }
        }
    }
    printf("Arreglo ordenado de mayor a menor:\n");
    muestra_arreglo(cantidad, arreglo);
    return 0;
}

int main(int argc, char *argv[])
{
    // Pre: 
    // ((all) largo: int) (0<largo<MAX)
    // ((all) arre: int)
    // ((all) i: int)
    // Post:
    // ((all arre: int)
        
    int largo = 0;
    int arre[MAX];
    int i;

    if (argc > 1)
    {
        largo = argc - 1;
        if ( largo > MAX)
        {
            printf("Se excede el máximo permitido.\n");
            return 3;
        }

        for (i = 1; i < argc; i++)
        {
            arre[i - 1] = atoi(argv[i]);
        }
    }
    else
    {
        printf("Ingrese el tamaño del arreglo que desea crear: \n");
        scanf("%d", &largo);
        
        if (largo > MAX)
        {
                printf("Se excede el máximo permitido.\n");
                return 1;
        }
        
        if (largo < 1)
        {
                printf("Ingrese un valor mayor a cero.\n");
                return 2;
        }
    
        cargar_arreglo(largo, arre);
    }

    muestra_arreglo(largo, arre);
    promedio(largo, arre);
    minimo(largo, arre);
    maximo(largo, arre);
    minmax(largo, arre);
    maxmin(largo, arre);

    return 0;
}