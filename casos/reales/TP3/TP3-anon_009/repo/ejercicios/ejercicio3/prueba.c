

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo)
{
    SUBCASE("copias de arreglos valido");
    {
        int origen[] = {15, -3, 42, 8};
        int destino[4] = {0};
        size_t cantidad = 4;
        copiar_arreglo(origen, cantidad, destino);
        ASSERT_INT_EQ(15, *(destino + 0));
        ASSERT_INT_EQ(-3, *(destino + 1));
        ASSERT_INT_EQ(42, *(destino + 2));
        ASSERT_INT_EQ(8, *(destino + 3));   
        ASSERT_TRUE(true);
    }
    SUBCASE("Copias invalidas o nulas");
    {
        int origen[3] = {10, 20, 30};
        int copia[3] = {0, 0, 0};
        copiar_arreglo(NULL, 3, copia);
        ASSERT_INT_EQ(0, *copia);
        copiar_arreglo(origen, 3, NULL);
        ASSERT_INT_EQ(10, *origen);
        copiar_arreglo(origen, 0, copia);
    }
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Casos bordes - Puntero NULL y cantidad <= 1");
    {
        invertir_arreglo(NULL, 5);
        int un_elemento[] = {99};
        invertir_arreglo(un_elemento, 1);
        ASSERT_INT_EQ(99, *un_elemento);
        int vacio[] = {0};
        invertir_arreglo(vacio, 0);
    }
    SUBCASE("Inversion exitosa in-place - Longitud impar");
    {
        int datos_impar[] = {1, 2, 3, 4, 5};
        invertir_arreglo(datos_impar, 5);
        ASSERT_INT_EQ(5, *(datos_impar + 0));
        ASSERT_INT_EQ(4, *(datos_impar + 1));
        ASSERT_INT_EQ(3, *(datos_impar + 2));
        ASSERT_INT_EQ(2, *(datos_impar + 3));
        ASSERT_INT_EQ(1, *(datos_impar + 4));
    }
    SUBCASE("Inversion exitosa in-place - Longitud par");
    {
        int datos_par[] = {10, 20, 30, 40};
        invertir_arreglo(datos_par, 4);
        ASSERT_INT_EQ(40, *(datos_par + 0));
        ASSERT_INT_EQ(30, *(datos_par + 1));
        ASSERT_INT_EQ(20, *(datos_par + 2));
        ASSERT_INT_EQ(10, *(datos_par + 3));
    }
}
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
    
