
/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include "../ejercicio4/matriz_dinamica.h"
#include "consulta_csv.h"
#include "p1_test.h"
#include <stdio.h>
#include <stdlib.h>

#define RUTA_PRUEBA "tp4_prueba_exportacion.tmp"

TEST(prueba_filtrar_filas_csv)
{
    int primera[] = {1, 10};
    int segunda[] = {2, 20};
    int tercera[] = {3, 30};
    int *matriz[] = {primera, segunda, tercera};

    size_t seleccionadas = 0;
    int **filtrada = NULL;

    SUBCASE("Filtro estricto, orden original y copia independiente");

    filtrada = filtrar_filas_csv(
        matriz,
        3,
        2,
        1,
        10,
        &seleccionadas
    );

    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_INT_EQ(2, (int)seleccionadas);

    ASSERT_INT_EQ(2, filtrada[0][0]);
    ASSERT_INT_EQ(20, filtrada[0][1]);
    ASSERT_INT_EQ(3, filtrada[1][0]);
    ASSERT_INT_EQ(30, filtrada[1][1]);

    filtrada[0][0] = 99;

    ASSERT_INT_EQ(2, segunda[0]);

    matriz_destruir(filtrada);
    filtrada = NULL;


    SUBCASE("Todas las filas");

    filtrada = filtrar_filas_csv(
        matriz,
        3,
        2,
        0,
        0,
        &seleccionadas
    );

    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_INT_EQ(3, (int)seleccionadas);

    matriz_destruir(filtrada);
    filtrada = NULL;


    SUBCASE("Ninguna fila");

    filtrada = filtrar_filas_csv(
        matriz,
        3,
        2,
        0,
        3,
        &seleccionadas
    );

    ASSERT_PTR_NULL(filtrada);
    ASSERT_INT_EQ(0, (int)seleccionadas);


    SUBCASE("Parametros invalidos");

    ASSERT_PTR_NULL(
        filtrar_filas_csv(
            NULL,
            3,
            2,
            0,
            0,
            &seleccionadas
        )
    );

    ASSERT_PTR_NULL(
        filtrar_filas_csv(
            matriz,
            3,
            2,
            2,
            0,
            &seleccionadas
        )
    );

    ASSERT_PTR_NULL(
        filtrar_filas_csv(
            matriz,
            0,
            2,
            0,
            0,
            &seleccionadas
        )
    );

    ASSERT_PTR_NULL(
        filtrar_filas_csv(
            matriz,
            3,
            2,
            0,
            0,
            NULL
        )
    );
}

TEST(prueba_estadisticas)
{
    int primera[] = {1, -10};
    int segunda[] = {2, 20};
    int *matriz[] = {primera, segunda};

    float *sumas = NULL;
    float *promedios = NULL;

    SUBCASE("Sumas por columna");

    sumas = sumar_columnas_csv(
        matriz,
        2,
        2
    );

    ASSERT_PTR_NOT_NULL(sumas);

    ASSERT_DOUBLE_EQ(
        3.0,
        sumas[0],
        0.001
    );

    ASSERT_DOUBLE_EQ(
        10.0,
        sumas[1],
        0.001
    );

    free(sumas);
    sumas = NULL;


    SUBCASE("Promedios por columna");

    promedios = promediar_columnas_csv(
        matriz,
        2,
        2
    );

    ASSERT_PTR_NOT_NULL(promedios);

    ASSERT_DOUBLE_EQ(
        1.5,
        promedios[0],
        0.001
    );

    ASSERT_DOUBLE_EQ(
        5.0,
        promedios[1],
        0.001
    );

    free(promedios);
    promedios = NULL;


    SUBCASE("Parametros invalidos");

    ASSERT_PTR_NULL(
        sumar_columnas_csv(
            NULL,
            2,
            2
        )
    );

    ASSERT_PTR_NULL(
        promediar_columnas_csv(
            matriz,
            0,
            2
        )
    );

    ASSERT_PTR_NULL(
        sumar_columnas_csv(
            matriz,
            2,
            0
        )
    );
}

TEST(prueba_exportar_csv)
{
    int primera[] = {1, -10};
    int segunda[] = {2, 20};
    int *matriz[] = {primera, segunda};

    size_t filas = 0;
    size_t columnas = 0;

    int **cargada = NULL;

    FILE *archivo = NULL;
    char linea[64] = {0};


    SUBCASE("Exportacion de datos");

    ASSERT_TRUE(
        exportar_matriz_csv(
            RUTA_PRUEBA,
            matriz,
            2,
            2
        )
    );

    archivo = fopen(
        RUTA_PRUEBA,
        "r"
    );

    ASSERT_PTR_NOT_NULL(archivo);

    ASSERT_PTR_NOT_NULL(
        fgets(
            linea,
            sizeof(linea),
            archivo
        )
    );

    ASSERT_STR_EQ(
        "1,-10\n",
        linea
    );

    ASSERT_PTR_NOT_NULL(
        fgets(
            linea,
            sizeof(linea),
            archivo
        )
    );

    ASSERT_STR_EQ(
        "2,20\n",
        linea
    );

    ASSERT_INT_EQ(
        EOF,
        fgetc(archivo)
    );

    ASSERT_INT_EQ(
        0,
        fclose(archivo)
    );


    SUBCASE("Recarga del archivo exportado");

    cargada = matriz_cargar_desde_csv(
        RUTA_PRUEBA,
        &filas,
        &columnas
    );

    ASSERT_PTR_NOT_NULL(cargada);

    ASSERT_INT_EQ(
        2,
        (int)filas
    );

    ASSERT_INT_EQ(
        2,
        (int)columnas
    );

    ASSERT_INT_EQ(
        20,
        cargada[1][1]
    );

    matriz_destruir(cargada);
    cargada = NULL;

    ASSERT_INT_EQ(
        0,
        remove(RUTA_PRUEBA)
    );


    SUBCASE("Archivo vacio");

    ASSERT_TRUE(
        exportar_matriz_csv(
            RUTA_PRUEBA,
            NULL,
            0,
            2
        )
    );

    archivo = fopen(
        RUTA_PRUEBA,
        "r"
    );

    ASSERT_PTR_NOT_NULL(archivo);

    ASSERT_INT_EQ(
        EOF,
        fgetc(archivo)
    );

    ASSERT_INT_EQ(
        0,
        fclose(archivo)
    );

    ASSERT_INT_EQ(
        0,
        remove(RUTA_PRUEBA)
    );


    SUBCASE("Parametros invalidos");

    ASSERT_FALSE(
        exportar_matriz_csv(
            NULL,
            matriz,
            2,
            2
        )
    );

    ASSERT_FALSE(
        exportar_matriz_csv(
            RUTA_PRUEBA,
            NULL,
            1,
            2
        )
    );

    ASSERT_FALSE(
        exportar_matriz_csv(
            RUTA_PRUEBA,
            matriz,
            2,
            0
        )
    );
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 6",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_filtrar_filas_csv);
    RUN_TEST(prueba_estadisticas);
    RUN_TEST(prueba_exportar_csv);

    return TEST_REPORT();
}
