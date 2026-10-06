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
#include "recorrido.h"


bool copiar_arreglo(const int *origen, size_t cantidad, int *destino);
bool invertir_arreglo(int *arreglo, size_t cantidad);

TEST(prueba_copiar_arreglo)
{
    SUBCASE("Copia de arreglo valido");
    int origen[] = {1, 2, 3, 4, 5};
    int destino[5] = {0};
    ASSERT_TRUE(copiar_arreglo(origen, 5, destino));
    ASSERT_INT_EQ(1, destino[0]);
    ASSERT_INT_EQ(2, destino[1]);
    ASSERT_INT_EQ(3, destino[2]);
    ASSERT_INT_EQ(4, destino[3]);
    ASSERT_INT_EQ(5, destino[4]);

    SUBCASE("Origen no se modifica");
    ASSERT_INT_EQ(1, origen[0]);
    ASSERT_INT_EQ(5, origen[4]);

    SUBCASE("Copia parcial, destino mas grande");
    int origen2[] = {10, 20, 30};
    int destino2[5] = {-1, -1, -1, -1, -1};
    ASSERT_TRUE(copiar_arreglo(origen2, 3, destino2));
    ASSERT_INT_EQ(10, destino2[0]);
    ASSERT_INT_EQ(20, destino2[1]);
    ASSERT_INT_EQ(30, destino2[2]);
    ASSERT_INT_EQ(-1, destino2[3]);
    ASSERT_INT_EQ(-1, destino2[4]);

    SUBCASE("Cantidad cero");
    int destino3[3] = {7, 8, 9};
    ASSERT_TRUE(copiar_arreglo(origen2, 0, destino3));
    ASSERT_INT_EQ(7, destino3[0]);
    ASSERT_INT_EQ(8, destino3[1]);
    ASSERT_INT_EQ(9, destino3[2]);

    SUBCASE("Punteros nulos");
    int datos[] = {1, 2, 3};
    int salida[3];
    ASSERT_FALSE(copiar_arreglo(NULL, 3, salida));
    ASSERT_FALSE(copiar_arreglo(datos, 3, NULL));
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Cantidad par");
    int datos_par[] = {1, 2, 3, 4};
    ASSERT_TRUE(invertir_arreglo(datos_par, 4));
    ASSERT_INT_EQ(4, datos_par[0]);
    ASSERT_INT_EQ(3, datos_par[1]);
    ASSERT_INT_EQ(2, datos_par[2]);
    ASSERT_INT_EQ(1, datos_par[3]);

    SUBCASE("Cantidad impar");
    int datos_impar[] = {1, 2, 3, 4, 5};
    ASSERT_TRUE(invertir_arreglo(datos_impar, 5));
    ASSERT_INT_EQ(5, datos_impar[0]);
    ASSERT_INT_EQ(4, datos_impar[1]);
    ASSERT_INT_EQ(3, datos_impar[2]);
    ASSERT_INT_EQ(2, datos_impar[3]);
    ASSERT_INT_EQ(1, datos_impar[4]);

    SUBCASE("Un solo elemento");
    int un_elemento[] = {42};
    ASSERT_TRUE(invertir_arreglo(un_elemento, 1));
    ASSERT_INT_EQ(42, un_elemento[0]);

    SUBCASE("Cantidad cero");
    int vacio[] = {1, 2, 3};
    ASSERT_TRUE(invertir_arreglo(vacio, 0));
    ASSERT_INT_EQ(1, vacio[0]);
    ASSERT_INT_EQ(2, vacio[1]);
    ASSERT_INT_EQ(3, vacio[2]);

    SUBCASE("Puntero nulo");
    ASSERT_FALSE(invertir_arreglo(NULL, 3));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3 (Copia e Inversion)", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
