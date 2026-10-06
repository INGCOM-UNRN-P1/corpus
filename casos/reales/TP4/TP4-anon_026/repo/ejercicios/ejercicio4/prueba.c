/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "matriz_dinamica.h"
 
#define RUTA_TEMPORAL "prueba_matriz_temporal.csv"
 
/**
 * @brief Escribe un archivo de texto temporal para las pruebas de CSV.
 *
 * @param contenido Texto a escribir.
 * @return true si se pudo escribir el archivo completo.
 */
static bool escribir_csv(const char *contenido)
{
    FILE *archivo = fopen(RUTA_TEMPORAL, "w");
    if (archivo == NULL) {
        return false;
    }
    bool correcto = fputs(contenido, archivo) >= 0;
    fclose(archivo);
    return correcto;
}
 
TEST(prueba_matriz_crear_destruir)
{
    SUBCASE("Creacion: dimensiones, inicializacion en cero y acceso m[i][j]");
    int **matriz = matriz_crear(3, 4);
    ASSERT_PTR_NOT_NULL(matriz);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            ASSERT_INT_EQ(0, matriz[i][j]);
            matriz[i][j] = (int)(i * 10 + j);
        }
    }
    ASSERT_INT_EQ(0, matriz[0][0]);
    ASSERT_INT_EQ(13, matriz[1][3]);
    ASSERT_INT_EQ(23, matriz[2][3]);
 
    SUBCASE("Los datos forman un unico bloque contiguo");
    ASSERT_TRUE(matriz[1] == matriz[0] + 4);
    ASSERT_TRUE(matriz[2] == matriz[0] + 8);
    ASSERT_INT_EQ(23, matriz[0][11]); 
    matriz_destruir(matriz);
 
    SUBCASE("Matriz de una sola celda");
    int **una = matriz_crear(1, 1);
    ASSERT_PTR_NOT_NULL(una);
    ASSERT_INT_EQ(0, una[0][0]);
    una[0][0] = 7;
    ASSERT_INT_EQ(7, una[0][0]);
    matriz_destruir(una);
 
    SUBCASE("Destruir NULL no hace nada");
    matriz_destruir(NULL);
}
 
TEST(prueba_matriz_crear_invalida)
{
    SUBCASE("Dimensiones cero");
    ASSERT_PTR_NULL(matriz_crear(0, 3));
    ASSERT_PTR_NULL(matriz_crear(3, 0));
    ASSERT_PTR_NULL(matriz_crear(0, 0));
 
    SUBCASE("Desborde del tamano total");
    ASSERT_PTR_NULL(matriz_crear(SIZE_MAX, 2));
    ASSERT_PTR_NULL(matriz_crear(2, SIZE_MAX));
}
 
TEST(prueba_matriz_csv_valido)
{
    size_t filas = 99;
    size_t columnas = 99;
 
    SUBCASE("CSV simple de 2x3");
    ASSERT_TRUE(escribir_csv("1,2,3\n4,5,6\n"));
    int **matriz = matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(3, (int)columnas);
    ASSERT_INT_EQ(1, matriz[0][0]);
    ASSERT_INT_EQ(3, matriz[0][2]);
    ASSERT_INT_EQ(4, matriz[1][0]);
    ASSERT_INT_EQ(6, matriz[1][2]);
    matriz_destruir(matriz);
 
    SUBCASE("Espacios, negativos, CRLF, linea en blanco y sin salto final");
    ASSERT_TRUE(escribir_csv("1, -2 ,3\r\n\r\n4,5,+6"));
    int **tolerante = matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(tolerante);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(3, (int)columnas);
    ASSERT_INT_EQ(1, tolerante[0][0]);
    ASSERT_INT_EQ(-2, tolerante[0][1]);
    ASSERT_INT_EQ(3, tolerante[0][2]);
    ASSERT_INT_EQ(6, tolerante[1][2]);
    matriz_destruir(tolerante);
 
    SUBCASE("Una sola celda");
    ASSERT_TRUE(escribir_csv("42"));
    int **celda = matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(celda);
    ASSERT_INT_EQ(1, (int)filas);
    ASSERT_INT_EQ(1, (int)columnas);
    ASSERT_INT_EQ(42, celda[0][0]);
    matriz_destruir(celda);
 
    SUBCASE("Una sola columna");
    ASSERT_TRUE(escribir_csv("1\n2\n3\n"));
    int **columna = matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(columna);
    ASSERT_INT_EQ(3, (int)filas);
    ASSERT_INT_EQ(1, (int)columnas);
    ASSERT_INT_EQ(3, columna[2][0]);
    matriz_destruir(columna);
 
    remove(RUTA_TEMPORAL);
}
 
TEST(prueba_matriz_csv_invalido)
{
    size_t filas = 99;
    size_t columnas = 99;
 
    SUBCASE("Filas con distinta cantidad de valores");
    ASSERT_TRUE(escribir_csv("1,2\n3\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
    ASSERT_INT_EQ(0, (int)filas);
    ASSERT_INT_EQ(0, (int)columnas);
 
    SUBCASE("Valor que no es entero");
    filas = 99;
    columnas = 99;
    ASSERT_TRUE(escribir_csv("1,a\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
    ASSERT_INT_EQ(0, (int)filas);
    ASSERT_INT_EQ(0, (int)columnas);
 
    SUBCASE("Valor con basura pegada");
    ASSERT_TRUE(escribir_csv("12abc,3\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
 
    SUBCASE("Coma final o valores faltantes");
    ASSERT_TRUE(escribir_csv("1,2,\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
    ASSERT_TRUE(escribir_csv("1,,2\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
    ASSERT_TRUE(escribir_csv(",1\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
 
    SUBCASE("Valor fuera del rango de int");
    ASSERT_TRUE(escribir_csv("99999999999999999999\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
 
    SUBCASE("Archivo vacio o solo con lineas en blanco");
    ASSERT_TRUE(escribir_csv(""));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
    ASSERT_TRUE(escribir_csv("\n  \n\n"));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, &columnas));
 
    remove(RUTA_TEMPORAL);
 
    SUBCASE("Archivo inexistente y parametros nulos");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv("no_existe_este_archivo.csv", &filas, &columnas));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(NULL, &filas, &columnas));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, NULL, &columnas));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TEMPORAL, &filas, NULL));
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear_destruir);
    RUN_TEST(prueba_matriz_crear_invalida);
    RUN_TEST(prueba_matriz_csv_valido);
    RUN_TEST(prueba_matriz_csv_invalido);
    return TEST_REPORT();
}