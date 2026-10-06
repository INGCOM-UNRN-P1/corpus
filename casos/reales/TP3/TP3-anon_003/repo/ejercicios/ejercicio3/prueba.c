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

TEST(test_invertir_arreglo)
{
    SUBCASE("PUNTERO NULL")
    {
        ASSERT_FALSE(invertir_arreglo(NULL, 5));
    }
    SUBCASE("TEST VALIDO"){
        int datos[] = {1, 2, 3, 4, 5};
        ASSERT_TRUE(invertir_arreglo(datos, 5));
        ASSERT_INT_EQ(5, datos[0]);
        ASSERT_INT_EQ(4, datos[1]);
        ASSERT_INT_EQ(3, datos[2]);
        ASSERT_INT_EQ(2, datos[3]);
        ASSERT_INT_EQ(1, datos[4]);
    }
    
}

TEST (test_copiar_arreglo){
    SUBCASE("NULL"){
        int valido[] = {1, 2, 3};
        ASSERT_FALSE(copiar_arreglo(NULL, valido, 3))
    }
    SUBCASE("Test valido"){
        int origen[] = {1, 2, 3, 4, 5};
        int destino[5] = {0};
        size_t cantidad = 5;
        ASSERT_TRUE(copiar_arreglo(origen, destino, 0));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(test_invertir_arreglo);
    RUN_TEST(test_copiar_arreglo);
    return TEST_REPORT();
}
