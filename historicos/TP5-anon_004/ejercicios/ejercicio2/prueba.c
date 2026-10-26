#include <stdio.h>
#include "p1_test.h"
#include "cadena_segura.h"
#include "slug_generator.h"

TEST(prueba_slug_generator)
{
    cadena_segura_t titulo;
    cadena_segura_t slug;

    SUBCASE("Generacion basica de slug");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "Introduccion a Programacion 1!"));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_STR_EQ("introduccion-a-programacion-1", slug.texto);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);

    SUBCASE("Manejo de multiples espacios y simbolos");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "   Memoria    Dinamica   ---   C11   "));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_STR_EQ("memoria-dinamica-c11", slug.texto);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);

    SUBCASE("Deteccion de palabras prohibidas");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "Articulo con contenido spam aqui"));
    ASSERT_TRUE(contiene_palabra_prohibida(&titulo, "spam"));
    ASSERT_FALSE(contiene_palabra_prohibida(&titulo, "educacion"));
    cadena_segura_destruir(&titulo);

    SUBCASE("Acotado de longitud de slug");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "Un titulo excesivamente extenso para URL"));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_TRUE(acotar_longitud_slug(&slug, 9));
    ASSERT_STR_EQ("un-titulo", slug.texto);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);

    SUBCASE("Casos de borde y valores nulos");
    ASSERT_FALSE(generar_slug(NULL, &slug));
    ASSERT_TRUE(cadena_segura_crear(&titulo, "Valido"));
    ASSERT_FALSE(generar_slug(&titulo, NULL));
    ASSERT_FALSE(contiene_palabra_prohibida(NULL, "palabra"));
    ASSERT_FALSE(contiene_palabra_prohibida(&titulo, NULL));
    ASSERT_FALSE(acotar_longitud_slug(NULL, 5));
    cadena_segura_destruir(&titulo);

    SUBCASE("Texto unicamente con caracteres especiales");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "!@#$%^&*()_+=-{}[]:;<>?,./"));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_STR_EQ("", slug.texto);
    ASSERT_UINT_EQ((size_t)0, slug.longitud);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);

    SUBCASE("Acotado sin necesidad de recorte");
    ASSERT_TRUE(cadena_segura_crear(&titulo, "hola mundo"));
    ASSERT_TRUE(generar_slug(&titulo, &slug));
    ASSERT_TRUE(acotar_longitud_slug(&slug, 50));
    ASSERT_STR_EQ("hola-mundo", slug.texto);
    cadena_segura_destruir(&titulo);
    cadena_segura_destruir(&slug);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 2 (Slug Generator)", conteo_args, argumentos);
    RUN_TEST(prueba_slug_generator);
    return TEST_REPORT();
}
