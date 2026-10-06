/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include "cadena_dinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char buffer1[100];
    char buffer2[100];

    printf("=== Ejercicio 3: Cadenas Dinamicas en Heap ===\n\n");

    // 1.entrada de datos
    printf("Ingrese la primera cadena: ");
    if (fgets(buffer1, sizeof(buffer1), stdin) != NULL)
    {
        for (size_t i = 0; buffer1[i] != '\0'; i++)
        {
            if (buffer1[i] == '\n')
                buffer1[i] = '\0';
        }
    }

    printf("Ingrese la segunda cadena: ");
    if (fgets(buffer2, sizeof(buffer2), stdin) != NULL)
    {
        for (size_t i = 0; buffer2[i] != '\0'; i++)
        {
            if (buffer2[i] == '\n')
                buffer2[i] = '\0';
        }
    }

    // 2. Demostracion de clonar_cadena
    char *clon = clonar_cadena(buffer1);
    if (clon != NULL)
    {
        printf("\n[CLONACION] Copia en heap: \"%s\"\n", clon);
    }

    // 3. Demostración de unir_cadenas_dinamicas
    char *unida = unir_cadenas_dinamicas(buffer1, buffer2);
    if (unida != NULL)
    {
        printf("[UNION] Resultado en heap: \"%s\"\n", unida);
    }

    // 4. Liberación obligatoria de memoria
    free(clon);
    free(unida);

    printf("\n[FREE] Memoria liberada correctamente.\n");

    return 0;
}
