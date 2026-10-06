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

    SUBCASE("Cadena vacia");
    char *vacia = cadena_duplicar_segura("", 5);
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);
 
    SUBCASE("La capacidad limita la inspeccion");
    char *parcial = cadena_duplicar_segura("programacion", 4);
    ASSERT_PTR_NOT_NULL(parcial);
    ASSERT_STR_EQ("prog", parcial);
    cadena_liberar_segura(&parcial);
 
    SUBCASE("Buffer sin terminador: no se lee fuera de limites");
    const char sin_nulo[3] = {'a', 'b', 'c'};
    char *recortada = cadena_duplicar_segura(sin_nulo, sizeof(sin_nulo));
    ASSERT_PTR_NOT_NULL(recortada);
    ASSERT_STR_EQ("abc", recortada);
    cadena_liberar_segura(&recortada);
 
    SUBCASE("La copia es independiente del origen");
    char origen[] = "hola";
    char *copia = cadena_duplicar_segura(origen, sizeof(origen));
    ASSERT_PTR_NOT_NULL(copia);
    origen[0] = 'X';
    ASSERT_STR_EQ("hola", copia);
    cadena_liberar_segura(&copia);
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
     ASSERT_PTR_NULL(cadena_unir_dinamica("test", 0, "test", 10));
    ASSERT_PTR_NULL(cadena_unir_dinamica("test", 10, "test", 0));
 
    SUBCASE("Cadenas vacias");
    char *con_vacia = cadena_unir_dinamica("", 5, "abc", 5);
    ASSERT_PTR_NOT_NULL(con_vacia);
    ASSERT_STR_EQ("abc", con_vacia);
    cadena_liberar_segura(&con_vacia);
 
    char *ambas_vacias = cadena_unir_dinamica("", 5, "", 5);
    ASSERT_PTR_NOT_NULL(ambas_vacias);
    ASSERT_STR_EQ("", ambas_vacias);
    cadena_liberar_segura(&ambas_vacias);
 
    SUBCASE("Las capacidades limitan la inspeccion de cada cadena");
    char *limitada = cadena_unir_dinamica("Hola", 2, "Mundo", 3);
    ASSERT_PTR_NOT_NULL(limitada);
    ASSERT_STR_EQ("HoMun", limitada);
    cadena_liberar_segura(&limitada);
}

TEST(prueba_cadena_liberar_segura)
{
    SUBCASE("Liberar con punteros nulos no hace nada");
    char *nula = NULL;
    cadena_liberar_segura(&nula);
    ASSERT_PTR_NULL(nula);
    cadena_liberar_segura(NULL);
}
 
TEST(prueba_cadena_subcadena_dinamica)
{
    SUBCASE("Extraccion al inicio, en el medio y hasta el final");
    char *inicio = cadena_subcadena_dinamica("Programacion", 20, 0, 4);
    ASSERT_PTR_NOT_NULL(inicio);
    ASSERT_STR_EQ("Prog", inicio);
    cadena_liberar_segura(&inicio);
    ASSERT_PTR_NULL(inicio);
 
    char *medio = cadena_subcadena_dinamica("Programacion", 20, 3, 3);
    ASSERT_PTR_NOT_NULL(medio);
    ASSERT_STR_EQ("gra", medio);
    cadena_liberar_segura(&medio);
 
    char *final = cadena_subcadena_dinamica("hola", 10, 2, 100);
    ASSERT_PTR_NOT_NULL(final);
    ASSERT_STR_EQ("la", final);
    cadena_liberar_segura(&final);
 
    SUBCASE("Inicio mayor o igual a la longitud retorna cadena vacia en heap");
    char *pasado = cadena_subcadena_dinamica("hola", 10, 10, 3);
    ASSERT_PTR_NOT_NULL(pasado);
    ASSERT_STR_EQ("", pasado);
    cadena_liberar_segura(&pasado);
 
    char *justo = cadena_subcadena_dinamica("hola", 10, 4, 3);
    ASSERT_PTR_NOT_NULL(justo);
    ASSERT_STR_EQ("", justo);
    cadena_liberar_segura(&justo);
 
    SUBCASE("Cantidad cero retorna cadena vacia en heap");
    char *nada = cadena_subcadena_dinamica("hola", 10, 1, 0);
    ASSERT_PTR_NOT_NULL(nada);
    ASSERT_STR_EQ("", nada);
    cadena_liberar_segura(&nada);
 
    SUBCASE("La capacidad limita la longitud medida del origen");
    char *acotada = cadena_subcadena_dinamica("Programacion", 4, 2, 10);
    ASSERT_PTR_NOT_NULL(acotada);
    ASSERT_STR_EQ("og", acotada);
    cadena_liberar_segura(&acotada);
 
    SUBCASE("Origen nulo retorna NULL");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 10, 0, 3));
}
 
TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("Inversion de cadenas comunes");
    char *invertida = cadena_invertir_dinamica("hola", 10);
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("aloh", invertida);
    cadena_liberar_segura(&invertida);
    ASSERT_PTR_NULL(invertida);
 
    char *un_caracter = cadena_invertir_dinamica("a", 10);
    ASSERT_PTR_NOT_NULL(un_caracter);
    ASSERT_STR_EQ("a", un_caracter);
    cadena_liberar_segura(&un_caracter);
 
    char *palindromo = cadena_invertir_dinamica("neuquen", 10);
    ASSERT_PTR_NOT_NULL(palindromo);
    ASSERT_STR_EQ("neuquen", palindromo);
    cadena_liberar_segura(&palindromo);
 
    SUBCASE("Cadena vacia retorna cadena vacia en heap");
    char *vacia = cadena_invertir_dinamica("", 10);
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);
 
    SUBCASE("No modifica la cadena origen");
    char origen[] = "hola";
    char *copia_invertida = cadena_invertir_dinamica(origen, sizeof(origen));
    ASSERT_PTR_NOT_NULL(copia_invertida);
    ASSERT_STR_EQ("hola", origen);
    ASSERT_STR_EQ("aloh", copia_invertida);
    cadena_liberar_segura(&copia_invertida);
 
    SUBCASE("La capacidad limita la longitud medida del origen");
    char *acotada = cadena_invertir_dinamica("programacion", 4);
    ASSERT_PTR_NOT_NULL(acotada);
    ASSERT_STR_EQ("gorp", acotada);
    cadena_liberar_segura(&acotada);
 
    SUBCASE("Origen nulo retorna NULL");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 10));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libstring", conteo_args, argumentos);
    RUN_TEST(prueba_cadena_duplicar_segura);
    RUN_TEST(prueba_cadena_unir_dinamica);
    RUN_TEST(prueba_cadena_liberar_segura);
    RUN_TEST(prueba_cadena_subcadena_dinamica);
    RUN_TEST(prueba_cadena_invertir_dinamica);
    return TEST_REPORT();
}