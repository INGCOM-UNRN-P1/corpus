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

TEST(prueba_copiar_con_punteros)
{
    char origen[] = "Adios, Mundo...";
    char destino[16];
    char destino_truncado[10];

    SUBCASE("Caso normal");
    ASSERT_TRUE(copiar_con_punteros(destino, sizeof(destino), origen));
    ASSERT_STR_EQ(origen, destino);

    SUBCASE("Caso con truncamiento");
    ASSERT_FALSE(copiar_con_punteros(destino_truncado, sizeof(destino_truncado), origen));
    ASSERT_STR_EQ("Adios, Mu", destino_truncado);

    SUBCASE("Casos con punteros nulos y capacidad 0");
    ASSERT_FALSE(copiar_con_punteros(NULL, sizeof(destino), origen));
    ASSERT_FALSE(copiar_con_punteros(destino, 0, origen));
    ASSERT_FALSE(copiar_con_punteros(destino, sizeof(destino), NULL));

}

TEST(prueba_concatenar_con_punteros)
{
    char origen[] = "Mundo...";
    char destino[17] = "Adios, ";
    char destino_truncado[10] = "Adios, ";
    
    SUBCASE("Caso normal");
    ASSERT_TRUE(concatenar_con_punteros(destino, 17, origen));
    ASSERT_STR_EQ("Adios, Mundo...", destino);

    SUBCASE("Caso con truncamiento");
    ASSERT_FALSE(concatenar_con_punteros(destino_truncado, 10, origen));
    ASSERT_STR_EQ("Adios, Mu", destino_truncado);

    SUBCASE("Punteros nulos y capacidad cero");    
    ASSERT_FALSE(concatenar_con_punteros(NULL, 30, origen));
    ASSERT_FALSE(concatenar_con_punteros(destino_truncado, 0, origen));
    ASSERT_FALSE(concatenar_con_punteros(destino_truncado, 30, NULL));

}

TEST(prueba_longitud_con_punteros)
{
    SUBCASE("Cadena nula o capacidad cero");
    ASSERT_INT_EQ(0, (int)longitud_con_punteros(NULL, 10));
    ASSERT_INT_EQ(0, (int)longitud_con_punteros("hola", 0));

    SUBCASE("Medicion dentro del limite");
    ASSERT_INT_EQ(0, (int)longitud_con_punteros("", 10));
    ASSERT_INT_EQ(4, (int)longitud_con_punteros("hola", 10));

    SUBCASE("Cadena que sobrepasa capacidad");
    ASSERT_INT_EQ(5, (int)longitud_con_punteros("programacion", 5));
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    RUN_TEST(prueba_longitud_con_punteros);
    return TEST_REPORT();
}
