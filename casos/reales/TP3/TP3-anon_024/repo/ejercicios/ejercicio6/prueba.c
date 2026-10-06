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

TEST(prueba_buscar_puntero_minimo_exito)
{
   int arrtest[] = {64, 25, 12, 22, 11};
   const int *ptr_min = buscar_puntero_minimo(arrtest, arrtest + 4);

   ASSERT_PTR_NOT_NULL(ptr_min);
   ASSERT_INT_EQ(11, *ptr_min);
   ASSERT_PTR_EQ(arrtest + 4, ptr_min);
}

TEST(prueba_ordenar_seleccion_punteros_desordenado)
{
   int arrtest[] = {64, 25, 12, 22, 11};
   int esperado[] = {11, 12, 22, 25, 64};
   ordenar_seleccion_punteros(arrtest, 5);

   ASSERT_ARRAY_INT_EQ(esperado, arrtest, 5);
}

TEST(prueba_ordenar_seleccion_punteros_ya_ordenado)
{
   int arrtest[] = {1, 2, 3, 4, 5};
   int esperado[] = {1, 2, 3, 4, 5};
   ordenar_seleccion_punteros(arrtest, 5);

   ASSERT_ARRAY_INT_EQ(esperado, arrtest, 5);
}

TEST(prueba_ordenar_seleccion_punteros_casos_limite)
{
   SUBCASE("Arreglo con un solo elemento");
   int arrtest[] = {42};
   ordenar_seleccion_punteros(arrtest, 1);
   ASSERT_INT_EQ(42, arrtest[0]);

   SUBCASE("Puntero nulo");
   ordenar_seleccion_punteros(NULL, 5);
}

int main(int conteo_args, char **argumentos)
{
   TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
   RUN_TEST(prueba_buscar_puntero_minimo_exito);
   RUN_TEST(prueba_ordenar_seleccion_punteros_desordenado);
   RUN_TEST(prueba_ordenar_seleccion_punteros_ya_ordenado);
   RUN_TEST(prueba_ordenar_seleccion_punteros_casos_limite);

   return TEST_REPORT();
}

// La herramienta gaff detecto los errores
// 0x300Dh, 0x001Eh, 0x2009h, 0x0009h,
// 0x001Dh los cuales considero que no se
// aplican a mi codigo.
