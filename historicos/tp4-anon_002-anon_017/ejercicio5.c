
#include <stdio.h>
#define MAXIMO 10
#define MAXIMO_DOBLE (MAXIMO * 2)
#define ERROR_DE_CARGA -1

void estadisticas(int *min, int *max, int *suma, float *promedio, int arreglo[], int capacidad);
int cargar_arreglo(int capacidad, int arreglo[]);

//pre: Se necesita un arreglo y un numero entero
//post: se opera con el arreglo para mostar el minimo, maximo, la suma y el promedio del arreglo.

int main()
{
    int arreglo[MAXIMO];
    int capacidad = 0;
    int min = 0;
    int max = 0;
    int suma = 0;
    float promedio = 0;
    
    
    printf("Ingrese la capacidad del arreglo: ");
    scanf("%d",&capacidad);
    
    cargar_arreglo(capacidad, arreglo);
    
    
    estadisticas(&min, &max, &suma, &promedio, arreglo, capacidad);
    
    printf("El minimo del arreglo es el: %d\n",min);
    printf("El maximo del arreglo es el: %d\n",max);
    printf("La suma del arreglo es :     %d\n",suma);
    printf("El promedio del arreglo es : %.2f\n",promedio);
    
    
    
}





int cargar_arreglo(int capacidad, int arreglo[])
{
    int contador = 0;
    
    if((capacidad > MAXIMO_DOBLE ) || (capacidad < 1))
    {
        return ERROR_DE_CARGA;
    }
    else
    {
        while(contador < capacidad)
        {
        printf("Ingrese un numero para la posicion '%d': ",contador);
        scanf("%d",&arreglo[contador]);//Guardo el valor ingresado en la posicion de contador
        contador++;//Incremento la posicion en 1
        } 
    }   
}




void muestra_arreglo(int capacidad, int arreglo[])
{
    int posicion = 0;
    
    while(posicion < capacidad)
    {
        printf("El numero en la posicion '%d' es: %d\n",posicion,arreglo[posicion]);//Muestro el valor de la "posicion" en el arreglo
        posicion++;//Incremento la posicion en 1
    }
}





void estadisticas(int *min, int *max, int *suma, float *promedio, int arreglo[], int capacidad)
{
    int contador = 0;
    *min = arreglo[0];//guardo el primer valor como minimo
    *max = arreglo[0];//Guardo el primer valor como maximo
    
    while(contador < capacidad)//Esto recorre el arreglo
    {
        if(arreglo[contador] < *min)//Compara si el valor anterior es menor al de ahora
        {
            *min = arreglo[contador];//si es menor lo guarda
        }
        if(arreglo[contador] > *max)//Compara si el valor anterior es mayor al de ahora
        {
            *max = arreglo[contador];//si es menor lo guarda
        }
        *suma = *suma + arreglo[contador];
        contador++;//Muevo la posicion en +1
    }
    
    
    *promedio = (*suma / capacidad);
    
  
}

