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
    SUBCASE("Busqueda de elemento existente (primera ocurrencia)");
    int datos[] = {10, 20, 30, 20, 50};
    const int *resultado = buscar_primero(datos, 5, 20);
    
    // Verificamos que no sea NULL y que apunte exactamente al primer '20' (índice 1)
    ASSERT_TRUE(resultado != NULL);
    ASSERT_INT_EQ(20, *resultado);
    ASSERT_TRUE(resultado == &datos[1]);

    SUBCASE("Busqueda de elemento inexistente");
    const int *no_encontrado = buscar_primero(datos, 5, 99);
    ASSERT_TRUE(no_encontrado == NULL);

    SUBCASE("Busqueda con arreglo NULL");
    ASSERT_TRUE(buscar_primero(NULL, 5, 10) == NULL);
}

TEST(prueba_distancia_punteros)
{
    SUBCASE("Calculo de distancia valida");
    int datos[] = {5, 12, 18, 25};
    const int *elem = &datos[2]; // Apunta al valor 18 (índice 2)
    
    ptrdiff_t distancia = distancia_punteros(datos, elem);
    ASSERT_INT_EQ(2, (int)distancia);

    SUBCASE("Distancia con puntero igual al inicio (indice 0)");
    const int *inicio = &datos[0];
    ASSERT_INT_EQ(0, (int)distancia_punteros(datos, inicio));

    SUBCASE("Distancia con punteros nulos o invalidos");
    ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, elem));
    ASSERT_INT_EQ(-1, (int)distancia_punteros(datos, NULL));
    
    // Elemento ubicado antes del inicio del arreglo (incoherencia espacial)
    const int *invalido = &datos[0] - 1;
    ASSERT_INT_EQ(-1, (int)distancia_punteros(datos, invalido));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4 (Búsqueda y Distancia)", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
