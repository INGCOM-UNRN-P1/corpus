#ifndef FECHA_H
#define FECHA_H

#include <stdbool.h>

/**
 * @brief Determina si un año dado es bisiesto según el calendario gregoriano.
 *
 * Un año es bisiesto si es divisible por 4 y no por 100, o si es divisible
 * por 400.
 *
 * @param anio Año a evaluar.
 * @return bool true si el año es bisiesto, false en caso contrario.
 */
bool es_bisiesto(int anio);

/**
 * @brief Obtiene la cantidad de días que contiene un mes determinado en un año dado.
 *
 * Considera los meses de 30 y 31 días, y calcula 29 o 28 días para febrero
 * según si el año es bisiesto o no. Si el mes está fuera del rango [1, 12],
 * retorna 0.
 *
 * @param mes Mes a consultar (1 a 12).
 * @param anio Año correspondiente al mes.
 * @return int Cantidad de días del mes, o 0 si el mes es inválido.
 */
int dias_en_mes(int mes, int anio);

/**
 * @brief Valida si una combinación de día, mes y año representa una fecha válida.
 *
 * Una fecha es válida si el año es mayor a cero, el mes se encuentra entre 1 y 12,
 * y el día está en el rango [1, dias_en_mes(mes, anio)].
 *
 * @param dia Día a validar.
 * @param mes Mes a validar.
 * @param anio Año a validar.
 * @return bool true si la fecha es válida, false en caso contrario.
 */
bool es_fecha_valida(int dia, int mes, int anio);

#endif 
