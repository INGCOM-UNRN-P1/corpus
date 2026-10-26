/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * @anon_023
 *************************/
#include<stdio.h>
#include<stdlib.h>
#define CADENA_CORTA -1
#define CADENA_VACIA -2
#define CADENA_EXCEDIDA -3 // No se encontró el final de la cadena antes de llegar a la capacidad máxima de la misma
#define CAPACIDAD_CADENA 20

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int tamaño = 0;
    while (cadena[tamaño] != 0 )
    {
        tamaño++;
    }
    if (tamaño == 0)
    {
        return CADENA_VACIA;
    }
    else if (tamaño > capacidad_cadena)
    {
        return CADENA_EXCEDIDA;
    }
    return tamaño;
}

int insercion(char *destino, int capacidad_destino, char* insertar, int posicion)
{
    int tamaño_insertar = largo_cadena(insertar,capacidad_destino);
    
    int tamaño_destino = largo_cadena(destino,capacidad_destino);
    
    if (tamaño_insertar + tamaño_destino < capacidad_destino) //dejo un espacio para el terminador de cadena
    {
        for(int i = tamaño_destino-1; i>posicion; i--)
        {
            destino[i+tamaño_insertar] = destino[i];
        }
        
        for(int i = 0; i<tamaño_insertar; i++)
        {
            destino[i+posicion+1] = insertar[i];
        }
        return tamaño_insertar + tamaño_destino;
    }
    else
    {
        return CADENA_EXCEDIDA;
    }
}

int inversor(char* origen, char* destino, int capacidad_destino)
{
    int tamaño_origen = largo_cadena(origen,capacidad_destino);
    if (tamaño_origen > 0)
    {
        for (int i = 0; i<tamaño_origen;i++)
        {
            destino[tamaño_origen-i-1] = origen[i];
        }
        return tamaño_origen;
    }
    return tamaño_origen;
}


int main()
{  
    char destino[CAPACIDAD_CADENA] ="roberto";
    char * origen ="laprueba";
    char * test_largo = "probando";
    char inversion[CAPACIDAD_CADENA] = "\0";
    
    int largo_destino = largo_cadena(test_largo, CAPACIDAD_CADENA);
    printf("largo_destino = %d\n", largo_destino);
    
    int insertar = insercion(destino, CAPACIDAD_CADENA, origen, 3);
    printf("insertar = %d, destino = %s\n", insertar, destino);
    
    int invertir = inversor(origen, inversion, CAPACIDAD_CADENA);
    printf("invertir = %d, destino = %s\n", invertir, inversion);
    
    return 0;
}
    
