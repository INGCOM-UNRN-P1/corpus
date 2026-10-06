/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo_exito)
{
   int arr_orig[] = {1, 2, 3, 4, 5};
   int arr_dest[5] = {0};
   size_t cantidad = 5;
   bool resultado = copiar_arreglo(arr_orig, arr_dest, cantidad);

   ASSERT_TRUE(resultado);
   ASSERT_ARRAY_INT_EQ(arr_orig, arr_dest, cantidad);
}

TEST(prueba_copiar_arreglo_punteros_null)
{
   int arrtest[] = {1, 2, 3};
   int arr_dest[3];

   ASSERT_FALSE(copiar_arreglo(NULL, arrtest, 3));
   ASSERT_FALSE(copiar_arreglo(arr_dest, NULL, 3));
   ASSERT_FALSE(copiar_arreglo(NULL, NULL, 3));
}

TEST(prueba_invertir_arreglo_par)
{
   int arrtest[] = {10, 20, 30, 40};
   int esperado[] = {40, 30, 20, 10};
   size_t cantidad = 4;
   bool resultado = invertir_arreglo(arrtest, cantidad);

   ASSERT_TRUE(resultado);
   ASSERT_ARRAY_INT_EQ(esperado, arrtest, cantidad);
}

TEST(prueba_invertir_arreglo_impar)
{
   int arrtest[] = {1, 2, 3, 4, 5};
   int esperado[] = {5, 4, 3, 2, 1};
   size_t cantidad = 5;
   bool resultado = invertir_arreglo(arrtest, cantidad);

   ASSERT_TRUE(resultado);
   ASSERT_ARRAY_INT_EQ(esperado, arrtest, cantidad);
}

TEST(prueba_invertir_arreglo_borde)
{
   SUBCASE("Arreglo de un solo elemento");
   int arrtest[] = {99};
   ASSERT_TRUE(invertir_arreglo(arrtest, 1));
   ASSERT_INT_EQ(99, arrtest[0]);

   SUBCASE("Puntero nulo");
   ASSERT_FALSE(invertir_arreglo(NULL, 5));
}

int main(int conteo_args, char **argumentos)
{
   TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
   RUN_TEST(prueba_copiar_arreglo_exito);
   RUN_TEST(prueba_copiar_arreglo_punteros_null);
   RUN_TEST(prueba_invertir_arreglo_par);
   RUN_TEST(prueba_invertir_arreglo_impar);
   RUN_TEST(prueba_invertir_arreglo_borde);

   return TEST_REPORT();
}

// La herramienta gaff detecto los errores
// 0x0017h, 0x300Dh, 0x0003h, 0x001Eh,
// 0x2009h, 0x001Dh, 0x0009h los cuales
// considero que no se aplican a mi codigo.
