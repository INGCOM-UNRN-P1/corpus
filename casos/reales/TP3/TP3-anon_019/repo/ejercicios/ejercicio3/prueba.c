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
    SUBCASE("copia valida de elementos");
    {
        int origen[] = {1, 2, 3};
        int destino[3] = {0, 0, 0};
        
        ASSERT_TRUE(copiar_arreglo(origen, destino, 3));
        ASSERT_INT_EQ(1, destino[0]);
        ASSERT_INT_EQ(2, destino[1]);
        ASSERT_INT_EQ(3, destino[2]);
    }

    SUBCASE("proteccion contra punteros nulos");
    {
        int array[3] = {0};
        ASSERT_FALSE(copiar_arreglo(NULL, array, 3));
        ASSERT_FALSE(copiar_arreglo(array, NULL, 3));
    }
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("inversion de arreglo de longitud par");
    {
        int par[] = {10, 20, 30, 40};
        
        ASSERT_TRUE(invertir_arreglo(par, 4));
        ASSERT_INT_EQ(40, par[0]);
        ASSERT_INT_EQ(30, par[1]);
        ASSERT_INT_EQ(20, par[2]);
        ASSERT_INT_EQ(10, par[3]);
    }

    SUBCASE("inversion de arreglo de longitud impar");
    {
        int impar[] = {1, 2, 3, 4, 5};
        
        ASSERT_TRUE(invertir_arreglo(impar, 5));
        ASSERT_INT_EQ(5, impar[0]);
        ASSERT_INT_EQ(3, impar[2]); 
        ASSERT_INT_EQ(1, impar[4]);
    }

    SUBCASE("proteccion contra nulos y cantidad cero");
    {
        int array[3] = {0};
        ASSERT_FALSE(invertir_arreglo(NULL, 3));
        ASSERT_FALSE(invertir_arreglo(array, 0));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("suite de pruebas: ejercicio 3", conteo_args, argumentos);
    
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    
    return TEST_REPORT();
}