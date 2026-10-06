
/**
 * @file prueba.c
 * @brief Pruebas de campos independientes y liberacion completa.
 */

#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    char linea[] = "uno,dos,tres";
    size_t cantidad = 0;
    char **campos = NULL;

    SUBCASE("Multiples campos independientes");

    campos = dividir_linea_csv(
        linea,
        ',',
        &cantidad
    );

    ASSERT_PTR_NOT_NULL(campos);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("uno", campos[0]);
    ASSERT_STR_EQ("dos", campos[1]);
    ASSERT_STR_EQ("tres", campos[2]);
    ASSERT_PTR_NE(campos[0], campos[1]);

    campos[0][0] = 'U';

    ASSERT_STR_EQ("uno,dos,tres", linea);

    liberar_arreglo_cadenas(&campos, cantidad);

    ASSERT_PTR_NULL(campos);


    SUBCASE("Delimitador alternativo y espacios conservados");

    campos = dividir_linea_csv(
        "uno; dos",
        ';',
        &cantidad
    );

    ASSERT_PTR_NOT_NULL(campos);
    ASSERT_INT_EQ(2, (int)cantidad);
    ASSERT_STR_EQ(" dos", campos[1]);

    liberar_arreglo_cadenas(&campos, cantidad);

    ASSERT_PTR_NULL(campos);
}

TEST(prueba_campos_vacios)
{
    size_t cantidad = 0;
    char **campos = NULL;

    SUBCASE("Campos vacios iniciales, interiores y finales");

    campos = dividir_linea_csv(
        ",a,,",
        ',',
        &cantidad
    );

    ASSERT_PTR_NOT_NULL(campos);
    ASSERT_INT_EQ(4, (int)cantidad);
    ASSERT_STR_EQ("", campos[0]);
    ASSERT_STR_EQ("a", campos[1]);
    ASSERT_STR_EQ("", campos[2]);
    ASSERT_STR_EQ("", campos[3]);

    liberar_arreglo_cadenas(&campos, cantidad);

    ASSERT_PTR_NULL(campos);


    SUBCASE("Linea vacia");

    campos = dividir_linea_csv(
        "",
        ',',
        &cantidad
    );

    ASSERT_PTR_NOT_NULL(campos);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ("", campos[0]);

    liberar_arreglo_cadenas(&campos, cantidad);

    ASSERT_PTR_NULL(campos);


    SUBCASE("Un solo campo");

    campos = dividir_linea_csv(
        "UNRN",
        ',',
        &cantidad
    );

    ASSERT_PTR_NOT_NULL(campos);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ("UNRN", campos[0]);

    liberar_arreglo_cadenas(&campos, cantidad);

    ASSERT_PTR_NULL(campos);
}

TEST(prueba_parametros_invalidos)
{
    size_t cantidad = 99;
    char **campos = NULL;

    ASSERT_PTR_NULL(
        dividir_linea_csv(
            NULL,
            ',',
            &cantidad
        )
    );

    ASSERT_INT_EQ(
        0,
        (int)cantidad
    );

    cantidad = 99;

    ASSERT_PTR_NULL(
        dividir_linea_csv(
            "uno",
            '\0',
            &cantidad
        )
    );

    ASSERT_INT_EQ(
        0,
        (int)cantidad
    );

    ASSERT_PTR_NULL(
        dividir_linea_csv(
            "uno",
            ',',
            NULL
        )
    );

    liberar_arreglo_cadenas(NULL, 0);
    liberar_arreglo_cadenas(&campos, 0);

    ASSERT_PTR_NULL(campos);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 5",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_campos_vacios);
    RUN_TEST(prueba_parametros_invalidos);

    return TEST_REPORT();
}
