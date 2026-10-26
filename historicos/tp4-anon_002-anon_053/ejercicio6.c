

#include <stdio.h>

#define ERROR -1

int intercambia(char *cadena, int origen, int destino);

int main() 
{
    char cadena[] = "Hola soy Katy";

    printf("Cadena original: %s\n", cadena);

    int origen = 2; // Posición del caracter '2'
    int destino = 6; // Posición del caracter '6'

    int resultado = intercambia(cadena, origen, destino);

    if (resultado == 0) 
    {
        printf("Cadena intercambiada: %s\n", cadena);
    }
    else 
    {
        printf("Error: Posiciones de intercambio inválidas.\n");
    }

    return 0;
}


int intercambia(char *cadena, int origen, int destino) 
{
    int error = 0;
    // Verifica si las posiciones de origen y destino son válidas
    if (origen < 0 || destino < 0) 
    {
        error = ERROR; // Error: posiciones inválidas
    }

    char *puntero_origen = cadena + origen;
    char *puntero_destino = cadena + destino;

    // Intercambiar los caracteres apuntados por ptr_origen y ptr_destino
    char auxiliar = *puntero_origen;
    *puntero_origen = *puntero_destino;
    *puntero_destino = auxiliar;

    return 0; 
}

