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
    SUBCASE("Caso normal");
    int arreglo_normal[] = {1, 2, 3, 4, 5};
    int buffer_normal[5];   
    ASSERT_TRUE(copiar_arreglo(buffer_normal, 5, arreglo_normal, 5));
    ASSERT_ARRAY_INT_EQ(arreglo_normal, buffer_normal, 5);

    SUBCASE("Arreglos nulos");
    int *arreglo_nulo = NULL;
    ASSERT_FALSE(copiar_arreglo(buffer_normal, 5, arreglo_nulo, 0));
    ASSERT_FALSE(copiar_arreglo(arreglo_nulo, 0, arreglo_normal, 5));
    
    SUBCASE("Arreglos con capacidad cero");
    ASSERT_FALSE(copiar_arreglo(buffer_normal, 0, arreglo_normal, 5));
    ASSERT_FALSE(copiar_arreglo(buffer_normal, 5, arreglo_normal, 0));

    SUBCASE("Destino es mas chico que origen");
    ASSERT_FALSE(copiar_arreglo(buffer_normal, 4, arreglo_normal, 5));

}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Caso normal");
    int arreglo_normal[] = {1, 2, 3, 4, 5};
    int arreglo_invertido[] = {5, 4, 3, 2, 1};
    ASSERT_TRUE(invertir_arreglo(arreglo_normal, 5));
    ASSERT_ARRAY_INT_EQ(arreglo_invertido, arreglo_normal, 5);

    SUBCASE("Arreglo es nulo");
    int *arreglo_nulo = NULL;
    ASSERT_FALSE(invertir_arreglo(arreglo_nulo, 5));

    SUBCASE("Cantidad es igual a 1 o 0");
    int arreglo_1[] = {42};
    int arreglo_1_expected[] = {42};
    ASSERT_TRUE(invertir_arreglo(arreglo_1, 1));
    ASSERT_ARRAY_INT_EQ(arreglo_1_expected, arreglo_1, 1);
    ASSERT_FALSE(invertir_arreglo(arreglo_1, 0));

}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
