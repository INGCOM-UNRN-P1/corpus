/**
 * @file prueba.c
 * @brief Pruebas unitarias de libcsv con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "csv.h"

TEST(prueba_csv_dimensiones)
{
    const char *ruta_tmp = "prueba_tmp_dim.csv";
    FILE *f = fopen(ruta_tmp, "w");
    if (f != NULL) {
        fprintf(f, "1,2,3\n4,5,6\n7,8,9\n10,11,12\n");
        fclose(f);

        ASSERT_INT_EQ(4, (int)csv_contar_filas(ruta_tmp));
        ASSERT_INT_EQ(3, (int)csv_contar_columnas(ruta_tmp));

        int buffer[12];
        size_t leidos = csv_leer_matriz(ruta_tmp, buffer, 4, 3);
        ASSERT_INT_EQ(12, (int)leidos);
        ASSERT_INT_EQ(1, buffer[0]);
        ASSERT_INT_EQ(12, buffer[11]);

        remove(ruta_tmp);
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libcsv", conteo_args, argumentos);
    RUN_TEST(prueba_csv_dimensiones);
    return TEST_REPORT();
}
