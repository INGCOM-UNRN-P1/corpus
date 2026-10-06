/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include "registro_csv.h"

#define CAMPO_NOMBRE 0
#define CAMPO_EDAD 1
#define CAMPO_CIUDAD 2
#define CANTIDAD_CAMPOS 3
#define EDAD_MINIMA 18

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n");

    const char *registros[] = {
        "Ana,23,Bariloche",
        "Bruno,17,Viedma",
        "Carla,31,El Bolson",
        "Dario,15,Roca",
    };
    size_t cantidad_registros = sizeof(registros) / sizeof(registros[0]);

    char **mayores = lista_cadenas_crear();
    size_t cantidad_mayores = 0;
    int resultado = 0;

    for (size_t i = 0; i < cantidad_registros && resultado == 0; i++)
    {
        size_t cantidad_campos = 0;
        char **campos = dividir_linea_csv(registros[i], ',',
                                          &cantidad_campos);
        if (campos == NULL || cantidad_campos != CANTIDAD_CAMPOS)
        {
            fprintf(stderr, "Registro invalido: %s\n", registros[i]);
            resultado = 1;
        }
        else
        {
            printf("Nombre: %-6s Edad: %-3s Ciudad: %s\n",
                   campos[CAMPO_NOMBRE], campos[CAMPO_EDAD],
                   campos[CAMPO_CIUDAD]);
            long edad = strtol(campos[CAMPO_EDAD], NULL, 10);
            bool es_mayor = edad >= EDAD_MINIMA;
            if (es_mayor == true
                && lista_cadenas_agregar(&mayores, &cantidad_mayores,
                                         campos[CAMPO_NOMBRE]) == false)
            {
                fprintf(stderr, "Error de memoria\n");
                resultado = 1;
            }
        }
        liberar_arreglo_cadenas(&campos, cantidad_campos);
    }

    printf("Mayores de edad (%zu):", cantidad_mayores);
    for (size_t i = 0; i < cantidad_mayores; i++)
    {
        printf(" %s", mayores[i]);
    }
    printf("\n");

    lista_cadenas_destruir(mayores, cantidad_mayores);
    mayores = NULL;
    return resultado;
}
