/**
 * @file prueba.c
 * @brief Pruebas unitarias de libstring con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "cadenas.h"

TEST(prueba_cadena_duplicar_segura)
{
    SUBCASE("Duplicacion de cadena valida");
    char *dup = cadena_duplicar_segura("Programacion 1", 30);
    ASSERT_PTR_NOT_NULL(dup);
    ASSERT_STR_EQ("Programacion 1", dup);
    cadena_liberar_segura(&dup);
    ASSERT_PTR_NULL(dup);

    SUBCASE("Cadena nula o capacidad cero");
    ASSERT_PTR_NULL(cadena_duplicar_segura(NULL, 10));
    ASSERT_PTR_NULL(cadena_duplicar_segura("hola", 0));
}

TEST(prueba_cadena_unir_dinamica)
{
    SUBCASE("Union exitosa en heap");
    char *unida = cadena_unir_dinamica("Hola ", 10, "Mundo", 10);
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola Mundo", unida);
    cadena_liberar_segura(&unida);
    ASSERT_PTR_NULL(unida);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_unir_dinamica(NULL, 10, "test", 10));
    ASSERT_PTR_NULL(cadena_unir_dinamica("test", 10, NULL, 10));
}

TEST(prueba_cadena_subcadena_dinamica)
{
    char cadena[] = "Hola mundo";

    SUBCASE("Caso normal");
    char *mundo = cadena_subcadena_dinamica(cadena, 11, 5, 5);
    ASSERT_STR_EQ("mundo", mundo);
    char *mun = cadena_subcadena_dinamica(cadena, 11, 5, 3);
    ASSERT_STR_EQ("mun", mun);    
    char *holamundo = cadena_subcadena_dinamica(cadena, 11, 0, 10);
    ASSERT_STR_EQ("Hola mundo", holamundo);    

    SUBCASE("Caso cadenas vacias");
    char *vacia1 = cadena_subcadena_dinamica(cadena, 11, 100, 5);
    ASSERT_STR_EQ("", vacia1);    
    char *vacia2 = cadena_subcadena_dinamica(cadena, 11, 5, 0);
    ASSERT_STR_EQ("", vacia2);    


    SUBCASE("Caso argumentos invalidos");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(cadena, 0, 0, 10));
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 11, 0, 10));
    
    cadena_liberar_segura(&mundo);
    cadena_liberar_segura(&mun);
    cadena_liberar_segura(&holamundo);
    cadena_liberar_segura(&vacia1);
    cadena_liberar_segura(&vacia2);
}

TEST(prueba_cadena_invertir_dinamica)
{
    char cadena[] = "9 8 7 6 5 4 3 2 1 0";

    SUBCASE("Caso normal");
    char *cadena_invertida = cadena_invertir_dinamica(cadena, 20);
    ASSERT_STR_EQ("0 1 2 3 4 5 6 7 8 9", cadena_invertida);

    SUBCASE("Caso con truncamiento");
    char *cadena_truncada = cadena_invertir_dinamica(cadena, 6);
    ASSERT_STR_EQ("7 8 9", cadena_truncada);

    SUBCASE("Casos con argumentos invalidos");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 100));
    ASSERT_PTR_NULL(cadena_invertir_dinamica(cadena, 0));

    cadena_liberar_segura(&cadena_invertida);   
    cadena_liberar_segura(&cadena_truncada);   
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libstring", conteo_args, argumentos);
    RUN_TEST(prueba_cadena_duplicar_segura);
    RUN_TEST(prueba_cadena_unir_dinamica);
    RUN_TEST(prueba_cadena_subcadena_dinamica);
    RUN_TEST(prueba_cadena_invertir_dinamica);
    return TEST_REPORT();
}
