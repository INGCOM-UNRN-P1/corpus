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

int distancia_punteros(const int *inicio, const int *puntero);
const int *buscar_primero(const int *arreglo, size_t capacidad, int valor_buscado);

TEST(prueba_buscar_primero)
{
    const int arreglo[] = {2, 4, 3, 1};

    SUBCASE("Punteros NULL");
    bool resultado_arrelgo = buscar_primero(NULL, 4, 4);
    ASSERT_INT_EQ(0, resultado_arrelgo);  

    SUBCASE("Capcidad 0");
    bool resultado_capacidad0 = buscar_primero(arreglo, 0, 2);
    ASSERT_INT_EQ(0, resultado_capacidad0);

    SUBCASE("Primera aparcicion valida");
    const int *puntero_encontrado = buscar_primero(arreglo, 4, 3);
    ASSERT_TRUE(puntero_encontrado != NULL);
    ASSERT_PTR_EQ(arreglo + 2, puntero_encontrado);
    ASSERT_INT_EQ(3, *puntero_encontrado);
}

TEST(prueba_distancia_punteros)
{
    const int arreglo[] = {10, 20, 30, 40};

    SUBCASE("Punteros NULL");
    ASSERT_INT_EQ(-1, distancia_punteros(NULL, arreglo + 2));
    ASSERT_INT_EQ(-1, distancia_punteros(arreglo, NULL));

    SUBCASE("Puntero anterior a inicio");
    ASSERT_INT_EQ(-1, distancia_punteros(arreglo + 2, arreglo));
    //puntero buscado esta antes de la posicion de inicio.

    SUBCASE("Mismo puntero");
    ASSERT_INT_EQ(0, distancia_punteros(arreglo, arreglo));

    SUBCASE("Distancia valida");
    const int *elemento_buscado = arreglo + 3;
    ASSERT_INT_EQ(3, distancia_punteros(arreglo, elemento_buscado));
}
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
