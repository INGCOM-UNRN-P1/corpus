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
    
    SUBCASE("valor existe en el arreglo - cortocircuito");
    {
        int datos[] = { 10, 25, 30, 25, 50};
        const int *resultado = buscar_primero(datos, 5, 25);

        ASSERT_TRUE(resultado != NULL);
        ASSERT_INT_EQ(25, *resultado);
        ASSERT_TRUE(resultado == (datos + 1));
    }

    SUBCASE("valor inexistente o parametros invalidos");
    {
        int datos[] = {1, 2, 3};
        ASSERT_TRUE(buscar_primero(datos, 3, 99) == NULL);
        ASSERT_TRUE(buscar_primero(NULL, 3, 2) == NULL);
    }
}

TEST(prueba_distancia_punteros)
{
    SUBCASE("distancia valida dentro del arreglo");
    {
        int datos[] = {100, 200, 300, 400};
        const int *inicio = datos;
        const int *elemento_300 = datos + 2;

        ptrdiff_t distancia = distancia_punteros(inicio, elemento_300);
        ASSERT_INT_EQ(2, (int)distancia);
    }

    SUBCASE("retorno -1 por error o desbordamiento inverso");
    {
        int datos[] = {10, 20};
        const int *inicio = datos;
        const int *elemento_previo = datos -1;

        ASSERT_INT_EQ(-1, (int)distancia_punteros(inicio, elemento_previo));
        ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, inicio));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
