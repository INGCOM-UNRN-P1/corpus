/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 1 con p1_test.
 */

#include "p1_test.h"
#include "vector.h"
#include "vector_enteros.h"
#include <stdio.h>
#include <stdlib.h>


int *clonar_arreglo_enteros(const int *origen, size_t cantidad);
/**
 * @brief Descripción de la función filtrar_arreglo_pares.
 *
 * @param origen Descripción del parámetro origen.
 * @param cantidad_origen Descripción del parámetro cantidad_origen.
 * @param cantidad_pares Descripción del parámetro cantidad_pares.
 * @return Descripción del valor de retorno.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);

TEST(prueba_clonar_arreglo_enteros)
{
    SUBCASE("Clonacion correcta en memoria dinamica");
    int datos[] = {10, 20, 30, 40};
    int *clon = clonar_arreglo_enteros(datos, 4);
    ASSERT_PTR_NOT_NULL(clon);
    for (size_t i = 0; i < 4; ++i)
    {
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

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1", conteo_args,
                          argumentos);
    RUN_TEST(prueba_clonar_arreglo_enteros);
    RUN_TEST(prueba_filtrar_arreglo_pares);
    return TEST_REPORT();
}
