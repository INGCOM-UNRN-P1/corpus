/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Franjw
*************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void cargar_arreglo(int cantidad, int arreglo[]);
void muestra_arreglo(int cantidad, int arreglo[]);
float promedio(int cantidad, int arreglo[]);
int minimo(int cantidad, int arreglo[]);
int maximo(int cantidad, int arreglo[]);
void menor_a_mayor(int cantidad, int arreglo[]);
void mayor_a_menor(int cantidad, int arreglo[]);

/* pre: *se necesita que se ingrese un numero mayor a 0 que sera la cantidad de posiciones del arreglo O se necesita que se ingrese el arreglo por linea de comandos.
   post:*En caso de que no se haya ingresado el arreglo por lista de comandos  se llamara a la funcion de "carga" para cargar el arreglo segun la cantidad de posiciones ingresadas.
        *se llamara a la funcion de "muestra" para mostrar el valor de cada posicion del arreglo.
        *Se mostraran los resultados de las funciones.
*/
int main(int argc, char *argv[])
{
    int cantidad = 0;
    int arreglo[MAX];
    int recorre = 1;
    int aux = 0;
    int respuesta_min = 0; /* respuesta de funcion minimo*/
    int respuesta_max = 0; /* respuesta de funcion maximo*/
    float resultado;       /* respuesta de funcion promedio*/
    int aux_cantidad = 0; /* uso un aux de cantidad para que no cargue la posicion de mas del argc*/
    
    /* Si se ingreso el arreglo por linea de comandos se ejecuta*/
    if (argc > 1)
    {
        aux_cantidad = argc; 
        
        while(recorre < aux_cantidad)
        {    
            
            aux = atoi(argv[recorre]); /* "atoi" es para cambiar de char a int"*/
            printf("%d \n",aux);
            arreglo[recorre] = aux; /* carga el arreglo de la linea de comandos en arreglo */
            printf("arreglo posta: %d\n",arreglo[recorre]);
            recorre++;
            cantidad++;
        }
    }
    /*Si NO se ingreso el arreglo por numros de comando se ejecuta para cargar el arreglo 1 por 1*/
    else 
    {
        printf("ingrese cuantos numeros va a cargar: \n");
        scanf("%d",&cantidad);
        cargar_arreglo( cantidad, arreglo);
    }
    /* final del programa mostrando resultado de las funciones */
    muestra_arreglo(cantidad, arreglo);
    
    resultado = promedio(cantidad, arreglo);
    printf("Promedio = %.2f \n",resultado);

    respuesta_min = minimo( cantidad,  arreglo);
    printf("Minimo = %d \n",respuesta_min);
    
    respuesta_max = maximo( cantidad,  arreglo);
    printf("Maximo = %d \n",respuesta_max);

    menor_a_mayor( cantidad, arreglo);

    mayor_a_menor(cantidad, arreglo);
  
}

/*
pre:*se pide que se ingresen numeros.
post:*Se carga el numero ingresado en las diferentes posiciones del arreglo*
*/

void cargar_arreglo(int cantidad, int arreglo[])
{
    int posicion;
    
    for(posicion = 0; posicion < cantidad; posicion++)
    {
        printf("ingrese el numero para la posicion [%d]: ",posicion);
        scanf("%d",&arreglo[posicion]);            
    }  
}

/*
pre: *se necesita que los valores ingresados sean numeros.
post:*imprime el numero de cada posicion.
*/

void muestra_arreglo(int cantidad, int arreglo[])
{
    int posicion;
    
    for (posicion = 0; posicion < cantidad; posicion++)
    {
        printf("El valor en la posicion [%d] es: %d\n",posicion, arreglo[posicion]);
    }
}

/*
    pre: *Se necesitan numeros en un arreglo.
    post:*Se sumaran todos los valores del arreglo para despues dividirlos por la cantidad de posiciones que tiene el mismo.
*/

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

/*
    pre: *Se necesitan numeros en un arreglo
    post:*Se compararan todas las posiciones del arreglo para determinar cual es el numero menor del mismo.
*/

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

/*
    pre: *Se necesitan numeros en un arreglo
    post:*Se compararan todas las posiciones del arreglo para determinar cual es el numero mayor del mismo.
*/

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

/*
    pre: *Se necesitan numeros en un arreglo
    post:*Se utilizara el metodo de la burbuja para comparar en el arreglo el valor de la izquierda y el de la derecha en caso de que el valor de la derecha sea menor al de la izquierda.
*/

void menor_a_mayor(int cantidad, int arreglo[])
{
    int valor1;
    int valor2 ;
    int aux = 0;
    int recorre = 0;


    /* metodo de la burbuja */
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

/*
    Pre: *Se necesitan numeros en un arreglo
    post:*Se utilizara el metodo de la burbuja para comparar en el arreglo el valor de la izquierda y el de la derecha en caso de que el valor de la derecha sea mayor al de la izquierda.
*/

void mayor_a_menor(int cantidad, int arreglo[])
{
    int valor1;
    int valor2 ;
    int aux = 0;
    int recorre = 0;


    /* metodo de la burbuja */
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