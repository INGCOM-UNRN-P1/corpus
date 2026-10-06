/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "cadena_dinamica.h"
//#include "../ejercicio5/lista_dinamica.h"


// Traida del ejercicio 5 para hacer mas legibles los tests, no se como incluir 
// codigo de otras carpetas y que lo compile el make
void lista_cadenas_destruir(char **lista, size_t cantidad)
{
    if (lista == NULL)
    {
        return;
    }
    
    for (size_t i = 0; i < cantidad; i++)
    {
        cadena_liberar_segura(&lista[i]);
    }
    free(lista);
    lista = NULL;
}

TEST(prueba_invertir_cadena_dinamico)
{
    char cadena[] = "3210";
    char cadena_vacia[] = "";
    
    SUBCASE("Caso normal");
    char *normal = invertir_cadena_dinamico(cadena, 5);
    ASSERT_STR_EQ("0123", normal);

    SUBCASE("Cadena vacia");
    char *vacia = invertir_cadena_dinamico(cadena_vacia, 1);
    ASSERT_STR_EQ("", vacia);

    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(invertir_cadena_dinamico(NULL, 1));
    ASSERT_PTR_NULL(invertir_cadena_dinamico(cadena, 0));

    cadena_liberar_segura(&normal);
    cadena_liberar_segura(&vacia);
}

TEST(prueba_partir_por_delimitador)
{
    char cadena[] = "123,4,,567890";
    size_t cantidad = 0;

    SUBCASE("Caso normal");
    char **lista_normal = NULL;
    lista_normal = partir_por_delimitador(cadena, 14, ',', &cantidad);
    ASSERT_INT_EQ(4, (int)cantidad);
    ASSERT_STR_EQ("123", lista_normal[0]);
    ASSERT_STR_EQ("4", lista_normal[1]);
    ASSERT_STR_EQ("", lista_normal[2]);
    ASSERT_STR_EQ("567890", lista_normal[3]);
    lista_cadenas_destruir(lista_normal, cantidad);

    SUBCASE("Caso sin caracter delimitador en la cadena");
    char **lista_sin_char = NULL;
    lista_sin_char = partir_por_delimitador(cadena, 14, '&', &cantidad);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ(cadena, lista_sin_char[0]);
    lista_cadenas_destruir(lista_sin_char, cantidad);

    SUBCASE("Caso con cadena vacia");
    char **lista_caso_vacia = NULL;
    lista_caso_vacia = partir_por_delimitador("", 1, ',', &cantidad);
    ASSERT_PTR_NOT_NULL(lista_caso_vacia);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ("", lista_caso_vacia[0]);
    lista_cadenas_destruir(lista_caso_vacia, cantidad); 

    SUBCASE("Parametros invalidos");
    char **invalido = NULL;
    invalido = partir_por_delimitador(NULL, 1, ',', &cantidad);
    ASSERT_PTR_NULL(invalido);
    invalido = partir_por_delimitador(cadena, 0, ',', &cantidad);
    ASSERT_PTR_NULL(invalido);
    invalido = partir_por_delimitador(cadena, 14, ',', NULL);
    ASSERT_PTR_NULL(invalido);

}
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_invertir_cadena_dinamico);
    RUN_TEST(prueba_partir_por_delimitador);
    return TEST_REPORT();
}
