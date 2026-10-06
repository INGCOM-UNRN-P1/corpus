/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "cadena_dinamica.h"
 
#define CAPACIDAD_LINEA 256
 
/**
 * @brief Muestra un mensaje y lee una línea de stdin sin el salto de línea final.
 *
 * Si la línea es más larga que el búfer, el resto se descarta.
 *
 * @param mensaje Texto a mostrar antes de leer.
 * @param buffer Búfer destino.
 * @param capacidad Tamaño total del búfer (incluyendo '\0').
 * @return true si se leyó una línea; false si se alcanzó el fin de la entrada.
 */
static bool leer_linea(const char *mensaje, char *buffer, size_t capacidad)
{
    printf("%s", mensaje);
    if (fgets(buffer, (int)capacidad, stdin) == NULL) 
    {
        return false;
    }
 
    size_t posicion = 0;
    while (buffer[posicion] != '\0' && buffer[posicion] != '\n') 
    {
        ++posicion;
    }
    if (buffer[posicion] == '\0') 
    {
        
        int caracter = getchar();
        while (caracter != '\n' && caracter != EOF) 
        {
            caracter = getchar();
        }
    }
    buffer[posicion] = '\0';
    return true;
}
 
int main(void)
{
    printf("Ejercicio 3: Cadenas Dinámicas en Heap\n");
 
    char primera[CAPACIDAD_LINEA];
    char segunda[CAPACIDAD_LINEA];
    if (!leer_linea("Ingrese la primera cadena: ", primera, sizeof(primera)) || !leer_linea("Ingrese la segunda cadena: ", segunda, sizeof(segunda))) 
        {
        fprintf(stderr, "\nError: no se pudo leer la entrada\n");
        return 1;
        }
 
    char *clon = clonar_cadena(primera);
    
    char *unida = unir_cadenas_dinamicas(primera, segunda);
    if (clon == NULL || unida == NULL) 
    {
        fprintf(stderr, "Error: no se pudo reservar memoria\n");
        free(clon);
        free(unida);
        return 1;
    }
    printf("Clon de la primera: \"%s\"\n", clon);
    printf("Union de ambas:     \"%s\"\n", unida);
 
    if (primera[0] != '\0') 
    {
        primera[0] = '#';
        printf("Original modificado: \"%s\"\n", primera);
        printf("El clon no cambia:   \"%s\"\n", clon);
    }

    free(unida);
    free(clon);
    return 0;
}