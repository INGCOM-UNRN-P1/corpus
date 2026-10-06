/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 1 con p1_test.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "vector.h"
#include "vector_enteros.h"


int *clonar_arreglo_enteros(const int *origen, size_t cantidad);
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

TEST(prueba_clonar_arreglo_enteros)
{
    SUBCASE("Clonacion correcta en memoria dinamica");
    int datos[] = {10, 20, 30, 40};
    int *clon = clonar_arreglo_enteros(datos, 4);
    ASSERT_PTR_NOT_NULL(clon);
    for (size_t i = 0; i < 4; ++i) {
        ASSERT_INT_EQ(datos[i], clon[i]);
    }
    liberar_bloque_enteros(&clon);
    ASSERT_PTR_NULL(clon);

    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(clonar_arreglo_enteros(NULL, 4));
    ASSERT_PTR_NULL(clonar_arreglo_enteros(datos, 0));
}

TEST(prueba_filtrar_arreglo_pares)
{
    SUBCASE("Filtrar pares con reserva exacta");
    int datos[] = {1, 4, 7, 8, 10, 13};
    size_t cant_pares = 0;
    int *pares = filtrar_arreglo_pares(datos, 6, &cant_pares);
    ASSERT_PTR_NOT_NULL(pares);
    ASSERT_INT_EQ(3, (int)cant_pares);
    ASSERT_INT_EQ(4, pares[0]);
    ASSERT_INT_EQ(8, pares[1]);
    ASSERT_INT_EQ(10, pares[2]);

    liberar_bloque_enteros(&pares);
    ASSERT_PTR_NULL(pares);

    SUBCASE("Sin elementos pares");
    int impares[] = {1, 3, 5};
    size_t cant_imp = 99;
    int *res_imp = filtrar_arreglo_pares(impares, 3, &cant_imp);
    ASSERT_PTR_NULL(res_imp);
    ASSERT_INT_EQ(0, (int)cant_imp);
}

TEST(prueba_clonar_bloque)
{
    SUBCASE("Clonacion con el nombre del README");
    int datos[] = {5, -2, 9};
    int *clon = clonar_bloque(datos, 3);
    ASSERT_ARRAY_INT_EQ(datos, clon, 3);
    liberar_bloque_enteros(&clon);

    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(clonar_bloque(NULL, 3));
    ASSERT_PTR_NULL(clonar_bloque(datos, 0));
}

TEST(prueba_filtrar_bloque_positivos)
{
    SUBCASE("Filtrar solo mayores a cero");
    int datos[] = {-1, 3, 0, 8, -5, 2};
    int esperado[] = {3, 8, 2};
    size_t cant_pos = 0;
    int *positivos = filtrar_bloque_positivos(datos, 6, &cant_pos);
    ASSERT_UINT_EQ(3, cant_pos);
    ASSERT_ARRAY_INT_EQ(esperado, positivos, 3);
    liberar_bloque_enteros(&positivos);

    SUBCASE("Sin positivos");
    int negativos[] = {-1, 0, -7};
    size_t cant_neg = 99;
    ASSERT_PTR_NULL(filtrar_bloque_positivos(negativos, 3, &cant_neg));
    ASSERT_UINT_EQ(0, cant_neg);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_arreglo_enteros);
    RUN_TEST(prueba_filtrar_arreglo_pares);
    RUN_TEST(prueba_clonar_bloque);
    RUN_TEST(prueba_filtrar_bloque_positivos);
    return TEST_REPORT();
}
