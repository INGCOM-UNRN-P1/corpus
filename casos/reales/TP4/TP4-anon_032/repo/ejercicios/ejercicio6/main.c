/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "lista_dinamica.h" // Incluido a la fuerza debido a problemas tecnicos
#include "procesamiento_dinamico.h"

int main(void)
{
    
    char **lista = lista_cadenas_crear();
    size_t cantidad;
    lista_cadenas_agregar(&lista, &cantidad, "O'er the midnight moorlands crying,", 36);
    lista_cadenas_agregar(&lista, &cantidad, "Thro' the cypress forests sighing,", 35);
    lista_cadenas_agregar(&lista, &cantidad, "In the night-wind madly flying,", 32);
    lista_cadenas_agregar(&lista, &cantidad, "Hellish forms with streaming hair;", 35);
    lista_cadenas_agregar(&lista, &cantidad, "In the barren branches creaking,", 33);
    lista_cadenas_agregar(&lista, &cantidad, "By the stagnant swamp-pools speaking,", 38);
    lista_cadenas_agregar(&lista, &cantidad, "Past the shore-cliffs ever shrieking,", 38);
    lista_cadenas_agregar(&lista, &cantidad, "Damn'd demons of despair.", 26);

    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%s\n", lista[i]);
    }
    
    return 0;
}
