
#include <stdio.h>
#define MAXIMO 20


void mostrar_arreglo(int arreglo[], int capacidad);
void mostrar_arreglo_invertido(int arreglo[], int capacidad);
int suma_arreglo(int arreglo[], int capacidad);


int main()
{
    int arreglo[MAXIMO] = {10,20,30,40,50};
    int capacidad = 5;
    int total = 0;
    
    printf("Arreglo\n");
    mostrar_arreglo(arreglo, capacidad);
    
    printf("\n\n");
    
    printf("Arreglo invertido\n");
    mostrar_arreglo_invertido(arreglo, capacidad-1);  
    
    printf("\n\n");
    
    total = suma_arreglo(arreglo, capacidad);
    printf("Suma de terminos = %d\n",total);
    
    
    
    
}


/**
 * La funcion muestra la posicion actual del puntero del arreglo.
 *  @param arreglo es el arreglo que se va a imprimir
 *  @pre tiene que ser un arreglo valido.
 *  @param capacidad es la capacidad del arreglo.
 *  @pre tiene que ser un numero entero positivo mayor a 0
 *  @post se espera que se impriman los elementos de un arreglo.
 */


void mostrar_arreglo(int arreglo[], int capacidad)
{

    
    if(capacidad > 0)
    {
        printf("%d\n",*arreglo);//Solamente desplazo la posicion de donde empieza el arreglo y lo manipulo como si fuese un puntero.
        
        mostrar_arreglo(arreglo + 1, capacidad - 1);//La capacidad es como sale del bucle.
    }

    
    
}


/**
 * La funcion muestra los elementos de un arreglo, desde el final hasta el principio.
 *  @param arreglo es el arreglo que se va a imprimir
 *  @pre tiene que ser un arreglo valido.
 *  @param capacidad es la capacidad del arreglo.
 *  @pre tiene que ser un numero entero positivo mayor a 0
 *  @post se espera que se impriman los elementos de un arreglo desde el ultimo hasta el primero.
 */
 
void mostrar_arreglo_invertido(int arreglo[], int capacidad)
{

    
    if(capacidad >= 0 )//= 0 por que la poscion 0 tambien hay que imprimirla.
    {
        printf("%d\n",arreglo[capacidad]);//Esto lo uso como un arreglo normal, como si la capacidad fuese un contador.
        
        mostrar_arreglo_invertido(arreglo, capacidad - 1);//Capacidad es la condicion de salida del bucle
    }

}

/**
 * La funcion suma los elementos de un arreglo.
 *  @param arreglo es el arreglo del que se van a sumar sus terminos
 *  @pre tiene que ser un arreglo valido.
 *  @param capacidad es la capacidad del arreglo.
 *  @pre tiene que ser un numero entero positivo mayor a 0
 *  @returns retorna la suma de los elemntos de un arreglo.
 *  @post se espera que se sumen los terminos de un arreglo.
 */

int suma_arreglo(int arreglo[], int capacidad)
{
    int retorno = 0;
    
    
    if(capacidad > 0)//Esto es para que salga del bucle.
    {
        retorno = *arreglo + suma_arreglo(arreglo + 1,capacidad - 1);//*arreglo es la posicion actual donde esta apuntadndo el arreglo, entonces si la muevo, no tengo que usar un "contador".
       
    }
    
    return retorno;
    
}