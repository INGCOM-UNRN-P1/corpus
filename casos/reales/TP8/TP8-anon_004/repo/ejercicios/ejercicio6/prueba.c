#include <stdbool.h>
#include <stdio.h>
#include "p1_test.h"
#include "bitmap.h"
#include "sierpin.h"



TEST(prueba_llenar_bloque_fondo_intacto)
{
    
    bmp_t *img = bmp_crear(9, 9);
    ASSERT_TRUE(img != NULL);

    
    

    color_t color;
    ASSERT_TRUE(bmp_get_pixel(img, (coordenada_t){0, 0}, &color));
    ASSERT_TRUE(bmp_colores_iguales(color, BMP_COLOR_NEGRO));

    bmp_destruir(img);
}

TEST(prueba_llenar_bloque_pinta_centro)
{
    SUBCASE("El píxel central debe tener el color asignado");
    
    
    
    
    
    
    ASSERT_TRUE(true);  
}



TEST(prueba_sierpinski_nivel_0)
{
    SUBCASE("Nivel 0: imagen 1×1, píxel negro");
    
    
    
    
    
    
    
    
    ASSERT_TRUE(true);
}

TEST(prueba_sierpinski_nivel_1_centro_blanco)
{
    SUBCASE("Nivel 1: imagen 3×3, píxel (1,1) debe ser blanco");
    
    
    
    
    
    
    ASSERT_TRUE(true);
}

TEST(prueba_sierpinski_nivel_negativo_null)
{
    SUBCASE("Nivel negativo debe retornar NULL");
    
    ASSERT_TRUE(true);
}



TEST(prueba_exportar_crea_archivo)
{
    SUBCASE("Exportar nivel 2 genera archivo no vacío");
    
    
    
    
    
    ASSERT_TRUE(true);
}



int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6 — Sierpinski", conteo_args, argumentos);
    RUN_TEST(prueba_llenar_bloque_fondo_intacto);
    RUN_TEST(prueba_llenar_bloque_pinta_centro);
    RUN_TEST(prueba_sierpinski_nivel_0);
    RUN_TEST(prueba_sierpinski_nivel_1_centro_blanco);
    RUN_TEST(prueba_sierpinski_nivel_negativo_null);
    RUN_TEST(prueba_exportar_crea_archivo);
    return TEST_REPORT();
}
