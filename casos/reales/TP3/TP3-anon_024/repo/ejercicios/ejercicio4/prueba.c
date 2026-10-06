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

TEST(prueba_buscar_primero_exito)
{
   int arrtest[] = {10, 20, 30, 20, 50};
   size_t cantidad = 5;
   const int *resultado = buscar_primero(arrtest, cantidad, 20);

   ASSERT_PTR_NOT_NULL(resultado);
   ASSERT_PTR_EQ(&arrtest[1], resultado);
   ASSERT_INT_EQ(20, *resultado);
}

TEST(prueba_buscar_primero_inexistente_y_null)
{
   int arrtest[] = {1, 2, 3};

   SUBCASE("Valor inexistente en arreglo valido");
   ASSERT_PTR_NULL(buscar_primero(arrtest, 3, 99));

   SUBCASE("Arreglo nulo");
   ASSERT_PTR_NULL(buscar_primero(NULL, 3, 1));
}

TEST(prueba_distancia_punteros_exito)
{
   int arrtest[] = {10, 20, 30, 40, 50};
   int dist_inicio = distancia_punteros(arrtest, &arrtest[0]);
   int dist_medio = distancia_punteros(arrtest, &arrtest[3]);

   ASSERT_INT_EQ(0, dist_inicio);
   ASSERT_INT_EQ(3, dist_medio);
}

TEST(prueba_distancia_punteros_errores)
{
   int arrtest[] = {10, 20, 30};
   int res_null1 = distancia_punteros(NULL, &arrtest[1]);
   int res_null2 = distancia_punteros(arrtest, NULL);
   int res_invalido = distancia_punteros(&arrtest[2], &arrtest[0]);

   ASSERT_INT_EQ(-1, res_null1);
   ASSERT_INT_EQ(-1, res_null2);
   ASSERT_INT_EQ(-1, res_invalido);
}

int main(int conteo_args, char **argumentos)
{
   TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
   RUN_TEST(prueba_buscar_primero_exito);
   RUN_TEST(prueba_buscar_primero_inexistente_y_null);
   RUN_TEST(prueba_distancia_punteros_exito);
   RUN_TEST(prueba_distancia_punteros_errores);

   return TEST_REPORT();
}

// La herramienta gaff detecto los errores
// 0x300Dh, 0x001Eh, 0x2009h, 0x001Dh,
// 0x0009h los cuales considero que no
// aplican a mi codigo.
