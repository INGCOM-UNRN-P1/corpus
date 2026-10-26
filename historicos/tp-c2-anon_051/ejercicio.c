
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO 100
void cargar_arreglo(int cantidad, int arreglo[])
{
    
    int i=0;
    int contador = 0;
    while (contador<cantidad)
    {
        printf("Ingrese un valor para la posicion %d: \n", contador);
        scanf("%d", &i);
        arreglo[contador] = i;
        contador = contador + 1;
    }
}
void muestra_arreglo(int cantidad, int arreglo[])
{
    
    int i = 0;
    int contador = 0;
    while (i<cantidad)
    {
        printf("arreglo[%d] == %i \n", contador, arreglo[i]);
        contador = contador + 1;
        i = i +1;
    }
}
float promedio(int cantidad, int arreglo[])
{
    
    int i = 0;
    float sumador = 0;
    float promedi = 0;
    while (i < cantidad)
    {
        sumador = sumador + arreglo[i];
        i = i + 1;
    }
    promedi = sumador / cantidad;
    return promedi;
}
int minimo(int cantidad, int arreglo[])
{
    
    int i = 0;
    int minim = 0;
    minim = arreglo[i];
    while(i < cantidad)
    {
        if (arreglo[i] < minim)
        {
            minim = arreglo[i]; 
        }
        i = i+1;
    }
    return minim;

}
int maximo(int cantidad, int arreglo[])
{
    
    int i = 0;
    int maxim = 0;
    maxim = arreglo[i];
    while(i < cantidad)
    {
        if (arreglo[i] > maxim)
        {
            maxim = arreglo[i]; 
        }
        i = i+1;
    }
    return maxim;
}
void ordenarmenor(int cantidad, int arreglo[])
{
    
    int i = 0;
    int j = 0;
    int guardar = 0;
    while (j < cantidad)
    {
        while(i < cantidad - 1)
        {
            if (arreglo[i] > arreglo[i+1])
            {
                guardar = arreglo[i+1];
                arreglo[i+1] = arreglo[i];
                arreglo[i] = guardar;
            }
            i = i+1;
        }
        i = 0;
        j = j + 1;
    }
    muestra_arreglo(cantidad, arreglo);
}
void ordenarmayor(int cantidad, int arreglo[])
{
    
    int i = 0;
    int j = 0;
    int guardar = 0;
    while (j < cantidad)
    {
        while(i < cantidad - 1)
        {
            if (arreglo[i] < arreglo[i+1])
            {
                guardar = arreglo[i+1];
                arreglo[i+1] = arreglo[i];
                arreglo[i] = guardar;
            }
            i = i+1;
        }
        i = 0;
        j = j + 1;
    }
    muestra_arreglo(cantidad, arreglo);
}
int main(int argc, char *argv[])
{
   int cantidad = 0;
   int i = 0;
   float promedi = 0;
   int arreglo[MAXIMO];
   int minim = 0;
   int maxim = 0;
   
   if (argc == 1)
   {
        printf("Ingrese la cantidad de elementos para el arreglo: \n");
        scanf("%d", &cantidad);
        int arreglo[cantidad];
        
        cargar_arreglo(cantidad, arreglo);
        printf("El valor de los arreglos es : \n");
        muestra_arreglo(cantidad, arreglo);
        
        promedi = promedio(cantidad, arreglo);
        printf("El promedio es %f \n", promedi);
           
        minim = minimo(cantidad, arreglo);
        printf("El minimo del arreglo es %d \n", minim);
        
        maxim = maximo(cantidad, arreglo);
        printf("El maximo del arreglo es %d \n", maxim);
        
        printf("Ordenado de menor a mayor el arreglo queda: \n");
        ordenarmenor(cantidad, arreglo);
        
        printf("Ordenado de mayor a menor el arreglo queda: \n");
        ordenarmayor(cantidad, arreglo);
   }
   else
   {    
        i = 0;
        cantidad = argc - 1;
        while (i < cantidad)
        {    
            arreglo[i] = atoi(argv[i + 1]);
            i = i +1;
        }
        printf("El valor de los arreglos es : \n");
        muestra_arreglo(cantidad, arreglo);
        
        promedi = promedio(cantidad, arreglo);
        printf("El promedio es %f \n", promedi);
           
        minim = minimo(cantidad, arreglo);
        printf("El minimo del arreglo es %d \n", minim);
        
        maxim = maximo(cantidad, arreglo);
        printf("El maximo del arreglo es %d \n", maxim);
        
        printf("Ordenado de menor a mayor el arreglo queda: \n");
        ordenarmenor(cantidad, arreglo);
        
        printf("Ordenado de mayor a menor el arreglo queda: \n");
        ordenarmayor(cantidad, arreglo);

   }
   return 0;
}

