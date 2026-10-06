/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin);
int *ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

TEST(prueba_buscar_puntero_minimo)
{
    const int arreglo[] = {1, 2, 5, 6, 4};

    SUBCASE("Puntero NULL");
    const int *null_inicio = buscar_puntero_minimo(NULL, arreglo + 5);
    ASSERT_INT_EQ(0, null_inicio);
    const int *null_fin = buscar_puntero_minimo(arreglo, NULL);
    ASSERT_INT_EQ(0, null_fin);

    SUBCASE("Rango invalido");
    const int *rango_invalido = buscar_puntero_minimo(arreglo, arreglo);
    ASSERT_INT_EQ(0, rango_invalido);

    SUBCASE("Caso valido");
    const int *minimo = buscar_puntero_minimo(arreglo, arreglo + 3);
    ASSERT_INT_EQ(1, *minimo);
}

TEST(prueba_ordenar_seleccion_punteros)
{
    int inicio[] = {1, 2, 5, 3, 4};

    SUBCASE("Puntero NULL");
    const int *null_arreglo = ordenar_seleccion_punteros(NULL, 5);
    ASSERT_INT_EQ(1, null_arreglo == NULL);

    SUBCASE("Capacidad 0");
    bool capacidad0 = ordenar_seleccion_punteros(inicio, 0);
    ASSERT_INT_EQ(0, capacidad0);

    SUBCASE("Caso Valido");
    bool exitoso = ordenar_seleccion_punteros(inicio, 5);
    ASSERT_INT_EQ(1, exitoso);

    ASSERT_INT_EQ(1, *(inicio + 0));
    ASSERT_INT_EQ(2, *(inicio + 1));
    ASSERT_INT_EQ(3, *(inicio + 2));
    ASSERT_INT_EQ(4, *(inicio + 3));
    ASSERT_INT_EQ(5, *(inicio + 4));

}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
