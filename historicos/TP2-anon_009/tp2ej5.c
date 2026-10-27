
#include <stdio.h>
#define MAX 5

//las 3 lineas de abajo llaman a las funciones a utilizar
int get_min(int array[]);
int get_max(int array[]);
float compute_mean(int array[]);

int main()
{

    int valores[] = {23, 4, 67, 32, 13};
    printf("El minimo es %d\n", get_min(valores));
    printf("El maximo es %d\n", get_max(valores));
    printf("El promedio es %0.2f\n", compute_mean(valores));
    return 0;
    

    

}


int get_min(int array[]) //devuelve el minimo elemento dentro de un arreglo
{
    int minimo = array[0];
    


    for (int i = 0; i < MAX; i++)//chequea todos los elementos de un arreglo y almacena el menor en la variable minimo
    {
        if (array[i] < minimo)
        {
            minimo = array[i];
        }
        
    }
    
    return minimo;

}


int get_max(int array[]) //devuelve el maximo elemento dentro de un arreglo
{
    int maximo = array[0];
    


    for (int i = 0; i < MAX; i++) //chequea todos los elementos de un arreglo y almacena el mayor en la variable maximo
    {
        if (array[i] > maximo)
        {
            maximo = array[i];
        }
        
    }
    
    return maximo;

}


float compute_mean(int array[]) //devuelve el promedio de los elementos de un arreglo
{

    float suma = 0;

    for (int i = 0; i < MAX; i++) //suma todos los elementos de un arreglo
    {
        suma = suma + array[i];
    }
    
    return suma / MAX; //devuelve el resultado de dividir la suma de todos los elementos del arreglo por la longitud del arreglo.

}