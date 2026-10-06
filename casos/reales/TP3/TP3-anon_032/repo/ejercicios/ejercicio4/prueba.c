/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"

TEST(prueba_buscar_primero)
{
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7};
    const int *puntero = NULL;

    SUBCASE("Busqueda normal");
    puntero = buscar_primero(arreglo, 7, 3);
    ASSERT_INT_EQ(3, *puntero);

    SUBCASE("Valor inexistente");
    puntero = buscar_primero(arreglo, 7, 9);
    ASSERT_PTR_NULL(puntero);

    SUBCASE("Arreglo nulo");
    puntero = buscar_primero(NULL, 7, 3);
    ASSERT_PTR_NULL(puntero);

    SUBCASE("Cantidad cero");
    puntero = buscar_primero(arreglo, 0, 3);
    ASSERT_PTR_NULL(puntero);


}

TEST(prueba_distancia_punteros)
{
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int *elemento = buscar_primero(arreglo, 10, 4);
    ptrdiff_t diferencia = 0;

    SUBCASE("Caso normal");
    diferencia = distancia_punteros(arreglo, elemento);
    ASSERT_INT_EQ(4, arreglo[diferencia]);

    SUBCASE("Elemento antes de inicio");
    diferencia = distancia_punteros(elemento, arreglo);
    ASSERT_INT_EQ(-1, diferencia);

    SUBCASE("Caso parametros nulos");
    diferencia = distancia_punteros(arreglo, NULL);
    ASSERT_INT_EQ(-1, diferencia);
    diferencia = distancia_punteros(NULL, elemento);
    ASSERT_INT_EQ(-1, diferencia);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
