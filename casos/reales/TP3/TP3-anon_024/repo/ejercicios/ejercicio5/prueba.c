/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros_exito)
{
   char arrtest[10] = {0};
   bool resultado = copiar_con_punteros(arrtest, sizeof(arrtest), "Hecho.");

   ASSERT_TRUE(resultado);
   ASSERT_STR_EQ("Hecho.", arrtest);
}

TEST(prueba_copiar_con_punteros_truncamiento)
{
   char arrtest[5] = {0};
   bool resultado = copiar_con_punteros(arrtest, sizeof(arrtest), "Jarvis!");

   ASSERT_FALSE(resultado);
   ASSERT_STR_EQ("Jarv", arrtest);
}

TEST(prueba_copiar_con_punteros_null)
{
   char arrtest[10] = {0};

   SUBCASE("Puntero de destino nulo");
   ASSERT_FALSE(copiar_con_punteros(NULL, 10, "Test"));

   SUBCASE("Puntero de origen nulo");
   ASSERT_FALSE(copiar_con_punteros(arrtest, 10, NULL));

   SUBCASE("Capacidad cero");
   ASSERT_FALSE(copiar_con_punteros(arrtest, 0, "Test"));
}

TEST(prueba_concatenar_punteros_exito)
{
   char arrtest[20] = "Hermoso";
   bool resultado = concatenar_punteros(arrtest, sizeof(arrtest), " dia!");

   ASSERT_TRUE(resultado);
   ASSERT_STR_EQ("Hermoso dia!", arrtest);
}

TEST(prueba_concatenar_punteros_truncamiento)
{
   char arrtest[8] = "Es";
   bool resultado = concatenar_punteros(arrtest, sizeof(arrtest), " verdad!");

   ASSERT_FALSE(resultado);
   ASSERT_STR_EQ("Es verd", arrtest);
}

TEST(prueba_concatenar_punteros_null)
{
   char arrtest[10] = "Test";

   SUBCASE("Puntero de destino nulo");
   ASSERT_FALSE(concatenar_punteros(NULL, 10, "Plus"));

   SUBCASE("Puntero de origen nulo");
   ASSERT_FALSE(concatenar_punteros(arrtest, 10, NULL));

   SUBCASE("Capacidad cero");
   ASSERT_FALSE(concatenar_punteros(arrtest, 0, "Plus"));
}

int main(int conteo_args, char **argumentos)
{
   TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
   RUN_TEST(prueba_copiar_con_punteros_exito);
   RUN_TEST(prueba_copiar_con_punteros_truncamiento);
   RUN_TEST(prueba_copiar_con_punteros_null);
   RUN_TEST(prueba_concatenar_punteros_exito);
   RUN_TEST(prueba_concatenar_punteros_truncamiento);
   RUN_TEST(prueba_concatenar_punteros_null);
   return TEST_REPORT();
}

// La herramienta gaff detecto los errores
// 0x300Dh, 0x001Dh, 0x001Eh, 0x2009h,
// 0x0009h los cuales considero que no
// se aplican en mi codigo.
