
/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 1 con p1_test.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "vector.h"
#include "vector_enteros.h"

TEST(prueba_clonar_arreglo_enteros)
{
    int datos[] = {10, 20, 30, 40};
    int *clon = NULL;
    size_t i = 0;

    SUBCASE("Clonacion correcta en memoria dinamica");

    clon = clonar_arreglo_enteros(datos, 4);

    ASSERT_PTR_NOT_NULL(clon);

    for (i = 0; i < 4; i++)
    {
        ASSERT_INT_EQ(datos[i], clon[i]);
    }

    liberar_bloque_enteros(&clon);

    ASSERT_PTR_NULL(clon);


    SUBCASE("Parametros invalidos");

    ASSERT_PTR_NULL(
        clonar_arreglo_enteros(NULL, 4)
    );

    ASSERT_PTR_NULL(
        clonar_arreglo_enteros(datos, 0)
    );
}


TEST(prueba_filtrar_arreglo_pares)
{
    int datos[] = {1, 4, 7, 8, 10, 13};
    int impares[] = {1, 3, 5};

    int *pares = NULL;
    int *resultado_impares = NULL;

    size_t cantidad_pares = 0;
    size_t cantidad_impares = 99;


    SUBCASE("Filtrar pares con reserva exacta");

    pares = filtrar_arreglo_pares(
        datos,
        6,
        &cantidad_pares
    );

    ASSERT_PTR_NOT_NULL(pares);

    ASSERT_INT_EQ(3, (int)cantidad_pares);

    ASSERT_INT_EQ(4, pares[0]);
    ASSERT_INT_EQ(8, pares[1]);
    ASSERT_INT_EQ(10, pares[2]);

    liberar_bloque_enteros(&pares);

    ASSERT_PTR_NULL(pares);


    SUBCASE("Sin elementos pares");

    resultado_impares = filtrar_arreglo_pares(
        impares,
        3,
        &cantidad_impares
    );

    ASSERT_PTR_NULL(resultado_impares);

    ASSERT_INT_EQ(
        0,
        (int)cantidad_impares
    );
}


TEST(prueba_arreglos_casos_borde)
{
    int datos[] = {-4, -3, 0, 2};

    int *pares = NULL;

    size_t cantidad = 99;


    SUBCASE("Pares negativos y cero");

    pares = filtrar_arreglo_pares(
        datos,
        4,
        &cantidad
    );

    ASSERT_PTR_NOT_NULL(pares);

    ASSERT_INT_EQ(
        3,
        (int)cantidad
    );

    ASSERT_INT_EQ(-4, pares[0]);
    ASSERT_INT_EQ(0, pares[1]);
    ASSERT_INT_EQ(2, pares[2]);


    SUBCASE("Bloque independiente del original");

    pares[0] = 42;

    ASSERT_INT_EQ(
        -4,
        datos[0]
    );

    liberar_bloque_enteros(&pares);

    ASSERT_PTR_NULL(pares);


    SUBCASE("Entradas invalidas");

    ASSERT_PTR_NULL(
        filtrar_arreglo_pares(
            NULL,
            4,
            &cantidad
        )
    );

    ASSERT_INT_EQ(
        0,
        (int)cantidad
    );

    ASSERT_PTR_NULL(
        filtrar_arreglo_pares(
            datos,
            0,
            &cantidad
        )
    );

    ASSERT_PTR_NULL(
        filtrar_arreglo_pares(
            datos,
            4,
            NULL
        )
    );
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 1",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_clonar_arreglo_enteros);
    RUN_TEST(prueba_filtrar_arreglo_pares);
    RUN_TEST(prueba_arreglos_casos_borde);

    return TEST_REPORT();
}
