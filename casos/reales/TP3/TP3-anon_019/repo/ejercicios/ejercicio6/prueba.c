/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_buscar_puntero_minimo)
{
    SUBCASE("encontrar el minimo en arreglo normal");
    {
        int array[] = {15, 8, 23, 4, 42};
        const int *inicio = array;
        const int *fin = array + 5;
        
        const int *minimo = buscar_puntero_minimo(inicio, fin);
        
        ASSERT_TRUE(minimo != NULL);
        ASSERT_INT_EQ(4, *minimo);
        ASSERT_TRUE(minimo == (array + 3)); 
    }

    SUBCASE("rango invalido o nulo");
    {
        int array[] = {1, 2, 3};
        ASSERT_TRUE(buscar_puntero_minimo(NULL, array + 3) == NULL);
        ASSERT_TRUE(buscar_puntero_minimo(array, NULL) == NULL);
        ASSERT_TRUE(buscar_puntero_minimo(array + 2, array) == NULL); 
    }
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("ordenar arreglo desordenado");
    {
        int array[] = {50, 20, 40, 10, 30};
        
        ASSERT_TRUE(ordenar_seleccion_punteros(array, 5));
        ASSERT_INT_EQ(10, *(array));
        ASSERT_INT_EQ(20, *(array + 1));
        ASSERT_INT_EQ(30, *(array + 2));
        ASSERT_INT_EQ(40, *(array + 3));
        ASSERT_INT_EQ(50, *(array + 4));
    }

    SUBCASE("ordenar arreglo ya ordenado");
    {
        int array[] = {1, 2, 3, 4};
        
        ASSERT_TRUE(ordenar_seleccion_punteros(array, 4));
        ASSERT_INT_EQ(1, *(array));
        ASSERT_INT_EQ(4, *(array + 3));
    }
    
    SUBCASE("proteccion contra nulos y cantidad cero");
    {
        int array[5] = {0};
        ASSERT_FALSE(ordenar_seleccion_punteros(NULL, 5));
        ASSERT_FALSE(ordenar_seleccion_punteros(array, 0));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("suite de pruebas: ejercicio 6", conteo_args, argumentos);
    
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    
    return TEST_REPORT();
}