/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>



int cargar_arreglo(int cantidad, int arreglo[]);
int muestra_arreglo(int cantidad, int arreglo[]);


int main()
{
    int cantidad;
    
    printf("ingrese cuantos numeros va a cargar: \n");
    scanf("%d",&cantidad);
    
    int arreglo[cantidad];
    
    cargar_arreglo(cantidad, arreglo);
    muestra_arreglo(cantidad, arreglo);
    
}

int cargar_arreglo(int cantidad, int arreglo[])
{
    int posicion;
    
    for(posicion = 0; posicion < cantidad; posicion++)
    {
        printf("ingrese el numero para la posicion [%d]: ",posicion);
        scanf("%d",&arreglo[posicion]);            
    }  
}


int muestra_arreglo(int cantidad, int arreglo[])
{
    int posicion;
    
    for (posicion = 0; posicion < cantidad; posicion++)
    {
        printf("El valor en la posicion [%d] es: %d\n",posicion, arreglo[posicion]);
    }
}