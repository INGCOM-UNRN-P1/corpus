/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros)
{
    SUBCASE("copia completa valida");
    {
        char destino[10];
        ASSERT_TRUE(copiar_con_punteros(destino, 10, "Hola"));
        ASSERT_INT_EQ('H', destino[0]);
        ASSERT_INT_EQ('a', destino[3]);
        ASSERT_INT_EQ('\0', destino[4]);
    }

    SUBCASE("truncamiento por limite de buffer");
    {
        char destino[5];
        ASSERT_FALSE(copiar_con_punteros(destino, 5, "Mundo")); 
        ASSERT_INT_EQ('M', destino[0]);
        ASSERT_INT_EQ('d', destino[3]);
        ASSERT_INT_EQ('\0', destino[4]);
    }

    SUBCASE("proteccion parametros invalidos en copia");
    {
        char destino[5];
        ASSERT_FALSE(copiar_con_punteros(NULL, 5, "Test"));
        ASSERT_FALSE(copiar_con_punteros(destino, 5, NULL));
        ASSERT_FALSE(copiar_con_punteros(destino, 0, "Test"));
    }
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("concatenacion completa valida");
    {
        char destino[15];
        copiar_con_punteros(destino, 15, "Hola ");
        
        ASSERT_TRUE(concatenar_con_punteros(destino, 15, "mundo"));
        ASSERT_INT_EQ('m', destino[5]);
        ASSERT_INT_EQ('o', destino[9]);
        ASSERT_INT_EQ('\0', destino[10]);
    }

    SUBCASE("truncamiento durante la concatenacion");
    {
        char destino[8];
        copiar_con_punteros(destino, 8, "Hola ");
        
        ASSERT_FALSE(concatenar_con_punteros(destino, 8, "mundo"));
        ASSERT_INT_EQ('m', destino[5]);
        ASSERT_INT_EQ('u', destino[6]);
        ASSERT_INT_EQ('\0', destino[7]);
    }
    
    SUBCASE("proteccion parametros invalidos en concatenacion");
    {
        char destino[10];
        ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "Test"));
        ASSERT_FALSE(concatenar_con_punteros(destino, 10, NULL));
        ASSERT_FALSE(concatenar_con_punteros(destino, 0, "Test"));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("suite de pruebas: ejercicio 5", conteo_args, argumentos);
    
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    
    return TEST_REPORT();
}