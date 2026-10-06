/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 2 con p1_test.
 */

#include "cadenas.h"
#include "p1_test.h"
#include "texto_dinamico.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Descripción de la función cadena_recortar_espacios.
 *
 * @param origen Descripción del parámetro origen.
 * @return Descripción del valor de retorno.
 */
char *cadena_recortar_espacios(const char *origen);
/**
 * @brief Descripción de la función cadena_repetir.
 *
 * @param origen Descripción del parámetro origen.
 * @param veces Descripción del parámetro veces.
 * @return Descripción del valor de retorno.
 */
char *cadena_repetir(const char *origen, size_t veces);

TEST(prueba_cadena_recortar_espacios)
{
    SUBCASE("Recorte de espacios iniciales y finales");
    char *limpio = cadena_recortar_espacios("   hola mundo   ");
    ASSERT_PTR_NOT_NULL(limpio);
    ASSERT_STR_EQ("hola mundo", limpio);
    cadena_liberar_segura(&limpio);
    ASSERT_PTR_NULL(limpio);

    SUBCASE("Cadena solo de espacios");
    char *vacio = cadena_recortar_espacios("     ");
    ASSERT_PTR_NULL(vacio);
}

TEST(prueba_cadena_repetir)
{
    SUBCASE("Repetir patron");
    char *rep = cadena_repetir("abc", 3);
    ASSERT_PTR_NOT_NULL(rep);
    ASSERT_STR_EQ("abcabcabc", rep);
    cadena_liberar_segura(&rep);
    ASSERT_PTR_NULL(rep);

    SUBCASE("Repetir cero veces");
    char *cero = cadena_repetir("abc", 0);
    ASSERT_PTR_NOT_NULL(cero);
    ASSERT_STR_EQ("", cero);
    cadena_liberar_segura(&cero);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 2", conteo_args,
                          argumentos);
    RUN_TEST(prueba_cadena_recortar_espacios);
    RUN_TEST(prueba_cadena_repetir);
    return TEST_REPORT();
}
