#include <stdio.h>
#include <stdlib.h>
#include "registro_csv.h"

static void quitar_salto(char *cadena)
{
    for (size_t i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == '\n')
        {
            cadena[i] = '\0';
            break;
        }
    }
}

int main(void)
{
    printf("Ejercicio 5: Registros y Parseo CSV en Heap\n\n");

    char buffer[256];
    printf("Ingrese una linea en formato CSV (ej: Juan,25,Bariloche):\n> ");
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        printf("Error al leer la entrada.\n");
        return 1;
    }
    quitar_salto(buffer);

    size_t cantidad = 0;
    char **campos = dividir_linea_csv(buffer, ',', &cantidad);

    if (campos != NULL)
    {
        printf("\nProcesando linea CSV...\n");
        printf("Se identificaron %zu campos:\n", cantidad);
        
        for (size_t i = 0; i < cantidad; i++)
        {
            printf("  [Campo %zu]: \"%s\"\n", i + 1, campos[i]);
        }

        liberar_arreglo_cadenas(&campos, cantidad);
        
        if (campos == NULL)
        {
            printf("\nMemoria de los campos liberada correctamente (puntero seteado a NULL).\n");
        }
    }
    else
    {
        printf("Fallo el procesamiento de la linea CSV.\n");
    }

    return 0;
}