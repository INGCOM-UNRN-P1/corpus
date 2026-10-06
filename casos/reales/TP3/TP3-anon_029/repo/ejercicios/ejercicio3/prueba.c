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

bool copiar_arreglo(const int *arreglo, int *destino, size_t capacidad);
bool invertir_arreglo(int *arreglo, size_t capacidad);

TEST(prueba_copiar_arreglo)
{
    const int arreglo[] = {1, 2, 3, 4};
    int destino[10];

    SUBCASE("Punteros NULL");
    bool resultado_null_origen = copiar_arreglo(NULL, destino, 4);
    ASSERT_INT_EQ(0, resultado_null_origen);
    bool resultado_null_destino = copiar_arreglo(arreglo, NULL, 4);
    ASSERT_INT_EQ(0, resultado_null_destino);   

    SUBCASE("Capcidad 0");
    bool resultado_capacidad0 = copiar_arreglo(arreglo, destino, 0);
    ASSERT_INT_EQ(0, resultado_capacidad0);

    SUBCASE("Copia valida");
    ASSERT_TRUE(copiar_arreglo(arreglo, destino, 10));
    ASSERT_INT_EQ(1, *(destino + 0));
    ASSERT_INT_EQ(2, *(destino + 1));
    ASSERT_INT_EQ(3, *(destino + 2));
    ASSERT_INT_EQ(4, *(destino + 3));
}

TEST(prueba_arreglo_invertir)
{
    int arreglo[] = {1, 2, 3, 4};

    SUBCASE("Puntero NULL");
    bool resultado_null_origen = arreglo_invertir(NULL, 4);
    ASSERT_INT_EQ(0, resultado_null_origen);

    SUBCASE("Capcidad 0");
    bool resultado_capacidad0 = arreglo_invertir(arreglo, 0);
    ASSERT_INT_EQ(0, resultado_capacidad0);

    SUBCASE("Inversion   valida");
    ASSERT_TRUE(arreglo_invertir(arreglo, 4));
    ASSERT_INT_EQ(4, *(arreglo + 0));
    ASSERT_INT_EQ(3, *(arreglo + 1));
    ASSERT_INT_EQ(2, *(arreglo + 2));
    ASSERT_INT_EQ(1, *(arreglo + 3));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_arreglo_invertir);
    return TEST_REPORT();
}
