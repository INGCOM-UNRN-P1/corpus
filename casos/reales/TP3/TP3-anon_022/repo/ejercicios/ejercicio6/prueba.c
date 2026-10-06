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

TEST(prueba_buscar_minimo_casos_validos)
{
    int numeros[] = {5, 3, 8, 1, 9, 1};
    int ascendente[] = {-5, 0, 10, 20};
    int descendente[] = {20, 10, 0, -5};
    int unico[] = {42};
    int minimo_repetido[] = {7, 3, 5, 3, 9};
    const int *minimo = NULL;

    SUBCASE("Mínimo en el medio del rango");
    minimo = buscar_puntero_minimo(numeros, numeros + 6);
    ASSERT_PTR_NOT_NULL(minimo);
    ASSERT_INT_EQ(1, *minimo);
    ASSERT_PTR_EQ(numeros + 3, minimo);

    SUBCASE("Mínimo al inicio del rango");
    minimo = buscar_puntero_minimo(ascendente, ascendente + 4);
    ASSERT_PTR_EQ(ascendente, minimo);

    SUBCASE("Mínimo al final del rango");
    minimo = buscar_puntero_minimo(descendente, descendente + 4);
    ASSERT_PTR_EQ(descendente + 3, minimo);

    SUBCASE("Rango de un único elemento");
    minimo = buscar_puntero_minimo(unico, unico + 1);
    ASSERT_PTR_EQ(unico, minimo);

    SUBCASE("Mínimo repetido");
    minimo = buscar_puntero_minimo(minimo_repetido, minimo_repetido + 5);
    ASSERT_PTR_EQ(minimo_repetido + 1, minimo);
}

TEST(prueba_buscar_minimo_casos_invalidos)
{
    int numeros[] = {1, 2, 3};

    SUBCASE("Puntero de inicio nulo");
    ASSERT_PTR_NULL(buscar_puntero_minimo(NULL, numeros + 3));

    SUBCASE("Puntero de fin nulo");
    ASSERT_PTR_NULL(buscar_puntero_minimo(numeros, NULL));

    SUBCASE("Rango vacío (fin igual a inicio)");
    ASSERT_PTR_NULL(buscar_puntero_minimo(numeros, numeros));

    SUBCASE("Rango invertido (fin anterior a inicio)");
    ASSERT_PTR_NULL(buscar_puntero_minimo(numeros + 2, numeros));
}

TEST(prueba_ordenar_seleccion_casos_validos)
{
    int aleatorio[] = {5, 3, 8, 1, 9, 1, -4};
    int esperado_aleatorio[] = {-4, 1, 1, 3, 5, 8, 9};

    int ordenado[] = {1, 2, 3, 4, 5};
    int esperado_ordenado[] = {1, 2, 3, 4, 5};

    int inverso[] = {5, 4, 3, 2, 1};
    int esperado_inverso[] = {1, 2, 3, 4, 5};

    int repetidos[] = {4, 2, 4, 2, 4};
    int esperado_repetidos[] = {2, 2, 4, 4, 4};

    int dos_elementos[] = {8, 3};
    int esperado_dos_elementos[] = {3, 8};

    int iguales[] = {6, 6, 6, 6};
    int esperado_iguales[] = {6, 6, 6, 6};

    SUBCASE("Arreglo en orden aleatorio");
    ordenar_seleccion_punteros(aleatorio, 7);
    ASSERT_ARRAY_INT_EQ(esperado_aleatorio, aleatorio, 7);

    SUBCASE("Arreglo ya ordenado");
    ordenar_seleccion_punteros(ordenado, 5);
    ASSERT_ARRAY_INT_EQ(esperado_ordenado, ordenado, 5);

    SUBCASE("Arreglo en orden inverso");
    ordenar_seleccion_punteros(inverso, 5);
    ASSERT_ARRAY_INT_EQ(esperado_inverso, inverso, 5);

    SUBCASE("Arreglo con elementos repetidos");
    ordenar_seleccion_punteros(repetidos, 5);
    ASSERT_ARRAY_INT_EQ(esperado_repetidos, repetidos, 5);

    SUBCASE("Arreglo de dos elementos");
    ordenar_seleccion_punteros(dos_elementos, 2);
    ASSERT_ARRAY_INT_EQ(esperado_dos_elementos, dos_elementos, 2);

    SUBCASE("Arreglo con todos los elementos iguales");
    ordenar_seleccion_punteros(iguales, 4);
    ASSERT_ARRAY_INT_EQ(esperado_iguales, iguales, 4);
}

TEST(prueba_ordenar_seleccion_casos_borde)
{
    int vacio[] = {9, 9, 9};
    int esperado_vacio[] = {9, 9, 9};

    int unico[] = {7};
    int esperado_unico[] = {7};

    SUBCASE("Arreglo nulo no produce fallas");
    ordenar_seleccion_punteros(NULL, 5);
    ASSERT_TRUE(true);

    SUBCASE("Cantidad cero no modifica nada");
    ordenar_seleccion_punteros(vacio, 0);
    ASSERT_ARRAY_INT_EQ(esperado_vacio, vacio, 3);

    SUBCASE("Un único elemento permanece igual");
    ordenar_seleccion_punteros(unico, 1);
    ASSERT_ARRAY_INT_EQ(esperado_unico, unico, 1);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args,
                           argumentos);

    RUN_TEST(prueba_buscar_minimo_casos_validos);
    RUN_TEST(prueba_buscar_minimo_casos_invalidos);
    RUN_TEST(prueba_ordenar_seleccion_casos_validos);
    RUN_TEST(prueba_ordenar_seleccion_casos_borde);

    return TEST_REPORT();
}