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
    int arreglo[] = {0,1,2,3,4,5,6,7,8,9};
    int buscado = 0;
    int *ptr_encontrado = buscar_primero(arreglo, 10, buscado);
    SUBCASE("Elemento esta al inicio");
    ASSERT_PTR_EQ(&arreglo[0], ptr_encontrado);

    SUBCASE("Elemento esta al final");
    buscado = 9;
    ptr_encontrado = buscar_primero(arreglo, 10, buscado);
    ASSERT_PTR_EQ(&arreglo[9], ptr_encontrado);

    SUBCASE("Elemento no esta contenido");
    buscado = 11;
    ptr_encontrado = buscar_primero(arreglo, 10, buscado);
    ASSERT_PTR_NULL(ptr_encontrado);

    SUBCASE("Puntero nulo y cantidad = 0");
    ASSERT_PTR_NULL(buscar_primero(NULL, 10, 0));
    ASSERT_PTR_NULL(buscar_primero(arreglo, 0, 0));

}

TEST(prueba_distancia_punteros)
{
    int arreglo[] = {0,1,2,3,4,5,6,7,8,9};
    int buscado = 0;
    int *ptr_encontrado = buscar_primero(arreglo, 10, buscado);
    SUBCASE("Elemento esta al inicio");
    ASSERT_INT_EQ(0, distancia_punteros(arreglo, 10, ptr_encontrado));

    SUBCASE("Elemento esta al final");
    buscado = 9;
    ptr_encontrado = buscar_primero(arreglo, 10, buscado);
    ASSERT_INT_EQ(9, distancia_punteros(arreglo, 10, ptr_encontrado));

    SUBCASE("Elemento no esta contenido");
    buscado = 0;
    ptr_encontrado = buscar_primero(arreglo, 10, buscado);
    ASSERT_INT_EQ(-1, distancia_punteros(arreglo+2, 8, ptr_encontrado));    // ptr_encontrado es &[0] pero hago que arreglo empiece en [2]
    ASSERT_INT_EQ(0, *ptr_encontrado);
    buscado = 9;
    ptr_encontrado = buscar_primero(arreglo, 10, buscado);
    ASSERT_INT_EQ(-1, distancia_punteros(arreglo, 8, ptr_encontrado));  // ptr_encontrado es &[9] pero hago que arreglo termine en [8]
    ASSERT_INT_EQ(9, *ptr_encontrado);

    SUBCASE("Punteros nulos y cantidad = 0");
    ASSERT_INT_EQ(-1, distancia_punteros(NULL, 10, ptr_encontrado));
    ASSERT_INT_EQ(-1, distancia_punteros(arreglo, 10, NULL));
    ASSERT_INT_EQ(-1, distancia_punteros(arreglo, 0, ptr_encontrado));

}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
