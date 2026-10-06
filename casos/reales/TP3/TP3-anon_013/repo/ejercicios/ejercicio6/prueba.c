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
    SUBCASE("Tiene exito");
    int arreglo [] = {8,4,5,2,1,3,6,-3,4,7,8,9};
    size_t cantidad = sizeof(arreglo) / sizeof(arreglo[0]);
    int *inicio = arreglo;
    int *fin = arreglo + cantidad - 1;
    ASSERT_INT_EQ(-3, *buscar_puntero_minimo(inicio, fin));

    SUBCASE("Valor minimo se repite");
    int arreglo2[] = {8,4,-3,2,1,3,6,-3,4,7,8,9};
    size_t cantidad2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
    int *inicio2 = arreglo2;
    int *fin2 = arreglo2 + cantidad2 - 1;
    ASSERT_PTR_EQ(&arreglo2[2], buscar_puntero_minimo(inicio2, fin2));  // si el valor minimo se repite, debe devolver el puntero al primero.

    SUBCASE("Fin < inicio");
    ASSERT_PTR_NULL(buscar_puntero_minimo(fin, inicio));

    SUBCASE("Punterop nulo");
    ASSERT_PTR_NULL(buscar_puntero_minimo(NULL, fin));
    ASSERT_PTR_NULL(buscar_puntero_minimo(inicio, NULL));

}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Tiene exito");
    int arreglo[] = {2,6,8,4,1,5,9,3,7};
    int esperado[] = {1,2,3,4,5,6,7,8,9};
    size_t cantidad = sizeof(arreglo) / sizeof(arreglo[0]);
    ordenar_seleccion_punteros(arreglo, cantidad);
    ASSERT_ARRAY_INT_EQ(esperado, arreglo, cantidad);

    SUBCASE("Cantidad < 2");
    int arreglo2[] = {2,6,8,4,1,5,9,3,7};
    int esperado2[] = {2,6,8,4,1,5,9,3,7};
    ordenar_seleccion_punteros(arreglo2, 1);
    ASSERT_ARRAY_INT_EQ(esperado2, arreglo2, 1);
    ordenar_seleccion_punteros(arreglo2, 0);
    ASSERT_ARRAY_INT_EQ(esperado2, arreglo2, 0);

    SUBCASE("Arreglo con elementos repetidos");
    int arreglo3[] = {8,5,1,4,7,3,6,2,4,5,6,1,9,8,2,9,7,3};
    int esperado3[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
    size_t cantidad3 = sizeof(arreglo3) / sizeof(arreglo3[0]);
    ordenar_seleccion_punteros(arreglo3, cantidad3);
    ASSERT_ARRAY_INT_EQ(esperado3, arreglo3, cantidad3);

    SUBCASE("Arreglo nulo");
    ordenar_seleccion_punteros(NULL, 5);    // no debería explotar

}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);

    return TEST_REPORT();
}
