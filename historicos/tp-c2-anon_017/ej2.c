/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#define MAX 50

int cargar_arreglo(int cantidad, int arreglo[]);
float promedio(int cantidad, int arreglo[]);
int minimo(int cantidad, int arreglo[]);
int maximo(int cantidad, int arreglo[]);
void menor_a_mayor(int cantidad, int arreglo[]);
void mayor_a_menor(int cantidad, int arreglo[]);


int main()
{
    int cantidad = 0;
    int opcion = 0;
    int respuesta = 0;
    float resultado = 0; 
    int arreglo[MAX];
    
    printf("ingrese cuantos numeros va a cargar: \n");
    scanf("%d",&cantidad);
    
    printf("seleccione el tipo de operacion a realizar: \n 1: promedio. \n 2: el minimo del arreglo. \n 3: el maximo del arreglo. \n 4: ordenar de menor a mayor el arreglo. \n 5: ordenar de mayor a menor el arreglo \n ingrese su opcion:\n");   
    scanf("%d",&opcion);
 
    
    cargar_arreglo(cantidad, arreglo);
    
    if (opcion == 1)
    {
        resultado = promedio(cantidad, arreglo);
        printf("%.2f",resultado);
    }
    else if (opcion == 2)
    {
        respuesta = minimo( cantidad,  arreglo);
        printf("%d",respuesta);
    }
    else if (opcion == 3)
    {
        respuesta = maximo( cantidad,  arreglo);
        printf("%.d",respuesta);
    }
    else if (opcion == 4)
    {
        menor_a_mayor( cantidad, arreglo);
    }
    else if (opcion == 5)
    {
        mayor_a_menor(cantidad, arreglo);
    }
    else
    {
        printf("%d no pertenece a ninguna opcion.",opcion);
    }

}

int cargar_arreglo(int cantidad, int arreglo[])
{
    int posicion;
    
    for(posicion = 0; posicion < cantidad; posicion++)
    {
        printf("ingrese el numero para la posicion [%d]: ",posicion);
        scanf("%d",&arreglo[posicion]);            
    }  
    return 0;
}



float promedio(int cantidad, int arreglo[])
{
    int posicion;
    int aux = 0;
    float resultado = 0;
    int divisor = 0;
    
    for(posicion = 0; posicion < cantidad; posicion++)
    {
        aux = aux + arreglo[posicion];  
        divisor = divisor + 1;
    } 
    resultado = aux / divisor;  

    return resultado;
}



int minimo (int cantidad, int arreglo[])
{
    int posicion;
    int min = arreglo[0];
    
    for(posicion = 0; posicion < cantidad; posicion++)
    {
        if(min > arreglo[posicion])
        {
            min = arreglo[posicion];;
        }     
    }
    return min;
}



int maximo(int cantidad, int arreglo[])
{
    int posicion;
    int max=0;
    
    for(posicion = 0; posicion < cantidad; posicion++)
    {
        if(max < arreglo[posicion])
        {
            max = arreglo[posicion];
        }     
    }
    return max; 
}



void menor_a_mayor(int cantidad, int arreglo[])
{
    int valor1;
    int valor2 ;
    int aux = 0;
    int recorre = 0;


    
    for(recorre = 0; recorre < cantidad; recorre++)
    {
        for(valor1 = 0 ,valor2 = 1 ; valor2 < cantidad; valor1++,valor2++)
        {
            if(arreglo[valor1] > arreglo[valor2])
            {
                aux = arreglo[valor2];
                arreglo[valor2] = arreglo[valor1];
                arreglo[valor1] = aux;
            }
        }
    }
}



void mayor_a_menor(int cantidad, int arreglo[])
{
    int valor1;
    int valor2 ;
    int aux = 0;
    int recorre = 0;


    
    for(recorre = 0; recorre < cantidad; recorre++)
    {
        for(valor1 = 0 ,valor2 = 1 ; valor2 < cantidad; valor1++,valor2++) 
            {
            if(arreglo[valor1] < arreglo[valor2])
            {
                aux = arreglo[valor2];
                arreglo[valor2] = arreglo[valor1];
                arreglo[valor1] = aux;
            }
        }
    }

}