/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz_crear)
{
    SUBCASE("Creacion exitosa de matriz y asignacion de valores");
    size_t filas = 3, columnas = 4;
    int **m = matriz_crear(filas, columnas);
    ASSERT_PTR_NOT_NULL(m);
    ASSERT_PTR_NOT_NULL(m[0]); // Bloque contiguo asignado
    m[0][0] = 10;
    m[2][3] = 99;
    ASSERT_INT_EQ(10, m[0][0]);
    ASSERT_INT_EQ(99, m[2][3]);
    matriz_destruir(&m);
    ASSERT_PTR_NULL(m);

    SUBCASE("Dimensiones invalidas devuelven NULL");
    int **m_err1 = matriz_crear(0, 5);
    ASSERT_PTR_NULL(m_err1);
    int **m_err2 = matriz_crear(5, 0);
    ASSERT_PTR_NULL(m_err2);
}

TEST(prueba_matriz_destruir)
{
    SUBCASE("Destruccion de matriz y anulacion del puntero");
    int **m = matriz_crear(2, 2);
    ASSERT_PTR_NOT_NULL(m);
    matriz_destruir(&m);
    ASSERT_PTR_NULL(m);

    SUBCASE("Destruir un puntero NULL no produce fallos");
    int **m_null = NULL;
    matriz_destruir(&m_null);
    ASSERT_PTR_NULL(m_null);
}


TEST(prueba_matriz_cargar_desde_csv)
{
    SUBCASE("Carga correcta desde un archivo CSV valido");
    const char *path = "temp_prueba.csv";
    // Crear CSV temporal para el test
    FILE *f = fopen(path, "w");
    if (f != NULL)
    {
        fprintf(f, "10,20,30\n40,50,60\n");
        fclose(f);
    }
    size_t filas = 0, columnas = 0;
    int **m = matriz_cargar_desde_csv(path, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(m);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(3, (int)columnas);
    ASSERT_INT_EQ(10, m[0][0]);
    ASSERT_INT_EQ(30, m[0][2]);
    ASSERT_INT_EQ(40, m[1][0]);
    ASSERT_INT_EQ(60, m[1][2]);
    matriz_destruir(&m);
    ASSERT_PTR_NULL(m);
    remove(path);

    SUBCASE("Archivo inexistente devuelve NULL");
    size_t f_err = 99, c_err = 99;
    int **m_err = matriz_cargar_desde_csv("invalido_no_existe.csv", &f_err, &c_err);
    ASSERT_PTR_NULL(m_err);
}




int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear);
    RUN_TEST(prueba_matriz_destruir);
    RUN_TEST(prueba_matriz_cargar_desde_csv);
    return TEST_REPORT();
}
