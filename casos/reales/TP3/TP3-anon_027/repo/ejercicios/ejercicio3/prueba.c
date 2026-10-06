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
    SUBCASE("Copia exitosa de arreglo valido");
    int origen[] = {10, 20, 30, 40, 50};
    int destino[5] = {0};
    
    ASSERT_TRUE(copiar_arreglo(origen, 5, destino));
    ASSERT_INT_EQ(10, destino[0]);
    ASSERT_INT_EQ(20, destino[1]);
    ASSERT_INT_EQ(30, destino[2]);
    ASSERT_INT_EQ(40, destino[3]);
    ASSERT_INT_EQ(50, destino[4]);

    SUBCASE("Copia de un solo elemento");
    int origen_uno [] = {99};
    int destino_uno[] = {0};
    
    ASSERT_TRUE(copiar_arreglo(origen_uno, 1, destino_uno));
    ASSERT_INT_EQ(99, destino_uno[0]);

    SUBCASE("Parametros nulos o invalidos");
    int buf_origen[] = {1, 2, 3};
    int buf_destino[3] = {0};
    
    ASSERT_FALSE(copiar_arreglo(NULL, 3, buf_destino));
    ASSERT_FALSE(copiar_arreglo(buf_origen, 3, NULL));
    ASSERT_FALSE(copiar_arreglo(NULL, 3, NULL));

    SUBCASE("Cantidad igual a cero");
    int origen_cero[] = {5, 10};
    int destino_cero[] = {77, 88};
    
    // Si tu implementación retorna false al recibir cantidad == 0:
    ASSERT_FALSE(copiar_arreglo(origen_cero, 0, destino_cero));
    // Comprueba que no modificó la memoria destino
    ASSERT_INT_EQ(77, destino_cero[0]);
    ASSERT_INT_EQ(88, destino_cero[1]);
}


TEST(prueba_invertir_arreglo)
{
    SUBCASE("Invertir arreglo con cantidad impar");
    {
        int impar[] = {1, 2, 3, 4, 5};
        int comienzo = impar[0];
        int final = impar[4];

        ASSERT_TRUE(invertir_arreglo(impar, 5, &comienzo, &final));

        ASSERT_INT_EQ(5, impar[0]);
        ASSERT_INT_EQ(4, impar[1]);
        ASSERT_INT_EQ(3, impar[2]);
        ASSERT_INT_EQ(2, impar[3]);
        ASSERT_INT_EQ(1, impar[4]);
    }

    SUBCASE("Invertir arreglo con cantidad par");
    {
        int par[] = {10, 20, 30, 40};
        int comienzo = par[0];
        int final = par[3];

        ASSERT_TRUE(invertir_arreglo(par, 4, &comienzo, &final));

        ASSERT_INT_EQ(40, par[0]);
        ASSERT_INT_EQ(30, par[1]);
        ASSERT_INT_EQ(20, par[2]);
        ASSERT_INT_EQ(10, par[3]);
    }

    SUBCASE("Arreglo con un solo elemento");
    {
        int uno[] = {42};
        int comienzo = uno[0];
        int final = uno[0];

        ASSERT_TRUE(invertir_arreglo(uno, 1, &comienzo, &final));
        ASSERT_INT_EQ(42, uno[0]);
    }

    SUBCASE("Cantidad igual a cero");
    {
        int cero[] = {1, 2, 3};
        int comienzo = cero[0];
        int final = cero[2];

        ASSERT_FALSE(invertir_arreglo(cero, 0, &comienzo, &final));
    }

    SUBCASE("Arreglo NULL");
    {
        int comienzo = 0;
        int final = 0;
        ASSERT_FALSE(invertir_arreglo(NULL, 5, &comienzo, &final));
    }
}



int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
