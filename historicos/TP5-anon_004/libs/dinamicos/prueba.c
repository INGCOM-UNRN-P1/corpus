/**
 * @file prueba.c
 * @brief Pruebas unitarias de libdinamicos con el framework p1_test.
 *
 * Trabajo Practico 5 - Programacion 1 - UNRN
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "dinamicos.h"

TEST(prueba_arreglo_dinamico_creacion_destruccion)
{
    arreglo_dinamico_t arr;

    SUBCASE("Creacion y destruccion exitosa");
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 4));
    ASSERT_PTR_NOT_NULL(arr.datos);
    ASSERT_INT_EQ(0, (int)arr.cantidad);
    ASSERT_INT_EQ(4, (int)arr.capacidad);
    arreglo_dinamico_destruir(&arr);
    ASSERT_PTR_NULL(arr.datos);
    ASSERT_INT_EQ(0, (int)arr.cantidad);
    ASSERT_INT_EQ(0, (int)arr.capacidad);

    SUBCASE("Creacion con capacidad 0 asigna capacidad por defecto");
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 0));
    ASSERT_PTR_NOT_NULL(arr.datos);
    ASSERT_INT_EQ(0, (int)arr.cantidad);
    ASSERT_INT_EQ(4, (int)arr.capacidad);
    arreglo_dinamico_destruir(&arr);

    SUBCASE("Puntero nulo seguro");
    ASSERT_FALSE(arreglo_dinamico_crear(NULL, 10));
    arreglo_dinamico_destruir(NULL);
}

TEST(prueba_arreglo_dinamico_agregar)
{
    arreglo_dinamico_t arr;
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 2));

    ASSERT_TRUE(arreglo_dinamico_agregar(&arr, 10));
    ASSERT_TRUE(arreglo_dinamico_agregar(&arr, 20));
    ASSERT_INT_EQ(2, (int)arr.cantidad);
    ASSERT_INT_EQ(2, (int)arr.capacidad);

    ASSERT_TRUE(arreglo_dinamico_agregar(&arr, 30));
    ASSERT_INT_EQ(3, (int)arr.cantidad);
    ASSERT_TRUE(arr.capacidad >= 4);
    ASSERT_INT_EQ(10, arr.datos[0]);
    ASSERT_INT_EQ(20, arr.datos[1]);
    ASSERT_INT_EQ(30, arr.datos[2]);

    arreglo_dinamico_destruir(&arr);
}

TEST(prueba_arreglo_dinamico_obtener)
{
    arreglo_dinamico_t arr;
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 3));
    arreglo_dinamico_agregar(&arr, 100);
    arreglo_dinamico_agregar(&arr, 200);

    int *p0 = arreglo_dinamico_obtener(&arr, 0);
    int *p1 = arreglo_dinamico_obtener(&arr, 1);
    ASSERT_PTR_NOT_NULL(p0);
    ASSERT_PTR_NOT_NULL(p1);
    ASSERT_INT_EQ(100, *p0);
    ASSERT_INT_EQ(200, *p1);

    ASSERT_PTR_NULL(arreglo_dinamico_obtener(&arr, 2));
    ASSERT_PTR_NULL(arreglo_dinamico_obtener(NULL, 0));

    arreglo_dinamico_destruir(&arr);
}

TEST(prueba_arreglo_dinamico_filtrar_pares)
{
    arreglo_dinamico_t origen;
    arreglo_dinamico_t pares;

    ASSERT_TRUE(arreglo_dinamico_crear(&origen, 5));
    arreglo_dinamico_agregar(&origen, 1);
    arreglo_dinamico_agregar(&origen, 4);
    arreglo_dinamico_agregar(&origen, 7);
    arreglo_dinamico_agregar(&origen, 8);
    arreglo_dinamico_agregar(&origen, 10);

    ASSERT_TRUE(arreglo_dinamico_filtrar_pares(&origen, &pares));
    ASSERT_INT_EQ(3, (int)pares.cantidad);
    ASSERT_INT_EQ(4, pares.datos[0]);
    ASSERT_INT_EQ(8, pares.datos[1]);
    ASSERT_INT_EQ(10, pares.datos[2]);

    SUBCASE("Aliasing y punteros nulos");
    ASSERT_FALSE(arreglo_dinamico_filtrar_pares(&origen, &origen));
    ASSERT_FALSE(arreglo_dinamico_filtrar_pares(NULL, &pares));
    ASSERT_FALSE(arreglo_dinamico_filtrar_pares(&origen, NULL));

    arreglo_dinamico_destruir(&origen);
    arreglo_dinamico_destruir(&pares);
}

TEST(prueba_arreglo_dinamico_operaciones)
{
    arreglo_dinamico_t arr;
    ASSERT_TRUE(arreglo_dinamico_crear(&arr, 5));
    arreglo_dinamico_agregar(&arr, 10);
    arreglo_dinamico_agregar(&arr, 20);
    arreglo_dinamico_agregar(&arr, 30);

    SUBCASE("Busqueda");
    ASSERT_INT_EQ(1, arreglo_dinamico_buscar(&arr, 20));
    ASSERT_INT_EQ(-1, arreglo_dinamico_buscar(&arr, 99));
    ASSERT_INT_EQ(-1, arreglo_dinamico_buscar(NULL, 10));

    SUBCASE("Inversion in-place");
    arreglo_dinamico_invertir(&arr);
    ASSERT_INT_EQ(30, arr.datos[0]);
    ASSERT_INT_EQ(20, arr.datos[1]);
    ASSERT_INT_EQ(10, arr.datos[2]);
    arreglo_dinamico_invertir(NULL);

    SUBCASE("Compactacion");
    arreglo_dinamico_agregar(&arr, 20);
    size_t eliminados = arreglo_dinamico_compactar(&arr, 20);
    ASSERT_INT_EQ(2, (int)eliminados);
    ASSERT_INT_EQ(2, (int)arr.cantidad);
    ASSERT_INT_EQ(30, arr.datos[0]);
    ASSERT_INT_EQ(10, arr.datos[1]);
    ASSERT_INT_EQ(0, (int)arreglo_dinamico_compactar(NULL, 1));

    arreglo_dinamico_destruir(&arr);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libdinamicos", conteo_args, argumentos);
    RUN_TEST(prueba_arreglo_dinamico_creacion_destruccion);
    RUN_TEST(prueba_arreglo_dinamico_agregar);
    RUN_TEST(prueba_arreglo_dinamico_obtener);
    RUN_TEST(prueba_arreglo_dinamico_filtrar_pares);
    RUN_TEST(prueba_arreglo_dinamico_operaciones);
    return TEST_REPORT();
}
