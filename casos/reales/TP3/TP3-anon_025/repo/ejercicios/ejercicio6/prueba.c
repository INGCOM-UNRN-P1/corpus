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
    
    SUBCASE("buscar minimo en rango valido");
    {
        int datos[] = {50, 20, 40, 10, 30};
        const int *inicio = datos;
        const int *fin = datos + 5;
        const int *minimo = buscar_puntero_minimo(inicio, fin);

        ASSERT_TRUE(minimo != NULL);
        ASSERT_INT_EQ(10, *minimo);
        ASSERT_TRUE(minimo == (datos + 3));
    }

    SUBCASE("retorno nulo con parametros invalidos o rangos vacios");
    {
        int datos[] = {1, 2, 3};
        ASSERT_TRUE(buscar_puntero_minimo(NULL, datos + 3) == NULL);
        ASSERT_TRUE(buscar_puntero_minimo(datos, datos) == NULL);
    }
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("oredenar arreglo desordenado exitosamente");
    {
        int datos[] = {4, 2, 5, 1, 3};
        ordenar_seleccion_punteros(datos, 5);

        ASSERT_INT_EQ(1, datos[0]);
        ASSERT_INT_EQ(2, datos[1]);
        ASSERT_INT_EQ(3, datos[2]);
        ASSERT_INT_EQ(4, datos[3]);
        ASSERT_INT_EQ(5, datos[4]);
    }

    SUBCASE("arreglo ya ordenado se mantiene igual");
    {
        int datos[] = {10, 20, 30};
        ordenar_seleccion_punteros(datos, 3);

        ASSERT_INT_EQ(10, datos[0]);
        ASSERT_INT_EQ(20, datos[1]);
        ASSERT_INT_EQ(30, datos[2]);
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
