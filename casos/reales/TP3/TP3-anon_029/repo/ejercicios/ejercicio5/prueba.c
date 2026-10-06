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

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);
bool concatenar_con_punteros(char destino[], size_t capacidad, const char origen[]);

TEST(prueba_copiar_con_punteros)
{
    const char *origen = "hola";
    char destino[10];

    SUBCASE("Punteros NULL");
    bool null_origen = copiar_con_punteros(NULL, 10, origen);
    ASSERT_INT_EQ(0, null_origen);
    bool null_destino = copiar_con_punteros(destino, 10, NULL);
    ASSERT_INT_EQ(0, null_destino); 

    SUBCASE("Capcidad 0");
    bool capacidad0 = copiar_con_punteros(destino, 0, origen);
    ASSERT_INT_EQ(0, capacidad0);
    
    SUBCASE("Copia valida");
    ASSERT_TRUE(copiar_con_punteros(destino, 10, origen));
    ASSERT_INT_EQ('h', *(destino + 0));
    ASSERT_INT_EQ('o', *(destino + 1));
    ASSERT_INT_EQ('l', *(destino + 2));
    ASSERT_INT_EQ('a', *(destino + 3));
    ASSERT_INT_EQ('\0', *(destino + 4));
}

TEST(prueba_concatenar_con_punteros)
{
    const char *origen = "mundo";
    char destino[20];

    SUBCASE("Punteros NULL");
    bool null_destino = concatenar_con_punteros(NULL, 20, origen);
    ASSERT_INT_EQ(0, null_destino);
    bool null_origen = concatenar_con_punteros(destino, 20, NULL);
    ASSERT_INT_EQ(0, null_origen); 

    SUBCASE("Capcidad 0");
    bool capacidad0 = concatenar_con_punteros(destino, 0, origen);
    ASSERT_INT_EQ(0, capacidad0);

    SUBCASE("Copia valida");
    //pasamos el "hola" que se concatena con mundo.
    copiar_con_punteros(destino, 20, "hola ");
    bool exito = concatenar_con_punteros(destino, 20, origen);
    ASSERT_INT_EQ(1, exito);

    ASSERT_INT_EQ('h', *(destino + 0));
    ASSERT_INT_EQ('o', *(destino + 1));
    ASSERT_INT_EQ('l', *(destino + 2));
    ASSERT_INT_EQ('a', *(destino + 3));
    ASSERT_INT_EQ(' ', *(destino + 4));
    ASSERT_INT_EQ('m', *(destino + 5));
    ASSERT_INT_EQ('u', *(destino + 6));
    ASSERT_INT_EQ('n', *(destino + 7));
    ASSERT_INT_EQ('d', *(destino + 8));
    ASSERT_INT_EQ('o', *(destino + 9));
    ASSERT_INT_EQ('\0', *(destino + 10));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
