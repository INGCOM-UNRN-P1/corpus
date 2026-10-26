

#include <stdio.h>

#define TAMANO 5
#define TAMANO_TOTAL 10

/**
 * La funcion permite el ingreso de numeros enteros para crear un arreglo.
 *  @param arreglo es la direccion de el arreglo en el que se ingresaran los numeros
 *  @pre es un arreglo valido
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns 
 *  @post la direccion del arreglo con los numeros ingresados
 */
int cargar_arreglo(int capacidad, int arreglo[])
{
    int i;
    int numero_ingresado;

    for(i = 0;i < capacidad;i++)
    {
        printf("Ingrese un numero para llenarlo en la posicion %d: ", i);
        scanf("%d", &numero_ingresado);
        arreglo[i] = numero_ingresado;
    }
}

/**
 * La funcion permite mostrar el contenido de un arreglo.
 *  @param arreglo es la direccion de el arreglo que contiene los numeros a mostrar
 *  @pre es un arreglo valido
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns
 *  @post los caracteres del arreglo
 */
int muestra_arreglo(int capacidad, int arreglo[])
{
    int i;

    printf("El arreglo quedo ordenado de esta manera: ");

    for(i = 0;i < capacidad; i++)
    {
        printf("%d ", arreglo[i]);
    }

    printf("\n");
}

/**
 * La funcion permite unir dos arreglos en un tercero con la capacidad suficiente.
 *  @param primer_arreglo es la direccion de el arreglo que se va a fusionar
 *  @pre es un arreglo valido
 *  @param segundo_arreglo es la direccion de el arreglo que se va a fusionar
 *  @pre es un arreglo valido
 *  @param arreglo_fusionado es la direccion de el arreglo donde quedarian fusionados
 *  @pre es un arreglo valido
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns
 *  @post un arreglo con los valores de los primeros dos arreglos tomados como parametros
 */
void fusionador_arreglos(int capacidad, int primer_arreglo[], int segundo_arreglo[], int arreglo_fusionado[])
{
    int i;
    int z = 0;

    for(i = 0;i < capacidad/2;i++)
    {
        arreglo_fusionado[i] = primer_arreglo[z];
        z++;
    }

    z = 0;

    for(i = capacidad/2;i < capacidad;i++)
    {
        arreglo_fusionado[i] = segundo_arreglo[z];
        z++;
    }
}

/**
 * La funcion permite averiguar el promedio de un arreglo.
 *  @param arreglo es la direccion de el arreglo que se va a promediar
 *  @pre es un arreglo valido
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero positivo
 *  @post el calculo del promedio del arreglo
 */
int promedio_arreglo(int capacidad,int arreglo[])
{
    int i;
    int suma = 0;

    for(i = 0;i < capacidad; i++)
    {
        suma = suma + arreglo[i];
    }

    return suma / capacidad;
}

/**
 * La funcion permite averiguar el valor minimo de un arreglo.
 *  @param arreglo es la direccion de el arreglo que se va a promediar
 *  @pre es un arreglo valido
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero
 *  @post el calculo del promedio del arreglo
 */
int valor_minimo_arreglo(int capacidad,int arreglo[])
{
    int i;
    int minimo = arreglo[0];

    for(i = 0;i < capacidad; i++)
    {
        if(arreglo[i] < minimo)
        {
            minimo = arreglo[i];
        }
    }

    return minimo;
}

/**
 * La funcion permite averiguar la posicion del valor maximo de un arreglo.
 *  @param arreglo es la direccion de el arreglo que se va a promediar
 *  @pre es un arreglo valido
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero
 *  @post la posicion del valor maximo del arreglo
 */
int posicion_valor_maximo_arreglo(int capacidad,int arreglo[])
{
    int i;
    int posicion = 0;
    int maximo = arreglo[0];

    for(i = 0;i < capacidad; i++)
    {
        if(arreglo[i] > maximo)
        {
            maximo = arreglo[i];
            posicion = i;
        }
    }

    return posicion;
}

/**
 * La funcion permite ordenar los valores de un arreglo de menor a mayor.
 *  @param arreglo es la direccion de el arreglo que se va a promediar
 *  @pre es un arreglo valido
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns
 *  @post cambia el orden de menor a mayor de los valores del arreglo
 */
void ordenar_menor_a_mayor_arreglo(int capacidad,int arreglo[])
{
    int i;
    int z;
    int temporal;

    for(i = 0;i < capacidad - 1; i++)
    {
        for(z = i + 1;z < capacidad; z++)
        {
            if(arreglo[i] > arreglo[z])
            {
                temporal = arreglo[i];
                arreglo[i] = arreglo[z];
                arreglo[z] = temporal;
            }
        }
    }
}

int main()
{
    int arreglo[TAMANO];
    int segundo_arreglo[TAMANO];
    int arreglo_fusionado[TAMANO_TOTAL];
    int promedio = 0;
    int minimo = 0;
    int posicion_maximo = 0;
    int i;

    cargar_arreglo(TAMANO, arreglo);
    muestra_arreglo(TAMANO, arreglo);

    promedio = promedio_arreglo(TAMANO, arreglo);
    printf("---- El promedio del arreglo es: %d \n", promedio);

    minimo = valor_minimo_arreglo(TAMANO, arreglo);
    printf("---- El valor minimo del arreglo es: %d \n", minimo);

    posicion_maximo = posicion_valor_maximo_arreglo(TAMANO, arreglo);
    printf("---- La posicion del valor maximo en el arreglo es: %d \n", posicion_maximo);

    ordenar_menor_a_mayor_arreglo(TAMANO, arreglo);
    printf("----(Menor a mayor) ");
    muestra_arreglo(TAMANO, arreglo);
    
    printf("Cargue el segundo arreglo para fusionarlo con el primero...\n");
    cargar_arreglo(TAMANO, segundo_arreglo);
    muestra_arreglo(TAMANO, segundo_arreglo);

    fusionador_arreglos(TAMANO_TOTAL, arreglo, segundo_arreglo, arreglo_fusionado);
    printf("----(Fusionado) ");
    muestra_arreglo(TAMANO_TOTAL, arreglo_fusionado);

    return 0;
}