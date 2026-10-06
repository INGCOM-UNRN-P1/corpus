/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include "consulta_csv.h"
#include "p1_test.h"
#include <stdio.h>

TEST(prueba_agregar_una_linea)
{
    char **lineas = NULL;
    size_t cantidad = 0;

    bool pudo_agregar = agregar_linea(&lineas, &cantidad, "Primera línea\n");

    ASSERT_TRUE(pudo_agregar);
    ASSERT_TRUE(lineas != NULL);
    ASSERT_INT_EQ(cantidad, 1);

    ASSERT_TRUE(contiene_subcadena(*lineas, "Primera"));
    ASSERT_TRUE(contiene_subcadena(*lineas, "línea"));

    liberar_lineas(lineas, cantidad);
}

TEST(prueba_agregar_varias_lineas)
{
    char **lineas = NULL;
    size_t cantidad = 0;

    bool pudo_agregar = agregar_linea(&lineas, &cantidad, "Primera línea\n");

    ASSERT_TRUE(pudo_agregar);

    pudo_agregar = agregar_linea(&lineas, &cantidad, "Segunda línea\n");

    ASSERT_TRUE(pudo_agregar);

    pudo_agregar = agregar_linea(&lineas, &cantidad, "Tercera línea\n");

    ASSERT_TRUE(pudo_agregar);

    ASSERT_INT_EQ(cantidad, 3);

    ASSERT_TRUE(contiene_subcadena(*(lineas), "Primera"));
    ASSERT_TRUE(contiene_subcadena(*(lineas + 1), "Segunda"));
    ASSERT_TRUE(contiene_subcadena(*(lineas + 2), "Tercera"));

    liberar_lineas(lineas, cantidad);
}

TEST(prueba_linea_se_duplica)
{
    char linea_original[] = "Texto original\n";
    char **lineas = NULL;
    size_t cantidad = 0;

    bool pudo_agregar = agregar_linea(&lineas, &cantidad, linea_original);

    ASSERT_TRUE(pudo_agregar);

    *linea_original = 'X';

    ASSERT_TRUE(contiene_subcadena(*lineas, "Texto original"));

    liberar_lineas(lineas, cantidad);
}

TEST(prueba_contiene_subcadena)
{
    ASSERT_TRUE(contiene_subcadena("Programacion 1", "Programacion"));

    ASSERT_TRUE(contiene_subcadena("Programacion 1", "1"));

    ASSERT_TRUE(contiene_subcadena("Programacion 1", "grama"));

    ASSERT_TRUE(!contiene_subcadena("Programacion 1", "Python"));
}

TEST(prueba_subcadena_vacia)
{
    ASSERT_TRUE(contiene_subcadena("Cualquier texto", ""));

    ASSERT_TRUE(contiene_subcadena("", ""));
}

TEST(prueba_parametros_invalidos)
{
    char **lineas = NULL;
    size_t cantidad = 0;

    bool pudo_agregar = agregar_linea(NULL, &cantidad, "Texto");

    ASSERT_TRUE(!pudo_agregar);
    ASSERT_INT_EQ(cantidad, 0);

    pudo_agregar = agregar_linea(&lineas, NULL, "Texto");

    ASSERT_TRUE(!pudo_agregar);
    ASSERT_INT_EQ(cantidad, 0);

    pudo_agregar = agregar_linea(&lineas, &cantidad, NULL);

    ASSERT_TRUE(!pudo_agregar);
    ASSERT_INT_EQ(cantidad, 0);

    ASSERT_TRUE(!contiene_subcadena(NULL, "Texto"));
    ASSERT_TRUE(!contiene_subcadena("Texto", NULL));

    liberar_lineas(NULL, 0);
    liberar_lineas(lineas, cantidad);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args,
                          argumentos);

    RUN_TEST(prueba_agregar_una_linea);
    RUN_TEST(prueba_agregar_varias_lineas);
    RUN_TEST(prueba_linea_se_duplica);
    RUN_TEST(prueba_contiene_subcadena);
    RUN_TEST(prueba_subcadena_vacia);
    RUN_TEST(prueba_parametros_invalidos);

    return TEST_REPORT();
}
