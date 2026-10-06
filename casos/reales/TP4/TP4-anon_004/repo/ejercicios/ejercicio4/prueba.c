
/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

#define RUTA_PRUEBA "tp4_prueba_matriz.tmp"

static void escribir_csv(const char *contenido)
{
    FILE *archivo = fopen(RUTA_PRUEBA, "w");

    ASSERT_PTR_NOT_NULL(archivo);
    ASSERT_TRUE(fputs(contenido, archivo) >= 0);
    ASSERT_INT_EQ(0, fclose(archivo));
}

TEST(prueba_matriz_crear)
{
    int **matriz = NULL;
    size_t fila = 0;
    size_t columna = 0;

    SUBCASE("Bloque contiguo inicializado en cero");

    matriz = matriz_crear(3, 4);

    ASSERT_PTR_NOT_NULL(matriz);

    ASSERT_PTR_EQ(matriz[0] + 4, matriz[1]);
    ASSERT_PTR_EQ(matriz[0] + 8, matriz[2]);

    for (fila = 0; fila < 3; fila++)
    {
        for (columna = 0; columna < 4; columna++)
        {
            ASSERT_INT_EQ(0, matriz[fila][columna]);
        }
    }

    matriz[2][3] = 42;

    ASSERT_INT_EQ(42, matriz[0][11]);

    matriz_destruir(matriz);
    matriz = NULL;


    SUBCASE("Dimensiones invalidas");

    ASSERT_PTR_NULL(
        matriz_crear(0, 4)
    );

    ASSERT_PTR_NULL(
        matriz_crear(3, 0)
    );

    matriz_destruir(NULL);
}

TEST(prueba_cargar_csv)
{
    size_t filas = 0;
    size_t columnas = 0;
    int **matriz = NULL;

    SUBCASE("Carga de CSV rectangular");

    escribir_csv(
        "1,2,3\n"
        "4,5,6\n"
    );

    matriz = matriz_cargar_desde_csv(
        RUTA_PRUEBA,
        &filas,
        &columnas
    );

    ASSERT_INT_EQ(0, remove(RUTA_PRUEBA));

    ASSERT_PTR_NOT_NULL(matriz);

    ASSERT_INT_EQ(
        2,
        (int)filas
    );

    ASSERT_INT_EQ(
        3,
        (int)columnas
    );

    ASSERT_INT_EQ(1, matriz[0][0]);
    ASSERT_INT_EQ(2, matriz[0][1]);
    ASSERT_INT_EQ(3, matriz[0][2]);

    ASSERT_INT_EQ(4, matriz[1][0]);
    ASSERT_INT_EQ(5, matriz[1][1]);
    ASSERT_INT_EQ(6, matriz[1][2]);

    matriz_destruir(matriz);
    matriz = NULL;


    SUBCASE("Una fila y una columna");

    escribir_csv("-42\n");

    matriz = matriz_cargar_desde_csv(
        RUTA_PRUEBA,
        &filas,
        &columnas
    );

    ASSERT_INT_EQ(0, remove(RUTA_PRUEBA));

    ASSERT_PTR_NOT_NULL(matriz);

    ASSERT_INT_EQ(
        1,
        (int)filas
    );

    ASSERT_INT_EQ(
        1,
        (int)columnas
    );

    ASSERT_INT_EQ(
        -42,
        matriz[0][0]
    );

    matriz_destruir(matriz);
    matriz = NULL;
}

TEST(prueba_csv_invalido)
{
    size_t filas = 99;
    size_t columnas = 99;
    int **matriz = NULL;

    SUBCASE("Archivo inexistente");

    matriz = matriz_cargar_desde_csv(
        "archivo_inexistente.csv",
        &filas,
        &columnas
    );

    ASSERT_PTR_NULL(matriz);

    ASSERT_INT_EQ(
        0,
        (int)filas
    );

    ASSERT_INT_EQ(
        0,
        (int)columnas
    );


    SUBCASE("Parametros nulos");

    ASSERT_PTR_NULL(
        matriz_cargar_desde_csv(
            NULL,
            &filas,
            &columnas
        )
    );

    ASSERT_PTR_NULL(
        matriz_cargar_desde_csv(
            RUTA_PRUEBA,
            NULL,
            &columnas
        )
    );

    ASSERT_PTR_NULL(
        matriz_cargar_desde_csv(
            RUTA_PRUEBA,
            &filas,
            NULL
        )
    );


    SUBCASE("Filas con distinta cantidad de columnas");

    escribir_csv(
        "1,2,3\n"
        "4,5\n"
    );

    filas = 99;
    columnas = 99;

    matriz = matriz_cargar_desde_csv(
        RUTA_PRUEBA,
        &filas,
        &columnas
    );

    ASSERT_INT_EQ(0, remove(RUTA_PRUEBA));

    ASSERT_PTR_NULL(matriz);

    ASSERT_INT_EQ(
        0,
        (int)filas
    );

    ASSERT_INT_EQ(
        0,
        (int)columnas
    );
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 4",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_matriz_crear);
    RUN_TEST(prueba_cargar_csv);
    RUN_TEST(prueba_csv_invalido);

    return TEST_REPORT();
}
