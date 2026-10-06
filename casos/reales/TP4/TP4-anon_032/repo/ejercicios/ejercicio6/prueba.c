/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "lista_dinamica.h" // Incluido a la fuerza debido a problemas tecnicos
#include "procesamiento_dinamico.h"

TEST(prueba_contiene_subcadena)
{
    SUBCASE("Caso normal");
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;
    lista_cadenas_agregar(&lista, &cantidad, "O'er the midnight moorlands crying,", 36);
    lista_cadenas_agregar(&lista, &cantidad, "Thro' the cypress forests sighing,", 35);
    lista_cadenas_agregar(&lista, &cantidad, "In the night-wind madly flying,", 32);
    lista_cadenas_agregar(&lista, &cantidad, "Hellish forms with streaming hair;", 35);
    lista_cadenas_agregar(&lista, &cantidad, "In the barren branches creaking,", 33);
    lista_cadenas_agregar(&lista, &cantidad, "By the stagnant swamp-pools speaking,", 38);
    lista_cadenas_agregar(&lista, &cantidad, "Past the shore-cliffs ever shrieking,", 38);
    lista_cadenas_agregar(&lista, &cantidad, "Damn'd demons of despair.", 26);

    ASSERT_TRUE(contiene_subcadena(lista[0], 36, "midnight", 9));
    ASSERT_FALSE(contiene_subcadena(lista[2], 32, "0", 4));
    
    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(contiene_subcadena(NULL, 36, "midnight", 9));
    ASSERT_FALSE(contiene_subcadena(lista[0], 0, "midnight", 9));
    ASSERT_FALSE(contiene_subcadena(lista[0], 36, NULL, 9));
    ASSERT_FALSE(contiene_subcadena(lista[0], 36, "midnight", 0));

    lista_cadenas_destruir(lista, cantidad);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_contiene_subcadena);
    return TEST_REPORT();
}
