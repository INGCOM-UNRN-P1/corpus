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
    SUBCASE("Caso nulos/incorrecto");
    int origen_caso_nulo[] = {1,2,3};
    int destino_caso_nulo[] = {1,2,3};
    ASSERT_FALSE(copiar_arreglo(NULL, 3, destino_caso_nulo, 3));
    ASSERT_FALSE(copiar_arreglo(origen_caso_nulo, 0, destino_caso_nulo, 3));
    ASSERT_FALSE(copiar_arreglo(origen_caso_nulo, 3, NULL, 3));
    ASSERT_FALSE(copiar_arreglo(origen_caso_nulo, 3, destino_caso_nulo, 0));
    
    SUBCASE("Caso de falta espacio");
    int origen_falta_espacio[] = {1,2,3};
    int destino_falta_espacio[] = {0};
    int esperado_falta_espacio[] = {1};
    ASSERT_TRUE(copiar_arreglo(origen_falta_espacio, 3, destino_falta_espacio, 1));
    ASSERT_ARRAY_INT_EQ(esperado_falta_espacio, destino_falta_espacio, 1);

    SUBCASE("Caso sobra espacio");
    int origen_sobra_espacio[] = {1,2,3};
    int destino_sobra_espacio[] = {0,0,0,0,0};
    int esperado_sobra_espacio[] = {1,2,3,0,0};
    ASSERT_TRUE(copiar_arreglo(origen_sobra_espacio, 3, destino_sobra_espacio, 5));
    ASSERT_ARRAY_INT_EQ(esperado_sobra_espacio, destino_sobra_espacio, 5);

    SUBCASE("Caso espacio justo");
    int origen[] = {1,2,3};
    int destino[] = {0,0,0};
    int esperado[] = {1,2,3};
    ASSERT_TRUE(copiar_arreglo(origen, 3, destino, 3));
    ASSERT_ARRAY_INT_EQ(esperado, destino, 3);


}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Caso nulos/incorrectos");
    int arreglo_incorrectos[] = {1,2,3,4,5};
    ASSERT_FALSE(invertir_arreglo(NULL, 5));
    ASSERT_FALSE(invertir_arreglo(arreglo_incorrectos, 0));

    SUBCASE("Caso inversion impar");
    int original[] = {1,2,3,4,5};
    int esperado[] = {5,4,3,2,1};
    ASSERT_TRUE(invertir_arreglo(original, 5));
    ASSERT_ARRAY_INT_EQ(esperado, original, 5);   

    SUBCASE("Caso inversion par");
    int original_par[] = {1,2,4,5};
    int esperado_par[] = {5,4,2,1};
    ASSERT_TRUE(invertir_arreglo(original_par, 4));
    ASSERT_ARRAY_INT_EQ(esperado_par, original_par, 4);

}
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
