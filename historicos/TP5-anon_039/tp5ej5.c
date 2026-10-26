/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_039 de GitHub
 *************************/
#include <stdio.h>
#define MAXIMO_STRINGS 50
#define MAXIMO_CARACTERES 1000
#define CADENA_ERROR -1

//Funciones a utilizar
int division_segura(char *cadena, int largo_maximo, char cadena_dividida[MAXIMO_STRINGS][MAXIMO_CARACTERES]);
int largo_cadena(char *cadena, int capacidad_cadena);

//Funcion Principal
int main(int argc, char *argv[])
{
    int linea;
    char cadena[MAXIMO_CARACTERES];
    char cadena_dividida[MAXIMO_STRINGS][MAXIMO_CARACTERES];
    int cantidad_lineas;

    printf("\nIngrese el texto a dividir: \n");
    scanf("%s", cadena);

    cantidad_lineas = division_segura(cadena, MAXIMO_CARACTERES, cadena_dividida);

    if (cantidad_lineas > 0)
    {
        for(linea = 0; linea < cantidad_lineas; linea++)
        {
            printf("%s\n", cadena_dividida[linea]);
        }
    }
    else
    {
        printf("\nError\n");
    }
    
}

int division_segura(char *cadena, int largo_maximo, char cadena_dividida[MAXIMO_STRINGS][MAXIMO_CARACTERES])
{
    int linea = 0;
    int caracter = 0;
    int j = 0;


    //Variable que permite conocer cual será el limite del lazo for, además de ser una condición para que el programa funciones.
    int largo_total_cadena = largo_cadena(cadena, MAXIMO_CARACTERES);

    //Si la funcion "largo_cadena" retorna un valor de error este filtro tambien hará lo devido.
    if (largo_total_cadena > 0)
    {
        //Lazo que permitirá ver cada caracter del texto ingresado.
        for(j = 0; j < largo_total_cadena; j++)
        {
            
            
            if(cadena[j] != '\n')
            {
                cadena_dividida[linea][caracter] = cadena[j];
                caracter++;
            }
            else
            {
                cadena_dividida[linea][caracter+1] = '\0';
                linea++;
                caracter = 0;
            }
        }

        //Retorno para saber la cantidad de lineas en la que se dividió la cadena de texto original.
        return linea+1;
    }
    else
    {
        //Retorno si hay un caso de error.
        return CADENA_ERROR;
    }
}

//Misma funcion que en el ejercicio 2 de la practica.
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
            return CADENA_ERROR;
        }
    }
    return i;
}