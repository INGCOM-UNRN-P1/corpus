
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
#define MAXIMO 50
#define MAXIMA_CAPACIDAD 100 

int largo_seguro(char cadena_destino[], int capacidad);
int inserta_cadena (char cadena_ingreso[], char cadena_destino[], int capacidad, int posicion);



int main()
{
    int capacidad = MAXIMO;
    int caracter = 0;
    int posicion = 0;
    int respuesta = 0;
    char cadena_ingreso[MAXIMA_CAPACIDAD];
    char cadena_destino[MAXIMA_CAPACIDAD];
    
    printf("ingrese una cadena para insertarla en otra: \n");
    fgets(cadena_ingreso,MAXIMA_CAPACIDAD,stdin);
    
    printf("ingrese en que cadena se va a insertar la anterior: \n");
    fgets(cadena_destino,MAXIMA_CAPACIDAD,stdin);
    
    
    printf("ingrese en que caracter se va a insertar la cadena: \n");
    scanf("%d",&posicion);
    
    respuesta = inserta_cadena(cadena_ingreso, cadena_destino, capacidad, posicion);
    printf("El largo de la cadena es: %d",respuesta);
        
}



int largo_seguro(char cadena_destino[], int capacidad)
{
    int caracter = 0;
    
    while ((cadena_destino[caracter] != '\0') && (caracter < capacidad))
    {
        caracter ++;
    }  
    if (caracter == capacidad)
    {
        return CADENA_SIN_TERMINADOR;
    }
    else
    {
        return caracter;  
    }   
}




int inserta_cadena (char cadena_ingreso[], char cadena_destino[], int capacidad, int posicion)
{
    
    int caracter = 0;
    int caracter_aux = 0;
    int caracter_aux2 = 0;
    int caracteres_ingreso = 0;
    int caracteres_destino = 0;
    int total_caracteres = 0;
    char cadena_aux[MAXIMA_CAPACIDAD];
    
    caracteres_ingreso = largo_seguro(cadena_ingreso,capacidad);
    caracteres_destino = largo_seguro(cadena_destino,capacidad);

    total_caracteres = caracteres_destino + caracteres_ingreso;
    total_caracteres = total_caracteres - 1; 
    
    if (total_caracteres > capacidad) 
    {
        return CADENA_SIN_TERMINADOR;
    }
    else 
    {
        
        while (caracter < posicion) 
        {
            cadena_aux[caracter] = cadena_destino[caracter];
            caracter++;
            
        }
        
        caracter_aux = caracter;
        while (caracter_aux2 < caracteres_ingreso - 1) 
        {
            
            cadena_aux[caracter_aux] = cadena_ingreso[caracter_aux2];
            caracter_aux++;
            caracter_aux2++;  
        }
        
        
        while (caracter < total_caracteres)
        {
            cadena_aux[caracter_aux] = cadena_destino[caracter];
            caracter++;
            caracter_aux++;
        }
    
    }
    cadena_destino = cadena_aux;
    

 
    total_caracteres = largo_seguro(cadena_destino, capacidad);
    return total_caracteres;
        
}