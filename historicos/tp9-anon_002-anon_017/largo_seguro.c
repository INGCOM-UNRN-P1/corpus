#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1 //codigo de error


/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post se espera que se devuelva la longitud de la cadena ingresada.
 */
 
int largo_seguro(char cadena[], int capacidad)
{
    int contador = 0;
    int retorno = 0;
    
    while ((cadena [contador] != '\0') && (contador < capacidad)) //mientras no encuentra el terminador, suma la cantidad de caracteres.
    {
        contador++;//cuento los caracteres.
    }
    
    if(contador >= capacidad)
    {
        retorno = CADENA_SIN_TERMINADOR;//retorna sin terminador
    }
    else
    {
        retorno = contador;//retorna el largo de la cadena
    }
    
    return retorno;
        
}