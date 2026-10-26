#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <stdbool.h>

#define TIPO_INVALIDO 0
#define TIPO_EQUILATERO 1
#define TIPO_ISOSCELES 2
#define TIPO_ESCALENO 3

/**
 * @brief Determina si tres longitudes pueden formar un triángulo válido.
 *
 * Aplica la desigualdad triangular estricta: cada lado debe ser menor
 * que la suma de los otros dos, y todos los lados deben ser mayores a cero.
 *
 * @param lado_a Longitud del primer lado.
 * @param lado_b Longitud del segundo lado.
 * @param lado_c Longitud del tercer lado.
 * @return bool true si forman un triángulo válido, false en caso contrario.
 */
bool es_triangulo_valido(float lado_a, float lado_b, float lado_c);

/**
 * @brief Clasifica un triángulo según las longitudes de sus lados.
 *
 * Determina si el triángulo es equilátero, isósceles o escaleno.
 * Si los lados no forman un triángulo válido, retorna TIPO_INVALIDO.
 *
 * @param lado_a Longitud del primer lado.
 * @param lado_b Longitud del segundo lado.
 * @param lado_c Longitud del tercer lado.
 * @return int Constante de tipo de triángulo o TIPO_INVALIDO si no es válido.
 */
int clasificar_triangulo(float lado_a, float lado_b, float lado_c);

/**
 * @brief Determina si un triángulo es rectángulo mediante Pitágoras.
 *
 * Evalúa si el cuadrado de alguno de los lados es igual a la suma de los
 * cuadrados de los otros dos, considerando una tolerancia para flotantes.
 * Si el triángulo no es válido, retorna false.
 *
 * @param lado_a Longitud del primer lado.
 * @param lado_b Longitud del segundo lado.
 * @param lado_c Longitud del tercer lado.
 * @return bool true si es rectángulo, false en caso contrario o inválido.
 */
bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c);

#endif 
