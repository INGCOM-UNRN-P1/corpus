
/**
 * @file prueba.c
 * @brief Pruebas unitarias del Ejercicio 4 (matriz dinámica).
 */
 
#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"
 

static void escribir_archivo(const char *ruta, const char *contenido)
{
    FILE *archivo = fopen(ruta, "w");
 
    if (archivo != NULL)
    {
        fputs(contenido, archivo);
        fclose(archivo);
    }
}
 
TEST(prueba_matriz_crear)
{
    SUBCASE("Matriz de 2 x 3 inicializada en cero");
    int **matriz = matriz_crear(2, 3);
    ASSERT_TRUE(matriz != NULL);
    ASSERT_INT_EQ(0, matriz[0][0]);
    ASSERT_INT_EQ(0, matriz[1][2]);
    matriz[1][2] = 7;
    ASSERT_INT_EQ(7, matriz[1][2]);
    ASSERT_INT_EQ(0, matriz[0][0]);
    matriz_destruir(matriz);
 
    SUBCASE("Dimensiones invalidas");
    ASSERT_TRUE(matriz_crear(0, 3) == NULL);
    ASSERT_TRUE(matriz_crear(3, 0) == NULL);
}
 
TEST(prueba_matriz_destruir)
{
    SUBCASE("Matriz NULL no hace nada");
    matriz_destruir(NULL);
    ASSERT_TRUE(1);
}
 
TEST(prueba_matriz_cargar_desde_csv)
{
    size_t filas = 0;
    size_t columnas = 0;
 
    SUBCASE("CSV valido");
    escribir_archivo("prueba_matriz.csv", "2,3\n5,8,2\n1,9,4\n");
    int **matriz = matriz_cargar_desde_csv("prueba_matriz.csv", &filas,
                                           &columnas);
    ASSERT_TRUE(matriz != NULL);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(3, (int)columnas);
    ASSERT_INT_EQ(5, matriz[0][0]);
    ASSERT_INT_EQ(4, matriz[1][2]);
    matriz_destruir(matriz);
 
    SUBCASE("Archivo inexistente");
    ASSERT_TRUE(matriz_cargar_desde_csv("no_existe.csv", &filas, &columnas)
                == NULL);
    ASSERT_INT_EQ(0, (int)filas);
 
    SUBCASE("CSV con valores faltantes");
    escribir_archivo("prueba_matriz.csv", "2,3\n5,8\n");
    ASSERT_TRUE(matriz_cargar_desde_csv("prueba_matriz.csv", &filas,
                                        &columnas) == NULL);
    remove("prueba_matriz.csv");
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args,
                          argumentos);
    RUN_TEST(prueba_matriz_crear);
    RUN_TEST(prueba_matriz_destruir);
    RUN_TEST(prueba_matriz_cargar_desde_csv);
    return TEST_REPORT();
}