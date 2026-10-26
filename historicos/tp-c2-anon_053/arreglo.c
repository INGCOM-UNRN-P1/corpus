

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

float promedio(float cantidad, int arreglo[]);
int valor_maximo(int cantidad, int arreglo[]);
void cargar_arreglo(int cantidad, int arreglo[]);
void muestra_arreglo(int cantidad, int arreglo[]);
int valor_minimo(int cantidad, int arreglo[]);
void mayor_menor(int cantidad, int arreglo[]);
void menor_mayor(int cantidad, int arreglo[]);

int main(int argc, char*argv[])
{
   
    int maximo = 0; 
    int minimo =0;
    int cantidad = 0;
    int contador = 0;    
    int mayor = 0;
    int menor = 0;
    float promedio1 = 0.00;
    
    if (argc == 1)
    {        
    
    printf("Ingrese tamaño del arreglo: ");   
    scanf("%d", &cantidad);
    
    int arreglo[cantidad];
    
    cargar_arreglo(cantidad, arreglo);   
    muestra_arreglo(cantidad, arreglo);    
    
    maximo = valor_maximo(cantidad,arreglo);
    minimo = valor_minimo(cantidad, arreglo);
    promedio1 = promedio(cantidad, arreglo);    
    
    printf("El valor maximo es: %d\n",maximo);
    printf("El valor minimo es: %d\n",minimo);
    printf("El promedio del arreglo es: %f\n", promedio1);  
    printf("Arreglo ordenado de mayor a menor: ");
    mayor_menor(cantidad, arreglo);   
    printf("\nArreglo ordenado de menor a mayor: ");
    menor_mayor(cantidad, arreglo);     
    
    }
    
    else
    {
        int arreglo[SIZE];
        cantidad = argc -1;
        for(contador = 0; contador<cantidad; contador++)
        {
            arreglo[contador] = atoi(argv[contador + 1]);            
        }
        muestra_arreglo(cantidad, arreglo);
        mayor_menor(mayor, arreglo);
        menor_mayor(menor, arreglo);
        
        maximo = valor_maximo(cantidad,arreglo);
        minimo = valor_minimo(cantidad, arreglo);
    	promedio1 = promedio(cantidad, arreglo);
    	    	
    	printf("El valor maximo es: %d\n",maximo);
    	printf("El valor minimo es: %d\n",minimo);
    	printf("El promedio del arreglo es: %f\n", promedio1);   
        printf("Arreglo ordenado de mayor a menor: ");
        mayor_menor(cantidad, arreglo);   
        printf("\nArreglo ordenado de menor a mayor: ");
        menor_mayor(cantidad, arreglo);
        
    }
}
//Se carga el valor por el usuario cada vez que se le pida
void cargar_arreglo(int cantidad, int arreglo[])
{
    // precondicion ingresa una cantidad de valores 
    // poscondicion retorna valores ingresados
    int i;
    
    for(i=0; i<cantidad; i++)
    {
        printf("Ingrese valor: ");
        scanf("%d", &arreglo[i]);     
    }
   
}
//Muestra por pantalla los valores que ingresa el usuario
void muestra_arreglo(int cantidad, int arreglo[])
{
    //precondicion ingreso de valor ingresado por el usuario
    //poscondicion salida de cada valor ingresado
    int i;

    for(i=0; i<cantidad; i++)
    {
        printf("En posicion [%d] el valor es: %d\n", i, arreglo[i]);
    }
   
    
}
//Retorna el valor maximo del arreglo
int valor_maximo(int cantidad, int arreglo[])
{
    //precondicion arreglo de numeros enteros
    //poscondicion valor maximo de arreglo
    int i;
    int maximo = arreglo[0];
    
    for(i=1; i<cantidad;i++)
    {
        if(arreglo[i]>maximo)
        {
            maximo=arreglo[i];
        }
   
    }
    return maximo;
}
//Retorna el valor minimo del arreglo
int valor_minimo(int cantidad, int arreglo[])
{
    //precondicion arreglo de numeros enteros
    //poscondicion valor minimo de arreglo
    int i;
    int minimo = arreglo[0];
    for(i=1; i<cantidad; i++) 
    {
        if(arreglo[i]<minimo)
        {
            minimo=arreglo[i];
        }        
    }   
    return minimo;
}
//Retorna el promedio de un arreglo de numeros enteros
float promedio(float cantidad, int arreglo[])
{
    //precondicion arreglo de numeros enteros
    //poscondicion valor promedio de arreglo    
    int i;
    float suma = 0;
    for(i=0;i<cantidad;i++)
    {
        suma=suma+arreglo[i];
    }
    float promedio = suma / cantidad;
    return promedio;

}
//Funcion que ordena un arreglo de numeros enteros de mayor a menor
void mayor_menor(int cantidad, int arreglo[])
{
    //precondicion arreglo de numeros enteros
    //poscondicion arreglo ordenado de mayor a menor
    int i;
    int j = 0;
    int auxiliar = 0;
    
    for(i=0; i<cantidad;i++)
    {
        for(j=i+1; j<cantidad;j++)
        {
            if(arreglo[i]<arreglo[j])
            {
                auxiliar = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = auxiliar;            
            }
        }
    }        
        
    for (i=0;i<cantidad; i++)
    {
        printf("%d ", arreglo[i]);
    
    }         
}
//Funcion ordena arreglo de numeros enteros de menor a mayor
void menor_mayor(int cantidad, int arreglo[])
{
    //precondicion arreglo de numeros enteros
    //poscondicion arreglo ordenado de menor a mayor
    int i;
    int j = 0;
    int auxiliar = 0;
    
    for(i=0; i<cantidad;i++)
    {
        for(j=i+1; j<cantidad;j++)
        {    if(arreglo[i]>arreglo[j])
            {
                auxiliar = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = auxiliar;            
            }
        }    
    }    
        
    for (i=0;i<cantidad; i++)
    {
        printf("%d ", arreglo[i]);
    
    }        
}

