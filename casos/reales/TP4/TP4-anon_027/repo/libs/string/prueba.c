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
    SUBCASE("Extraccion exitosa en el medio de la cadena");
    char *sub = cadena_subcadena_dinamica("Hola Mundo", 20, 5, 5);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("Mundo", sub);
    cadena_liberar_segura(&sub);
    ASSERT_PTR_NULL(sub);

    SUBCASE("Cantidad solicitada excede la longitud restante");
    // 'cantidad' es 10, pero desde el índice 2 solo hay 2 caracteres ("la")
    char *recortada = cadena_subcadena_dinamica("Hola", 10, 2, 10);
    ASSERT_PTR_NOT_NULL(recortada);
    ASSERT_STR_EQ("la", recortada);
    cadena_liberar_segura(&recortada);
    ASSERT_PTR_NULL(recortada);

    SUBCASE("Inicio mayor o igual a la longitud (retorna cadena vacia en heap)");
    // El índice 10 está fuera de rango para "Hola", debe retornar "" en heap (no NULL)
    char *vacia = cadena_subcadena_dinamica("Hola", 10, 10, 2);
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);
    ASSERT_PTR_NULL(vacia);

    SUBCASE("Respeto del limite capacidad_max");
    // Inspecciona solo 4 caracteres ("Hola"), extrayendo desde el índice 1
    char *limitada = cadena_subcadena_dinamica("Hola Mundo", 4, 1, 3);
    ASSERT_PTR_NOT_NULL(limitada);
    ASSERT_STR_EQ("ola", limitada);
    cadena_liberar_segura(&limitada);
    ASSERT_PTR_NULL(limitada);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 10, 0, 5));
}
    


TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("Inversion exitosa de cadena normal");
    char *invertida = cadena_invertir_dinamica("Hola", 10);
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("aloH", invertida);
    cadena_liberar_segura(&invertida);
    ASSERT_PTR_NULL(invertida);

    SUBCASE("Inversion de cadena vacia");
    char *vacia = cadena_invertir_dinamica("", 10);
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);
    ASSERT_PTR_NULL(vacia);

    SUBCASE("Respeto del limite capacidad_max");
    // Solo toma los primeros 4 caracteres "Hola" e invierte
    char *recortada = cadena_invertir_dinamica("Hola Mundo", 4);
    ASSERT_PTR_NOT_NULL(recortada);
    ASSERT_STR_EQ("aloH", recortada);
    cadena_liberar_segura(&recortada);
    ASSERT_PTR_NULL(recortada);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 10));
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
