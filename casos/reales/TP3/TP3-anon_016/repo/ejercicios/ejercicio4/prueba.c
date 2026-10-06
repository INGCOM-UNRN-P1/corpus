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
    int datos[] = {10, 25, 40, 25, 60};

    SUBCASE("Elemento presente, primera aparicion");
    int buscado = 25;
    const int *resultado = buscar_primero(datos, 5, &buscado);
    ASSERT_TRUE(resultado != NULL);
    ASSERT_INT_EQ(1, distancia_punteros(datos, resultado));

    SUBCASE("Elemento ausente");
    int ausente = 99;
    const int *no_encontrado = buscar_primero(datos, 5, &ausente);
    ASSERT_TRUE(no_encontrado == NULL);

    SUBCASE("Parametros invalidos");
    int val = 10;
    ASSERT_TRUE(buscar_primero(NULL, 5, &val) == NULL);
    ASSERT_TRUE(buscar_primero(datos, 5, NULL) == NULL);
    ASSERT_TRUE(buscar_primero(datos, 0, &val) == NULL);
}

TEST(prueba_distancia_punteros)
{
    int datos[] = {10, 20, 30, 40, 50};

    SUBCASE("Distancia al primer elemento");
    ASSERT_INT_EQ(0, distancia_punteros(datos, &datos[0]));

    SUBCASE("Distancia a un elemento intermedio");
    ASSERT_INT_EQ(3, distancia_punteros(datos, &datos[3]));

    SUBCASE("Punteros nulos o elemento anterior al inicio");
    ASSERT_INT_EQ(-1, distancia_punteros(NULL, &datos[0]));
    ASSERT_INT_EQ(-1, distancia_punteros(datos, NULL));
    ASSERT_INT_EQ(-1, distancia_punteros(&datos[1], &datos[0]));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
