/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include <stdbool.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");
    const char *origen = "Hola";
    char destino [15];
    size_t cantidad = sizeof(destino) / sizeof(destino[0]);
    printf("Copiar con punteros:\n");

    bool exito = copiar_con_punteros(origen, cantidad, destino);

    if (exito == true)
    {
        printf("Copia de cadena original exitosa: %s\n", destino);
    }
    else
    {
        printf("La cadena se trunco o hubo un error.\n");
    }
   
    printf("Concatenacion de punteros:\n");

    const char *original = "Programacion";
    char concatenacion [35] = "Materia de ";
    size_t capacidad = sizeof(concatenacion) / sizeof(concatenacion[0]);
    bool concatenar = concatenar_con_punteros(original, capacidad, concatenacion);
    
    if(concatenar == true)
    {
        printf("se concateno correctamente: %s\n", concatenacion);
    }

    else
    {
        printf("la cadena se trunco: %s\n", concatenacion);
    }
    return 0;
}
