/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_buscar_puntero_minimo)
{
    SUBCASE("Casos bordes - NULL o rango inválido");
    {
        int datos[] = {10, 20, 30};
        ASSERT_TRUE(buscar_puntero_minimo(NULL, datos + 3) == NULL);
        ASSERT_TRUE(buscar_puntero_minimo(datos, NULL) == NULL);
        ASSERT_TRUE(buscar_puntero_minimo(datos, datos) == NULL);      // Rango de 0 elementos
        ASSERT_TRUE(buscar_puntero_minimo(datos + 2, datos) == NULL);  // inicio > fin
    }
    SUBCASE("Búsqueda exitosa de mínimo");
    {
        int datos[] = {40, 10, 25, 5, 99};
        size_t cantidad = 5;
        const int *p_min = buscar_puntero_minimo(datos, datos + cantidad);
        ASSERT_TRUE(p_min == (datos + 3));
        ASSERT_INT_EQ(5, *p_min);
        const int *p_sub_min = buscar_puntero_minimo(datos, datos + 3);
        ASSERT_TRUE(p_sub_min == (datos + 1));
        ASSERT_INT_EQ(10, *p_sub_min);
    }
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Casos bordes - NULL o cantidad menor a 2");
    {
        int datos[] = {42};

        ordenar_seleccion_punteros(NULL, 5);
        ordenar_seleccion_punteros(datos, 0);
        ordenar_seleccion_punteros(datos, 1);
        ASSERT_INT_EQ(42, *datos);
    }

    SUBCASE("Ordenamiento de arreglo general con repetidos y negativos");
    {
        int datos[] = {5, -2, 12, -2, 0, 8};
        size_t cantidad = 6;

        ordenar_seleccion_punteros(datos, cantidad);

        ASSERT_INT_EQ(-2, *(datos + 0));
        ASSERT_INT_EQ(-2, *(datos + 1));
        ASSERT_INT_EQ(0,  *(datos + 2));
        ASSERT_INT_EQ(5,  *(datos + 3));
        ASSERT_INT_EQ(8,  *(datos + 4));
        ASSERT_INT_EQ(12, *(datos + 5));
    }
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
