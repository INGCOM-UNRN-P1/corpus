/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "puntero_cadena.h"
#include "p1_test.h"

TEST(probar_copiar_con_punteros) {
    char dest[20];

    // Copia completa
    ASSERT_TRUE(copiar_con_punteros(dest, sizeof(dest), "Hola"));
    ASSERT_STR_CASE_EQ(dest, "Hola");

    // Truncamiento por capacidad insuficiente
    ASSERT_FALSE(copiar_con_punteros(dest, 3, "Hola"));
    ASSERT_STR_CASE_EQ(dest, "Ho");

    // Casos invalidos / NULL
    ASSERT_FALSE(copiar_con_punteros(NULL, 10, "Hola"));
    ASSERT_FALSE(copiar_con_punteros(dest, 0, "Hola"));
}

TEST(probar_concatenar_con_punteros) {
    char dest[20] = "Hola ";

    // Concatenacion exitosa
    ASSERT_TRUE(concatenar_con_punteros(dest, sizeof(dest), "Mundo"));
    ASSERT_STR_CASE_EQ(dest, "Hola Mundo");

    // Truncamiento
    ASSERT_FALSE(concatenar_con_punteros(dest, 12, "!!!"));
    ASSERT_STR_CASE_EQ(dest, "Hola Mundo!");

    // Casos invalidos / NULL
    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "Test"));
}

int main(void) {
    RUN_TEST(probar_copiar_con_punteros);
    RUN_TEST(probar_concatenar_con_punteros);

    return 0;
}