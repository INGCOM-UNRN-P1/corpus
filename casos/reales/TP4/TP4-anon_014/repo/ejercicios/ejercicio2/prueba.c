/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 2 con p1_test.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadenas.h"
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen);
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

TEST(prueba_recortar_espacios_dinamico)
{
    SUBCASE("Recorte normal");
    char *limpio = recortar_espacios_dinamico("  abc d ");
    ASSERT_STR_EQ("abc d", limpio);
    cadena_liberar_segura(&limpio);

    SUBCASE("Solo espacios da cadena vacia");
    char *vacia = recortar_espacios_dinamico("    ");
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);

    SUBCASE("Origen nulo");
    ASSERT_PTR_NULL(recortar_espacios_dinamico(NULL));
}

TEST(prueba_normalizar_mayusculas_dinamico)
{
    SUBCASE("Convierte solo las letras");
    char *mayus = normalizar_mayusculas_dinamico("Hola, mundo 123");
    ASSERT_STR_EQ("HOLA, MUNDO 123", mayus);
    cadena_liberar_segura(&mayus);

    SUBCASE("Origen nulo");
    ASSERT_PTR_NULL(normalizar_mayusculas_dinamico(NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 2", conteo_args, argumentos);
    RUN_TEST(prueba_cadena_recortar_espacios);
    RUN_TEST(prueba_cadena_repetir);
    RUN_TEST(prueba_recortar_espacios_dinamico);
    RUN_TEST(prueba_normalizar_mayusculas_dinamico);
    return TEST_REPORT();
}
