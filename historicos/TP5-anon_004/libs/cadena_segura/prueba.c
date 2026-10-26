/**
 * @file prueba.c
 * @brief Pruebas unitarias de libcadena_segura con el framework p1_test.
 *
 * Trabajo Practico 5 - Programacion 1 - UNRN
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadena_segura.h"

TEST(prueba_cadena_segura_creacion_destruccion)
{
    cadena_segura_t c;

    SUBCASE("Creacion desde literal");
    ASSERT_TRUE(cadena_segura_crear(&c, "Hola Mundo"));
    ASSERT_PTR_NOT_NULL(c.texto);
    ASSERT_INT_EQ(10, (int)c.longitud);
    ASSERT_STR_EQ("Hola Mundo", c.texto);
    cadena_segura_destruir(&c);
    ASSERT_PTR_NULL(c.texto);
    ASSERT_INT_EQ(0, (int)c.longitud);
    ASSERT_INT_EQ(0, (int)c.capacidad);

    SUBCASE("Creacion desde NULL (vacia)");
    ASSERT_TRUE(cadena_segura_crear(&c, NULL));
    ASSERT_PTR_NOT_NULL(c.texto);
    ASSERT_INT_EQ(0, (int)c.longitud);
    ASSERT_STR_EQ("", c.texto);
    cadena_segura_destruir(&c);

    SUBCASE("Puntero a estructura nulo");
    ASSERT_FALSE(cadena_segura_crear(NULL, "test"));
    cadena_segura_destruir(NULL);
}

TEST(prueba_cadena_segura_concatenar)
{
    cadena_segura_t c;
    ASSERT_TRUE(cadena_segura_crear(&c, "Hola"));

    ASSERT_TRUE(cadena_segura_concatenar(&c, " "));
    ASSERT_TRUE(cadena_segura_concatenar(&c, "Mundo"));
    ASSERT_INT_EQ(10, (int)c.longitud);
    ASSERT_STR_EQ("Hola Mundo", c.texto);

    
    ASSERT_TRUE(cadena_segura_concatenar(&c, NULL));
    ASSERT_STR_EQ("Hola Mundo", c.texto);

    
    ASSERT_TRUE(cadena_segura_concatenar(&c, ""));
    ASSERT_STR_EQ("Hola Mundo", c.texto);

    
    ASSERT_TRUE(cadena_segura_concatenar(&c, c.texto));
    ASSERT_INT_EQ(20, (int)c.longitud);
    ASSERT_STR_EQ("Hola MundoHola Mundo", c.texto);

    
    ASSERT_FALSE(cadena_segura_concatenar(NULL, "algo"));

    cadena_segura_destruir(&c);
}

TEST(prueba_cadena_segura_subcadena_y_clonar)
{
    cadena_segura_t original;
    cadena_segura_t sub;
    cadena_segura_t clon;

    ASSERT_TRUE(cadena_segura_crear(&original, "Programacion 1"));

    SUBCASE("Subcadena valida");
    ASSERT_TRUE(cadena_segura_subcadena(&original, 0, 8, &sub));
    ASSERT_INT_EQ(8, (int)sub.longitud);
    ASSERT_STR_EQ("Programa", sub.texto);
    cadena_segura_destruir(&sub);

    SUBCASE("Subcadena excedente copia hasta el final");
    ASSERT_TRUE(cadena_segura_subcadena(&original, 13, 10, &sub));
    ASSERT_INT_EQ(1, (int)sub.longitud);
    ASSERT_STR_EQ("1", sub.texto);
    cadena_segura_destruir(&sub);

    SUBCASE("Subcadena con inicio fuera de rango o longitud cero");
    ASSERT_TRUE(cadena_segura_subcadena(&original, 50, 5, &sub));
    ASSERT_INT_EQ(0, (int)sub.longitud);
    ASSERT_STR_EQ("", sub.texto);
    cadena_segura_destruir(&sub);

    ASSERT_TRUE(cadena_segura_subcadena(&original, 2, 0, &sub));
    ASSERT_INT_EQ(0, (int)sub.longitud);
    ASSERT_STR_EQ("", sub.texto);
    cadena_segura_destruir(&sub);

    SUBCASE("Subcadena sobre si misma (origen == destino)");
    cadena_segura_t mutante;
    ASSERT_TRUE(cadena_segura_crear(&mutante, "abcdef"));
    ASSERT_TRUE(cadena_segura_subcadena(&mutante, 2, 3, &mutante));
    ASSERT_INT_EQ(3, (int)mutante.longitud);
    ASSERT_STR_EQ("cde", mutante.texto);
    cadena_segura_destruir(&mutante);

    SUBCASE("Clonacion profunda independiente");
    ASSERT_TRUE(cadena_segura_clonar(&original, &clon));
    ASSERT_STR_EQ("Programacion 1", clon.texto);
    ASSERT_TRUE(clon.texto != original.texto);
    cadena_segura_destruir(&clon);

    SUBCASE("Clonacion sobre si misma (origen == destino)");
    ASSERT_TRUE(cadena_segura_clonar(&original, &original));
    ASSERT_STR_EQ("Programacion 1", original.texto);

    SUBCASE("Parametros nulos defensivos");
    ASSERT_FALSE(cadena_segura_subcadena(NULL, 0, 1, &sub));
    ASSERT_FALSE(cadena_segura_subcadena(&original, 0, 1, NULL));
    ASSERT_FALSE(cadena_segura_clonar(NULL, &clon));
    ASSERT_FALSE(cadena_segura_clonar(&original, NULL));

    cadena_segura_destruir(&original);
}

TEST(prueba_cadena_segura_buscar)
{
    cadena_segura_t c;
    ASSERT_TRUE(cadena_segura_crear(&c, "universidad nacional de rio negro"));

    ASSERT_INT_EQ(0, cadena_segura_buscar(&c, "universidad"));
    ASSERT_INT_EQ(12, cadena_segura_buscar(&c, "nacional"));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(&c, "comahue"));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(&c, ""));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(&c, NULL));
    ASSERT_INT_EQ(-1, cadena_segura_buscar(NULL, "nacional"));

    cadena_segura_destruir(&c);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libcadena_segura", conteo_args, argumentos);
    RUN_TEST(prueba_cadena_segura_creacion_destruccion);
    RUN_TEST(prueba_cadena_segura_concatenar);
    RUN_TEST(prueba_cadena_segura_subcadena_y_clonar);
    RUN_TEST(prueba_cadena_segura_buscar);
    return TEST_REPORT();
}
