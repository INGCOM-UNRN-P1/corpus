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
    SUBCASE("buscar primer elemento existente:");
    int primer[5] = {10, 20, 30, 20, 50};
    // Debe retornar 1 (el índice de la PRIMERA aparición del 20, ignorando el de la posición 3)
    const int *resultado = buscar_primero(primer, 5, 20);
    ASSERT_TRUE(resultado == &primer[1]);


    SUBCASE("buscar primero no hallado");
    int no_hallado[5] = {1, 2, 3, 4, 5};
    //retorna NULL si el elemento no existe en el arreglo
    ASSERT_INT_EQ(NULL, buscar_primero(no_hallado, 5, 99));

    SUBCASE("buscar primero casos borde");
    int borde[3] = {10, 20, 30};
    // Puntero NULL
    ASSERT_INT_EQ(NULL, buscar_primero(NULL, 3, 10));
    // Capacidad 0
    ASSERT_INT_EQ(NULL, buscar_primero(borde, 0, 10));
}

TEST(prueba_distancia_punteros)
{
    SUBCASE("distancia entre elementos válidos");
    int arreglo[5] = {10, 20, 30, 40, 50};
    // Mismo puntero (distancia 0)
    ASSERT_INT_EQ(0, distancia_punteros(&arreglo[0], &arreglo[0]));
    // Distancia a elementos posteriores
    ASSERT_INT_EQ(1, distancia_punteros(&arreglo[1], &arreglo[0]));
    ASSERT_INT_EQ(3, distancia_punteros(&arreglo[3], &arreglo[0]));
    ASSERT_INT_EQ(4, distancia_punteros(&arreglo[4], &arreglo[0]));


    SUBCASE("integración con buscar_primero");
    int datos[4] = {100, 200, 300, 400};
    // Obtenemos el puntero buscando el elemento 300
    const int *p = buscar_primero(datos, 4, 300);
    // Debe retornar el índice 2
    ASSERT_INT_EQ(2, distancia_punteros(p, datos));


    SUBCASE("casos de error y punteros invertidos");
    int error[3] = {1, 2, 3};
    // p está antes de inicio (distancia negativa / inválida)
    ASSERT_INT_EQ(-1, distancia_punteros(&error[0], &error[2]));
    // Punteros NULL
    ASSERT_INT_EQ(-1, distancia_punteros(NULL, error));
    ASSERT_INT_EQ(-1, distancia_punteros(error, NULL));
    ASSERT_INT_EQ(-1, distancia_punteros(NULL, NULL));
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
