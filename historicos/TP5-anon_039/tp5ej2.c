/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_039 de GitHub
 *************************/
#include <stdio.h>
#define CADENA_CORTA -1
#define MAX_CADENA 150

//Funciones para resolución de ejercicios

int largo_cadena(char *cadena, int capacidad_cadena);
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion);
int copiadora(char *origen, char *destino, int capacidad_destino);
int limpiadora(char *origen, char *destino, int capacidad_destino);
int inversor(char* origen, char* destino, int capacidad_destino);


//Funciones de pruebas para no tener conflictos de datos entre ejercicios

void prueba_largo_cadenas()
{
    char cadena[MAX_CADENA] = "Hola Mundo";
    int largo_de_cadena;
    
    printf("\nLARGO DE UNA CADENA\n");
    largo_de_cadena = largo_cadena(cadena, MAX_CADENA);
    printf("\nEl largo de la cadena es = %d\n", largo_de_cadena);
}

void prueba_insercion()
{
    int insercion_de_cadena;
    
    char cadena[MAX_CADENA] = "Hola Mundo";
    char otra_cadena[MAX_CADENA] = "VIRTUAL";
    
    printf("\nINSERCION DE CADENA\n");
    insercion_de_cadena = insercion(cadena, MAX_CADENA, otra_cadena, 9);
    printf("\nEl largo de la cadena destino es = %d\n", insercion_de_cadena);
}

void prueba_copiadora()
{
    
    int copia_cadena;
    char cadena[MAX_CADENA] = "Hola Mundo";
    char otra_cadena[MAX_CADENA] = "VIRTUAL";
    
    printf("\nCOPIADORA\n");
    copia_cadena = copiadora(otra_cadena, cadena, MAX_CADENA);
    printf("\nEl largo de la cadena destino es = %d\n", copia_cadena);
}

void prueba_limpiadora()
{
    int limpiadora_cadena;
    char cadena[MAX_CADENA] = "Hola!-!Mundo";
    char otra_cadena[MAX_CADENA] = "cadena destinooooooooooooooooo";
    
    printf("\nLIMPIADORA\n");
    limpiadora_cadena = limpiadora(cadena, otra_cadena, MAX_CADENA);
    printf("\nEl largo de la cadena destino es = %d\n", limpiadora_cadena);
}

void prueba_inversor()
{
    int inversora_cadena;
    char cadena[MAX_CADENA] = "etneG aloH - Hola Gente";
    char otra_cadena[MAX_CADENA] = "cadena destino";
    
    printf("\nINVERSORA\n");
    inversora_cadena = inversor(cadena, otra_cadena, MAX_CADENA);
    
    if (inversora_cadena > 0)
    {
        printf("\nEl texto de destino es = %s\n", otra_cadena);
    }
    else
    {
        printf("El texto destino es = %d\n", inversora_cadena);
    }
}
    

//Función Principal

int main(int argc, char *argv[])
{
    //LARGO DE CADENA
    prueba_largo_cadenas();
    
    //INSERCIÓN DE CADENA
    prueba_insercion();
    
    //COPIADORA DE CADENAS
    prueba_copiadora();
    
    //LIMPIADORA DE CADENAS
    prueba_limpiadora();
    
    //INVERSOR DE CADENAS
    prueba_inversor();
    
    return 0;
}

//Largo de una cadena

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i = 0;
    
    while (cadena[i] != '\0')
    {
        if (i <= capacidad_cadena)
        {
            i++;
        }
        else
        {
            return CADENA_CORTA;
        }
    }
    return i;
}

//Inserción de cadenas

int insercion(char *destino, int capacidad_destino, char *insertar, int posicion)
{
    int i;
    
//---Largos de cadenas---
    int largo_destino = largo_cadena(destino, MAX_CADENA);
    int largo_insertar = largo_cadena(insertar, MAX_CADENA);
    int total_largo_cadena = largo_destino + largo_insertar;
    
//---desplazamiento a realizar de caracteres de texto destino---    
    int largo_desplazamiento = largo_destino + posicion;
    
/**************
 Si el total de la cadena (calculado previamente) es mayor a la capacidad de cadena ó
 la posicion es mayor al largo de la cadena destino dará resultado de error
 ***************/
    if ((( 0 <= total_largo_cadena)||(total_largo_cadena <= capacidad_destino)) && (posicion < largo_destino))
    {
    //---desplazamiento de caracteres de texto destino---    
        for (i = largo_desplazamiento - 1 ; i >= 0; i--)
        {
            destino[posicion+largo_insertar+i] = destino[posicion+i];
        }
    //---inserción de caracteres de texto "insertar" en texto "destino"---
        for (i = 1; i <= largo_insertar; i++)
        {
            destino[posicion+i] = insertar[i-1];
        }
    
    //---largo de la cadena destino resultante---
        total_largo_cadena = largo_cadena(destino, MAX_CADENA);
        
        return total_largo_cadena;

    }
    else
    {
        return CADENA_CORTA;
    }
}

//Copia de cadenas

int copiadora(char *origen, char *destino, int capacidad_destino)
{
    int i;
    int largo_destino;
    
    //Largo para utilizarlo en el filtro de "capacidad_destino" y en cuandos caracteres copiar
    int largo_origen = largo_cadena(origen, MAX_CADENA);
    
    if (( 0 <= largo_origen)||(largo_origen <= capacidad_destino))
    {
       
        
        for (i = 0; i <= largo_origen; i++)
        {
            destino[i] = origen[i];
        }
        
        
        
        largo_destino = largo_cadena(destino, MAX_CADENA);
        
        return largo_destino;
    }
    else
    {
        return CADENA_CORTA;
    }
}

//Limpiadora de cadenas

int limpiadora(char *origen, char *destino, int capacidad_destino)
{
    int i;
    int caracter_ascii;
    
    int largo_origen = largo_cadena(origen,MAX_CADENA);
    int largo_destino;
    
    if (( 0 <= largo_origen)||( largo_origen <= capacidad_destino))
    {
        for (i = 0; i < largo_origen; i++)
        {
            caracter_ascii = origen[i];
            
            if ((('0' <= caracter_ascii) &&(caracter_ascii <= '9'))
                ||(('A' <= caracter_ascii) && (caracter_ascii <= 'Z'))
                ||(('a' <= caracter_ascii) && (caracter_ascii <= 'z')))
            {
                destino[i]= origen[i];
            }
            else
            {
                destino[i] = ' ';
            }
        }
        destino[i] = '\0';
        largo_destino = largo_cadena(destino, MAX_CADENA);
        
        return largo_destino;
    }
    else
    {
        return CADENA_CORTA;
    }
}

//Inversor de cadenas

int inversor(char* origen, char* destino, int capacidad_destino)
{
    int i;
    int j = 0;
    int largo_origen = largo_cadena(origen, MAX_CADENA);
    
    
    if (largo_origen <= capacidad_destino)
    {
        for (i = largo_origen - 1 ; i >= 0; i--)
        {
            destino[j] = origen[i];
            j++;
        }
        destino[j] = '\0';
        return 1;
    }
    else
    {
        return CADENA_CORTA;
    }
    
}