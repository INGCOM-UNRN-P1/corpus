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

TEST(prueba_buscar_primero_arreglo_nulo)
{
    SUBCASE("Arreglo NULL retorna NULL");
    ASSERT_PTR_NULL(buscar_primero(NULL, 5, 10));
}

TEST(prueba_buscar_primero_cantidad_cero)
{
    int numeros[] = {1, 2, 3};

    SUBCASE("Cantidad 0 retorna NULL");
    ASSERT_PTR_NULL(buscar_primero(numeros, 0, 1));
}

TEST(prueba_buscar_primero_valor_ausente)
{
    int numeros[] = {10, 20, 30, 40};

    SUBCASE("Valor ausente retorna NULL");
    ASSERT_PTR_NULL(buscar_primero(numeros, 4, 99));
}

TEST(prueba_buscar_primero_primera_aparicion)
{
    int numeros[] = {5, 8, 12, 8, 3};

    SUBCASE("Con duplicados retorna la primera aparición");
    const int *encontrado = buscar_primero(numeros, 5, 8);

    ASSERT_PTR_NOT_NULL(encontrado);
    ASSERT_PTR_EQ(&numeros[1], encontrado);
    ASSERT_INT_EQ(8, *encontrado);
}

TEST(prueba_buscar_primero_extremos)
{
    int numeros[] = {7, 14, 21};

    SUBCASE("El valor está en la primera posición");
    ASSERT_PTR_EQ(&numeros[0], buscar_primero(numeros, 3, 7));

    SUBCASE("El valor está en la última posición");
    ASSERT_PTR_EQ(&numeros[2], buscar_primero(numeros, 3, 21));

    SUBCASE("Arreglo de un elemento");
    int unico[] = {42};
    ASSERT_PTR_EQ(&unico[0], buscar_primero(unico, 1, 42));
}

TEST(prueba_buscar_primero_no_modifica)
{
    int numeros[] = {5, 8, 12, 8, 3};
    int esperado[] = {5, 8, 12, 8, 3};

    SUBCASE("La búsqueda no modifica el arreglo");
    buscar_primero(numeros, 5, 8);

    ASSERT_ARRAY_INT_EQ(esperado, numeros, 5);
}

TEST(prueba_distancia_punteros_nulos)
{
    int numeros[] = {1, 2, 3};

    SUBCASE("Inicio NULL retorna -1");
    ASSERT_INT_EQ(-1, distancia_punteros(NULL, &numeros[1]));

    SUBCASE("Elemento NULL retorna -1");
    ASSERT_INT_EQ(-1, distancia_punteros(numeros, NULL));

    SUBCASE("Ambos punteros NULL retornan -1");
    ASSERT_INT_EQ(-1, distancia_punteros(NULL, NULL));
}

TEST(prueba_distancia_punteros_elemento_antes_de_inicio)
{
    int numeros[] = {1, 2, 3, 4};

    SUBCASE("Elemento anterior al inicio retorna -1");
    ASSERT_INT_EQ(-1, distancia_punteros(&numeros[2], &numeros[0]));
}

TEST(prueba_distancia_punteros_valida)
{
    int numeros[] = {100, 200, 300, 400, 500};

    SUBCASE("El inicio tiene distancia 0");
    ASSERT_INT_EQ(0, distancia_punteros(numeros, &numeros[0]));

    SUBCASE("Elemento intermedio retorna su índice");
    ASSERT_INT_EQ(2, distancia_punteros(numeros, &numeros[2]));

    SUBCASE("Último elemento retorna su índice");
    ASSERT_INT_EQ(4, distancia_punteros(numeros, &numeros[4]));
}

TEST(prueba_integracion_buscar_y_distancia)
{
    int numeros[] = {9, 4, 6, 4, 1};

    SUBCASE("Buscar un valor y calcular su distancia");
    const int *encontrado = buscar_primero(numeros, 5, 4);

    ASSERT_PTR_NOT_NULL(encontrado);
    ASSERT_INT_EQ(1, distancia_punteros(numeros, encontrado));

    SUBCASE("Valor ausente produce distancia -1");
    const int *ausente = buscar_primero(numeros, 5, 77);

    ASSERT_INT_EQ(-1, distancia_punteros(numeros, ausente));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4",
                           conteo_args, argumentos);

    RUN_TEST(prueba_buscar_primero_arreglo_nulo);
    RUN_TEST(prueba_buscar_primero_cantidad_cero);
    RUN_TEST(prueba_buscar_primero_valor_ausente);
    RUN_TEST(prueba_buscar_primero_primera_aparicion);
    RUN_TEST(prueba_buscar_primero_extremos);
    RUN_TEST(prueba_buscar_primero_no_modifica);
    RUN_TEST(prueba_distancia_punteros_nulos);
    RUN_TEST(prueba_distancia_punteros_elemento_antes_de_inicio);
    RUN_TEST(prueba_distancia_punteros_valida);
    RUN_TEST(prueba_integracion_buscar_y_distancia);

    return TEST_REPORT();
}