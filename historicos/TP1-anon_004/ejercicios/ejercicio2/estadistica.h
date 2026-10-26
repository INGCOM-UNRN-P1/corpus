#ifndef ESTADISTICA_H
#define ESTADISTICA_H

/**
 * @brief Calcula el promedio a partir de una suma acumulada y la cantidad
 *        de elementos.
 *
 * @param suma Suma total acumulada de los valores.
 * @param cantidad Cantidad de elementos sumados (debe ser mayor a cero).
 * @return float El promedio obtenido, o 0.0f si la cantidad es menor o igual
 *         a cero.
 */
float calcular_promedio(float suma, int cantidad);

/**
 * @brief Actualiza el valor mínimo comparándolo con un nuevo valor.
 *
 * @param actual_min Valor mínimo registrado hasta el momento.
 * @param nuevo_valor Nuevo valor a evaluar.
 * @return float El menor entre actual_min y nuevo_valor.
 */
float actualizar_minimo(float actual_min, float nuevo_valor);

/**
 * @brief Actualiza el valor máximo comparándolo con un nuevo valor.
 *
 * @param actual_max Valor máximo registrado hasta el momento.
 * @param nuevo_valor Nuevo valor a evaluar.
 * @return float El mayor entre actual_max y nuevo_valor.
 */
float actualizar_maximo(float actual_max, float nuevo_valor);

#endif 
