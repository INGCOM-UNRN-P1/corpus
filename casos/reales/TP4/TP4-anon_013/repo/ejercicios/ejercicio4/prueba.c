/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz_crear)
{
    SUBCASE("Creacion exitosa");
    int **matriz = matriz_crear(3, 4, NULL);
    ASSERT_PTR_NOT_NULL(matriz);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            ASSERT_INT_EQ(0, matriz[i][j]);
        }
    }
    ASSERT_PTR_EQ(matriz[0] + 4, matriz[1]);  // las filas son diferentes punteros dentro del mismo bloque
    ASSERT_PTR_EQ(matriz[0] + 8, matriz[2]);  // de memoria espaciados 'columna' espacios.
    matriz[2][3] = 99;
    ASSERT_INT_EQ(99, matriz[2][3]);
    matriz_destruir_v2(&matriz);

    SUBCASE("Matriz de un unico numero");
    matriz = matriz_crear(1, 1, NULL);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(0, matriz[0][0]);
    matriz_destruir_v2(&matriz);

    SUBCASE("Parametros invalisod");
    ASSERT_PTR_NULL(matriz_crear(0, 4, NULL));
    ASSERT_PTR_NULL(matriz_crear(3, 0, NULL));
}

TEST(prueba_matriz_destruir_v2)
{
    SUBCASE("Destruccion exitosa");
    int **matriz = matriz_crear(2, 2, NULL);
    ASSERT_PTR_NOT_NULL(matriz);
    matriz_destruir_v2(&matriz);
    ASSERT_PTR_NULL(matriz);

    SUBCASE("punteros nulos");
    int **ptr_nulo = NULL;
    matriz_destruir_v2(&ptr_nulo);
    matriz_destruir_v2(NULL);
}

//_________________ ESTAS PRUEBAS LAS DISEÑO LA IA _________________

#define RUTA_TMP "prueba_tmp.csv"


static void escribir_csv(const char *ruta, const char *contenido)
{
    FILE *f = fopen(ruta, "w");     // "w" si no existe el archivo lo crea, si existe lo sobreescribe
    if (f != NULL)
    {
        fputs(contenido, f);
        fclose(f);
    }
}

TEST(prueba_matriz_cargar_desde_csv)
{
    size_t filas = 0;
    size_t columnas = 0;

    SUBCASE("CSV valido de 2x3");
    escribir_csv(RUTA_TMP, "1,2,3\n4,5,6\n");
    int **m = matriz_cargar_desde_csv(RUTA_TMP, &filas, &columnas, NULL);
    ASSERT_PTR_NOT_NULL(m);
    ASSERT_UINT_EQ(2, filas);
    ASSERT_UINT_EQ(3, columnas);
    int esperado[] = {1, 2, 3, 4, 5, 6};
    ASSERT_ARRAY_INT_EQ(esperado, m[0], 6);
    matriz_destruir_v2(&m);

    SUBCASE("Lineas vacias, espacios y negativos");
    escribir_csv(RUTA_TMP, "\n -1, 2\n\n3,-4\n\n");
    m = matriz_cargar_desde_csv(RUTA_TMP, &filas, &columnas, NULL);
    ASSERT_PTR_NOT_NULL(m);
    ASSERT_UINT_EQ(2, filas);
    ASSERT_UINT_EQ(2, columnas);
    ASSERT_INT_EQ(-1, m[0][0]);
    ASSERT_INT_EQ(-4, m[1][1]);
    matriz_destruir_v2(&m);

    SUBCASE("Fila con menos columnas");
    escribir_csv(RUTA_TMP, "1,2,3\n4,5\n");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TMP, &filas, &columnas, NULL));

    SUBCASE("Fila con mas columnas");
    escribir_csv(RUTA_TMP, "1,2\n3,4,5\n");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TMP, &filas, &columnas, NULL));

    SUBCASE("Valor que no es un numero");
    escribir_csv(RUTA_TMP, "1,2\n3,abc\n");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TMP, &filas, &columnas, NULL));

    SUBCASE("Archivo vacio o solo lineas vacias");
    escribir_csv(RUTA_TMP, "\n  \n\n");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TMP, &filas, &columnas, NULL));

    SUBCASE("Archivo inexistente y parametros nulos");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv("no_existe.csv", &filas, &columnas, NULL));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(NULL, &filas, &columnas, NULL));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TMP, NULL, &columnas, NULL));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_TMP, &filas, NULL, NULL));

    remove(RUTA_TMP);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear);
    RUN_TEST(prueba_matriz_destruir_v2);
    RUN_TEST(prueba_matriz_cargar_desde_csv);

    return TEST_REPORT();
}
