/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"
#include <stdlib.h>

TEST(prueba_creacion_destruccion_matriz)
{
    
    SUBCASE("Creacion y acceso bidimensional correcto");
    int **m = matriz_crear(2, 3);
    ASSERT_PTR_NOT_NULL(m);

    m[0][0] = 10;
    m[1][2] = 20;
    ASSERT_INT_EQ(10, m[0][0]);
    ASSERT_INT_EQ(20, m[1][2]);

    matriz_destruir(m);
    m = NULL;

    SUBCASE("Validacion de seguridad ante parametros nulos");
    ASSERT_PTR_NULL(matriz_crear(0, 5));
    ASSERT_PTR_NULL(matriz_crear(5, 0));
}

TEST(prueba_csv_matriz)
{
    SUBCASE("Simulacion completa de lectura de arvhico csv");
    FILE *f = fopen("test_matriz.csv", "w");
    ASSERT_PTR_NOT_NULL(f);
    fprintf(f, "2,2\n");
    fprintf(f, "5,10,\n");
    fprintf(f, "15, 20,\n");
    fclose(f);
    size_t filas = 0, columnas = 0; 
    int **m = matriz_cargar_desde_csv("test_matriz.csv", &filas, &columnas);

    ASSERT_PTR_NOT_NULL(m);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(2, (int)columnas);
    ASSERT_INT_EQ(5, m[0][0]);
    ASSERT_INT_EQ(20, m[1][1]);
    matriz_destruir(m);
    m = NULL;
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_creacion_destruccion_matriz);
    RUN_TEST(prueba_csv_matriz);
    return TEST_REPORT();
}
