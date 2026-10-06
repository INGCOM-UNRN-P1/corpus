/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"

TEST(prueba_buscar_primero)
{
    SUBCASE("elemento existente en el arreglo");
    {
        int array[] = {10, 20, 30, 40};
        const int *ptr = buscar_primero(array, 4, 30);
        
        ASSERT_TRUE(ptr != NULL);
        ASSERT_TRUE(ptr == (array + 2)); 
        ASSERT_INT_EQ(30, *ptr);
    }

    SUBCASE("elemento no existente");
    {
        int array[] = {10, 20, 30};
        const int *ptr = buscar_primero(array, 3, 99);
        ASSERT_TRUE(ptr == NULL);
    }

    SUBCASE("proteccion contra nulos y cantidad cero en busqueda");
    {
        int array[] = {10, 20, 30};
        const int *ptr_nulo = buscar_primero(NULL, 5, 10);
        const int *ptr_cero = buscar_primero(array, 0, 10); 
        
        ASSERT_TRUE(ptr_nulo == NULL);
        ASSERT_TRUE(ptr_cero == NULL);
    }
}

TEST(prueba_distancia_punteros)
{
    SUBCASE("distancia valida");
    {
        int array[] = {100, 200, 300, 400};
        const int *inicio = array;
        const int *elemento = array + 3; 
        
        ASSERT_INT_EQ(3, distancia_punteros(inicio, elemento));
    }

    SUBCASE("elemento apuntando al mismo inicio");
    {
        int array[] = {100, 200};
        ASSERT_INT_EQ(0, distancia_punteros(array, array));
    }

    SUBCASE("proteccion invalidos en distancia");
    {
        int array[] = {10, 20, 30};
        const int *inicio = array + 2;
        const int *invalido = array; 
        
        ASSERT_INT_EQ(-1, distancia_punteros(NULL, inicio));
        ASSERT_INT_EQ(-1, distancia_punteros(inicio, NULL));
        ASSERT_INT_EQ(-1, distancia_punteros(inicio, invalido));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("suite de pruebas: ejercicio 4", conteo_args, argumentos);
    
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    
    return TEST_REPORT();
}