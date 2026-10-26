

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

#include"funciones.c"



char* concatenaCadenas(char* cadena1, char* cadena2);

int main() 
{
    char* cadena1 = "Hola, ";
    char* cadena2 = "mundo!";
    char* concatenada = concatenaCadenas(cadena1, cadena2);
    
    printf("Cadena concatenada: %s\n", concatenada);

    // Liberar la memoria asignada para la cadena concatenada
    free(concatenada);

    return 0;
}


char* concatenaCadenas(char* cadena1, char* cadena2) 
{
    int longitud1 = largo_seguro(cadena1);
    int longitud2 = largo_seguro(cadena2);
    
    // Reserva memoria para la nueva cadena concatenada
    char* concatenada = (char*)malloc((longitud1 + longitud2 + 1) * sizeof(char));
    
    // Verifica si la reserva de memoria fue exitosa
    if (concatenada == NULL) 
    {
        concatenada = ERROR;
        
    }

    // Copia la primera cadena al inicio de la cadena concatenada
    for (int i = 0; i < longitud1; i++) 
    {
        concatenada[i] = cadena1[i];
    }

    // Concatena la segunda cadena al final de la cadena concatenada
    for (int i = 0; i < longitud2; i++) 
    {
        concatenada[longitud1 + i] = cadena2[i];
    }

    // Agrega el carácter nulo de terminación '\0'
    concatenada[longitud1 + longitud2] = '\0';

    return concatenada;
}
