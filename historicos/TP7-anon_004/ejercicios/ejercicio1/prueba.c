/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 1 con p1_test.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "matrices.h"
#include "matriz_csv.h"

bool matriz_cargar_csv(const char *ruta, matriz_t *destino);
bool matriz_guardar_csv(const char *ruta, const matriz_t *origen);

TEST(prueba_matriz_csv_ciclo_completo)
{
    const char *ruta_tmp = "prueba_tmp_matriz.csv";
    matriz_t m1;
    ASSERT_TRUE(matriz_crear(&m1, 2, 3));
    ASSERT_TRUE(matriz_asignar(&m1, 0, 0, 10));
    ASSERT_TRUE(matriz_asignar(&m1, 0, 1, 20));
    ASSERT_TRUE(matriz_asignar(&m1, 0, 2, 30));
    ASSERT_TRUE(matriz_asignar(&m1, 1, 0, 40));
    ASSERT_TRUE(matriz_asignar(&m1, 1, 1, 50));
    ASSERT_TRUE(matriz_asignar(&m1, 1, 2, 60));

    ASSERT_TRUE(matriz_guardar_csv(ruta_tmp, &m1));

    matriz_t m2;
    ASSERT_TRUE(matriz_cargar_csv(ruta_tmp, &m2));
    ASSERT_INT_EQ(2, (int)m2.cant_filas);
    ASSERT_INT_EQ(3, (int)m2.cant_columnas);

    int v = 0;
    matriz_obtener(&m2, 0, 2, &v);
    ASSERT_INT_EQ(30, v);
    matriz_obtener(&m2, 1, 1, &v);
    ASSERT_INT_EQ(50, v);

    matriz_destruir(&m1);
    matriz_destruir(&m2);
    remove(ruta_tmp);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_csv_ciclo_completo);
    return TEST_REPORT();
}
