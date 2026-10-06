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

TEST(prueba_copiar_arreglo)
{
    int fuente[] = {10, 20, 30, 40};
    int destino[] = {0, 0, 0, 0};
    bool resultado = copiar_arreglo(fuente, destino, 4);

    ASSERT_TRUE(resultado);

    ASSERT_INT_EQ(10, *destino);
    ASSERT_INT_EQ(20, *(destino + 1));
    ASSERT_INT_EQ(30, *(destino + 2));
    ASSERT_INT_EQ(40, *(destino + 3));
}

TEST(prueba_copiar_destino_mayor)
{
    int fuente[] = {10, 20, 30};
    int destino[] = {0, 0, 0, 0, 0};

    bool resultado = copiar_arreglo(fuente, destino, 3);

    ASSERT_TRUE(resultado);

    ASSERT_INT_EQ(10, *destino);
    ASSERT_INT_EQ(20, *(destino + 1));
    ASSERT_INT_EQ(30, *(destino + 2));
    ASSERT_INT_EQ(0, *(destino + 3));
    ASSERT_INT_EQ(0, *(destino + 4));
}

TEST(prueba_copiar_fuente_null)
{
    int destino[] = {0, 0, 0, 0};

    bool resultado = copiar_arreglo(NULL, destino, 4);

    ASSERT_FALSE(resultado);
}

TEST(prueba_copiar_destino_null)
{
    int fuente[] = {10, 20, 30, 40};

    bool resultado = copiar_arreglo(fuente, NULL, 4);

    ASSERT_FALSE(resultado);
}

TEST(prueba_copiar_cantidad_cero)
{
    int fuente[] = {10, 20, 30, 40};
    int destino[] = {0, 0, 0, 0};

    bool resultado = copiar_arreglo(fuente, destino, 0);

    ASSERT_FALSE(resultado);
}


TEST(prueba_invertir_arreglo_par)
{
    int arreglo[] = {10, 20, 30, 40};

    bool resultado = invertir_arreglo(arreglo, 4);

    ASSERT_TRUE(resultado);

    ASSERT_INT_EQ(40, *arreglo);
    ASSERT_INT_EQ(30, *(arreglo + 1));
    ASSERT_INT_EQ(20, *(arreglo + 2));
    ASSERT_INT_EQ(10, *(arreglo + 3));
}

TEST(prueba_invertir_arreglo_impar)
{
    int arreglo[] = {10, 20, 30, 40, 50};

    bool resultado = invertir_arreglo(arreglo, 5);

    ASSERT_TRUE(resultado);

    ASSERT_INT_EQ(50, *arreglo);
    ASSERT_INT_EQ(40, *(arreglo + 1));
    ASSERT_INT_EQ(30, *(arreglo + 2));
    ASSERT_INT_EQ(20, *(arreglo + 3));
    ASSERT_INT_EQ(10, *(arreglo + 4));
}

TEST(prueba_invertir_un_elemento)
{
    int arreglo[] = {10};

    bool resultado = invertir_arreglo(arreglo, 1);

    ASSERT_TRUE(resultado);
    ASSERT_INT_EQ(10, *arreglo);
}

TEST(prueba_invertir_arreglo_null)
{
    bool resultado = invertir_arreglo(NULL, 4);

    ASSERT_FALSE(resultado);
}

TEST(prueba_invertir_cantidad_cero)
{
    int arreglo[] = {10, 20, 30};

    bool resultado = invertir_arreglo(arreglo, 0);

    ASSERT_FALSE(resultado);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);

    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_copiar_destino_mayor);
    RUN_TEST(prueba_copiar_fuente_null);
    RUN_TEST(prueba_copiar_destino_null);
    RUN_TEST(prueba_copiar_cantidad_cero);

    RUN_TEST(prueba_invertir_arreglo_par);
    RUN_TEST(prueba_invertir_arreglo_impar);
    RUN_TEST(prueba_invertir_un_elemento);
    RUN_TEST(prueba_invertir_arreglo_null);
    RUN_TEST(prueba_invertir_cantidad_cero);

    return TEST_REPORT();
}
