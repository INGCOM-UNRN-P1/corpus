/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "registro_csv.h"

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
    while (buffer[posicion] != '\0' && buffer[posicion] != '\n' && buffer[posicion] != '\r') 
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
 
/**
 * @brief Divide una línea en campos, los muestra y libera la memoria.
 *
 * @param linea Línea a dividir.
 * @param delimitador Carácter separador de campos.
 */
static void mostrar_campos(const char *linea, char delimitador)
{
    size_t cantidad = 0;
    char **tokens = dividir_linea_csv(linea, delimitador, &cantidad);
    if (tokens == NULL) 
    {
        fprintf(stderr, "Error: no se pudo dividir la linea\n");
        return;
    }
 
    printf("Linea \"%s\" -> %zu campos:\n", linea, cantidad);
    for (size_t i = 0; i < cantidad; ++i) 
    {
        printf("  [%zu] \"%s\"\n", i, tokens[i]);
    }
    liberar_arreglo_cadenas(&tokens, cantidad);
}
 
int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");
 
    mostrar_campos("Ana,30,Bariloche,,ingeniera", ',');

    char delimitador_texto[CAPACIDAD_LINEA];
    char linea[CAPACIDAD_LINEA];
    if (!leer_linea("\nDelimitador (Enter para ','): ", delimitador_texto, sizeof(delimitador_texto)) || !leer_linea("Ingrese una linea de texto: ", linea, sizeof(linea))) 
    {
        fprintf(stderr, "\nError: no se pudo leer la entrada\n");
        return 1;
    }
    char delimitador = (delimitador_texto[0] == '\0') ? ',' : delimitador_texto[0];
    mostrar_campos(linea, delimitador);
    return 0;
}