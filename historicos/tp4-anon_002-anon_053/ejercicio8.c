

#include <stdio.h>

#define NULL -1

char* busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda);

int main() {
    char cadena[] = "Mi nombre es Katherina";
    char busqueda[] = "nombre";
    
    char* resultado = busqueda(cadena, sizeof(cadena) - 1, busqueda, sizeof(busqueda) - 1);
    
    if (resultado != NULL) 
    {
        printf("La primera ocurrencia de '%s' se encuentra en la posición relativa %ld\n", busqueda, resultado - cadena);
    } 
    else 
    {
        printf("'%s' no se encontró en '%s'\n", busqueda, cadena);
    }
    
    return 0;
}


char* busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda) 
{
    int resultado = 0;
    int contador = 0;

    for (contador = 0; contador <= capacidad_cadena - capacidad_busqueda; contador++) 
    {
        int itereador;
        for (itereador = 0; itereador < capacidad_busqueda; itereador++) 
        {
            if (cadena[contador + itereador] != busqueda[itereador]) 
            {
                break;// sale del bucle si no encuentra una ocurrencia
            }
        }

        if (itereador == capacidad_busqueda) //
        {
            // Se encontró una coincidencia
            resultado = &cadena[contador];
        }
    }

    
    return resultado;
}




