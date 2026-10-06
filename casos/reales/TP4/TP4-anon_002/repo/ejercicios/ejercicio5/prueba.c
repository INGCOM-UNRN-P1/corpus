/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include "p1_test.h"
#include "registro_csv.h"
#include <stdio.h>
#include <string.h>

TEST(prueba_crear_lista_vacia)
{
    char **lista = lista_cadenas_crear();

    ASSERT_TRUE(lista == NULL);

    lista_cadenas_destruir(lista, 0);
}

TEST(prueba_agregar_una_cadena)
{
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;

    bool pudo_agregar = lista_cadenas_agregar(&lista, &cantidad, "Hola mundo");

    ASSERT_TRUE(pudo_agregar);
    ASSERT_INT_EQ(cantidad, 1);
    ASSERT_TRUE(lista != NULL);
    ASSERT_TRUE(strcmp(*lista, "Hola mundo") == 0);

    lista_cadenas_destruir(lista, cantidad);
}

TEST(prueba_agregar_varias_cadenas)
{
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;

    bool pudo_agregar = lista_cadenas_agregar(&lista, &cantidad, "Primera");

    ASSERT_TRUE(pudo_agregar);

    pudo_agregar = lista_cadenas_agregar(&lista, &cantidad, "Segunda");

    ASSERT_TRUE(pudo_agregar);

    pudo_agregar = lista_cadenas_agregar(&lista, &cantidad, "Tercera");

    ASSERT_TRUE(pudo_agregar);

    ASSERT_INT_EQ(cantidad, 3);
    ASSERT_TRUE(strcmp(*(lista), "Primera") == 0);
    ASSERT_TRUE(strcmp(*(lista + 1), "Segunda") == 0);
    ASSERT_TRUE(strcmp(*(lista + 2), "Tercera") == 0);

    lista_cadenas_destruir(lista, cantidad);
}

TEST(prueba_cadena_se_duplica)
{
    char cadena_original[] = "Original";
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;

    bool pudo_agregar =
        lista_cadenas_agregar(&lista, &cantidad, cadena_original);

    ASSERT_TRUE(pudo_agregar);
    ASSERT_INT_EQ(cantidad, 1);

    *(cadena_original) = 'M';

    ASSERT_TRUE(strcmp(*lista, "Original") == 0);

    lista_cadenas_destruir(lista, cantidad);
}

TEST(prueba_agregar_cadena_vacia)
{
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;

    bool pudo_agregar = lista_cadenas_agregar(&lista, &cantidad, "");

    ASSERT_TRUE(pudo_agregar);
    ASSERT_INT_EQ(cantidad, 1);
    ASSERT_TRUE(strcmp(*lista, "") == 0);

    lista_cadenas_destruir(lista, cantidad);
}

TEST(prueba_parametros_invalidos)
{
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;

    bool pudo_agregar = lista_cadenas_agregar(NULL, &cantidad, "Hola");

    ASSERT_TRUE(!pudo_agregar);
    ASSERT_INT_EQ(cantidad, 0);

    pudo_agregar = lista_cadenas_agregar(&lista, NULL, "Hola");

    ASSERT_TRUE(!pudo_agregar);
    ASSERT_INT_EQ(cantidad, 0);

    pudo_agregar = lista_cadenas_agregar(&lista, &cantidad, NULL);

    ASSERT_TRUE(!pudo_agregar);
    ASSERT_INT_EQ(cantidad, 0);

    lista_cadenas_destruir(lista, cantidad);
    lista_cadenas_destruir(NULL, 0);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args,
                          argumentos);

    RUN_TEST(prueba_crear_lista_vacia);
    RUN_TEST(prueba_agregar_una_cadena);
    RUN_TEST(prueba_agregar_varias_cadenas);
    RUN_TEST(prueba_cadena_se_duplica);
    RUN_TEST(prueba_agregar_cadena_vacia);
    RUN_TEST(prueba_parametros_invalidos);

    return TEST_REPORT();
}
