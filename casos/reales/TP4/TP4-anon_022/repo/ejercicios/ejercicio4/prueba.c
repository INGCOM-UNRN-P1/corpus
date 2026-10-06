/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz_crear)
{
    SUBCASE("Crea una matriz valida");

    int **matriz = matriz_crear(3, 4);

    ASSERT_PTR_NOT_NULL(matriz);

    matriz_destruir(matriz);


    SUBCASE("Permite acceder a sus elementos");

    matriz = matriz_crear(2, 3);

    ASSERT_PTR_NOT_NULL(matriz);

    matriz[0][0] = 10;
    matriz[0][1] = 20;
    matriz[1][2] = 30;

    ASSERT_INT_EQ(10, matriz[0][0]);
    ASSERT_INT_EQ(20, matriz[0][1]);
    ASSERT_INT_EQ(30, matriz[1][2]);

    matriz_destruir(matriz);


    SUBCASE("Las filas pertenecen al mismo bloque contiguo");

    matriz = matriz_crear(3, 4);

    ASSERT_PTR_NOT_NULL(matriz);

    ASSERT_PTR_EQ(matriz[0] + 4, matriz[1]);
    ASSERT_PTR_EQ(matriz[1] + 4, matriz[2]);

    matriz_destruir(matriz);


    SUBCASE("Cero filas retorna NULL");

    matriz = matriz_crear(0, 4);

    ASSERT_PTR_NULL(matriz);


    SUBCASE("Cero columnas retorna NULL");

    matriz = matriz_crear(4, 0);

    ASSERT_PTR_NULL(matriz);
}

TEST(prueba_matriz_destruir)
{
    SUBCASE("Acepta una matriz valida");

    int **matriz = matriz_crear(3, 3);

    ASSERT_PTR_NOT_NULL(matriz);

    matriz_destruir(matriz);

    ASSERT_TRUE(true);


    SUBCASE("Acepta NULL");

    matriz_destruir(NULL);

    ASSERT_TRUE(true);
}

static void crear_archivo_prueba(const char *ruta, const char *contenido)
{
    FILE *archivo = fopen(ruta, "w");

    if (archivo != NULL) {
        fputs(contenido, archivo);
        fclose(archivo);
    }
}

TEST(prueba_matriz_cargar_csv)
{
    SUBCASE("Carga una matriz rectangular");

    crear_archivo_prueba(
        "matriz_prueba.csv",
        "10,20,30\n"
        "40,50,60\n"
    );

    size_t filas = 0;
    size_t columnas = 0;

    int **matriz = matriz_cargar_desde_csv(
        "matriz_prueba.csv",
        &filas,
        &columnas
    );

    ASSERT_PTR_NOT_NULL(matriz);

    ASSERT_UINT_EQ(2, filas);
    ASSERT_UINT_EQ(3, columnas);

    ASSERT_INT_EQ(10, matriz[0][0]);
    ASSERT_INT_EQ(20, matriz[0][1]);
    ASSERT_INT_EQ(30, matriz[0][2]);

    ASSERT_INT_EQ(40, matriz[1][0]);
    ASSERT_INT_EQ(50, matriz[1][1]);
    ASSERT_INT_EQ(60, matriz[1][2]);

    matriz_destruir(matriz);
    remove("matriz_prueba.csv");


    SUBCASE("Archivo inexistente retorna NULL");

    filas = 0;
    columnas = 0;

    matriz = matriz_cargar_desde_csv(
        "archivo_que_no_existe.csv",
        &filas,
        &columnas
    );

    ASSERT_PTR_NULL(matriz);


    SUBCASE("Archivo vacio retorna NULL");

    crear_archivo_prueba(
        "matriz_vacia.csv",
        ""
    );

    filas = 0;
    columnas = 0;

    matriz = matriz_cargar_desde_csv(
        "matriz_vacia.csv",
        &filas,
        &columnas
    );

    ASSERT_PTR_NULL(matriz);

    remove("matriz_vacia.csv");
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 4",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_matriz_crear);
    RUN_TEST(prueba_matriz_destruir);
    RUN_TEST(prueba_matriz_cargar_csv);

    return TEST_REPORT();
}