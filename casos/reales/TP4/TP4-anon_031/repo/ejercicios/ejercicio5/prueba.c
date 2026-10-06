/**
 * @file prueba.c
 * @brief Pruebas unitarias del Ejercicio 5.
 */

#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    size_t cantidad = 0U;
    char **campos = dividir_linea_csv("Maximiliano,25,Bariloche", ',', &cantidad);

    ASSERT_PTR_NOT_NULL(campos);
    ASSERT_UINT_EQ(3U, cantidad);
    ASSERT_STR_EQ("Maximiliano", campos[0]);
    ASSERT_STR_EQ("25", campos[1]);
    ASSERT_STR_EQ("Bariloche", campos[2]);
    liberar_arreglo_cadenas(&campos, cantidad);
    ASSERT_PTR_NULL(campos);

    SUBCASE("Campos vacios");
    campos = dividir_linea_csv("a,,c,", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(campos);
    ASSERT_UINT_EQ(4U, cantidad);
    ASSERT_STR_EQ("", campos[1]);
    ASSERT_STR_EQ("", campos[3]);
    liberar_arreglo_cadenas(&campos, cantidad);

    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cantidad));
    ASSERT_PTR_NULL(dividir_linea_csv("a,b", ',', NULL));
}

TEST(prueba_lista_cadenas_dinamica)
{
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0U;

    ASSERT_PTR_NULL(lista);
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "uno"));
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "dos"));
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "tres"));
    ASSERT_UINT_EQ(3U, cantidad);
    ASSERT_STR_EQ("uno", lista[0]);
    ASSERT_STR_EQ("dos", lista[1]);
    ASSERT_STR_EQ("tres", lista[2]);

    ASSERT_FALSE(lista_cadenas_agregar(NULL, &cantidad, "cuatro"));
    ASSERT_FALSE(lista_cadenas_agregar(&lista, NULL, "cuatro"));
    ASSERT_FALSE(lista_cadenas_agregar(&lista, &cantidad, NULL));

    lista_cadenas_destruir(lista, cantidad);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_lista_cadenas_dinamica);
    return TEST_REPORT();
}
