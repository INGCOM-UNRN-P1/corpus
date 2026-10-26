/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * @anon_020
 *************************/
#include<stdio.h>
#include<stdlib.h>
#define CADENA_CORTA -1
#define LIMITE_CADENA 100

int largo_cadena(char *cadena, int capacidad_cadena)
{
    capacidad_cadena = 0;
    if (cadena[capacidad_cadena] != 0)
    {
        while (cadena[capacidad_cadena] != 0)
        {
            capacidad_cadena++; 
        }
         return capacidad_cadena;
        
    }
    else
    {
        return CADENA_CORTA;
    }
   
    
}

int es_palindromo(char* cadena, int largo)
{
    int igualdad = 1;
    int oracion = 1;
    int i;
    largo = largo_cadena(cadena, LIMITE_CADENA);
    
    for (i = largo - 1; i >= 0; i--)
    {
        if (cadena[i] == cadena[oracion])
        {
            igualdad += 1;
            oracion += 1;
            
        }
    }
    if (largo_cadena(cadena, LIMITE_CADENA) == igualdad)
    {
        return 1;
    }
    else
    {
        return CADENA_CORTA;
    }
    
    return 0;
}

int compara(char* primera, char* segunda)
{
    int i;
   
    do
    {
        for(i = 0; i < LIMITE_CADENA; i++)
        {
            if (primera[i] > segunda [i])
            {
                return 1;
            }
            else if (primera[i] < segunda[i])
            {   
            return CADENA_CORTA;
            }
        }
    }
    while (primera[i] != segunda[i]);
               
    return 0; 
}
int copiadora(char origen[], char destino[], int capacidad_destino)
{
    int largodestino = largo_cadena(destino, LIMITE_CADENA);
    if(largo_cadena(origen, LIMITE_CADENA) <= largodestino)
    {
        for(int i = 0;i<capacidad_destino;i++)
        {
            destino[i] = origen[i];  
        }
        return largodestino;
    }
    else
    {
        return CADENA_CORTA;
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
   
    char * cadena = "oso";
    char * primeracadena = "aaab";
    char * segundacadena = "aaac";
    char destino[LIMITE_CADENA] ="hola";
    char origen[LIMITE_CADENA] ="mundo";
    char inversion[LIMITE_CADENA] = "\0";
  
    
    int largo = largo_cadena(cadena, LIMITE_CADENA);
    int palindromo = es_palindromo(cadena, LIMITE_CADENA);
    int comparar = compara(primeracadena, segundacadena);
    int copiar = copiadora(origen, destino, largo_cadena(destino,LIMITE_CADENA));
    int invertir = inversor(origen, inversion, LIMITE_CADENA);
    
    printf("la cadena: %s tiene un largo de %d \n", cadena, largo);
    printf(" La cadena es palindromo?(1 si, -1 o 0 no): %d \n", palindromo);
    printf("(%s) es mayor que (%s) ?: %d \n", primeracadena, segundacadena, comparar);
    printf("%d es el largo de la cadena destino\n", copiar);
    printf("Invirtiendo %d caracteres deja la cadena (%s) como %s", invertir, origen, inversion);

    return 0;
}
    
