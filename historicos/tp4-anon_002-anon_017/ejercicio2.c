
#include <stdio.h>
#define MAXIMO 10
#define MAXIMOx2 20

void intercambia(int* izquierda, int* derecha);
int cargar_arreglo(int capacidad, int arreglo[]);
void menor_a_mayor(int capacidad, int arreglo[]);
void muestra_arreglo(int capacidad, int arreglo[]);

//pre: Se necesita un arreglo valido y un numero entero
//post: se imprime el arreglo ordenado de menor a mayor.

int main()
{
    int arreglo[MAXIMO];
    int capacidad = 0;
    
    printf("Cargar arreglo\n");
    
    printf("Ingrese la capacidad del arrelgo: ");
    scanf("%d",&capacidad);
    
    cargar_arreglo(capacidad, arreglo);
    menor_a_mayor(capacidad, arreglo);
    muestra_arreglo(capacidad, arreglo);
    
    
    
    
    
}





int cargar_arreglo(int capacidad, int arreglo[])
{
    int contador = 0;
    
    if((capacidad > MAXIMOx2 ) || (capacidad < 1))
    {
        return -1;
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




void menor_a_mayor(int capacidad, int arreglo[])
{
    int contador = 0;//recorre el arreglo 
    int recorre = 0;//recorre el arreglo para comparar
 
    
    while(contador < capacidad)
    {
          
        for (recorre = contador + 1; recorre < capacidad; recorre++)//Empieza en + 1 para no contar la misma posicion que el contador.
        {
            
            if(arreglo[contador] > arreglo[recorre])//Si es menor al numero anterior encontrado como "minimo"
            {
                
                intercambia(&arreglo[contador], &arreglo[recorre]);//Intercambia los valores

            }
            
        }   
        contador++;
    }
    
    
}




void intercambia(int* izquierda, int* derecha )
{
    int temporal = *izquierda; //Guardo en temporal el valor izquierdo  (Para que no se pierda)
    *izquierda = *derecha; //Guardo en izquierda el valor derecho.
    *derecha = temporal; //Guardo el valor temporal en derecha.
      
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



