#ifndef CAJERO_H
#define CAJERO_H

#include <stdbool.h>

#define BILLETE_20000 20000
#define BILLETE_10000 10000
#define BILLETE_5000 5000
#define BILLETE_2000 2000
#define BILLETE_1000 1000
#define BILLETE_500 500
#define BILLETE_200 200
#define BILLETE_100 100
#define DENOMINACION_MINIMA BILLETE_100

/**
 * @brief Determina si un monto solicitado es admisible para su retiro.
 *
 * Un monto es válido si es estrictamente positivo y múltiplo de la
 * denominación mínima de billete disponible en el cajero ($100).
 *
 * @param monto Monto solicitado a retirar.
 * @return bool true si el monto es mayor a cero y múltiplo de 100,
 *         false en caso contrario.
 */
bool es_monto_valido(int monto);

/**
 * @brief Calcula la cantidad de billetes de una denominación dada.
 *
 * Realiza la división entera entre el monto disponible y la denominación
 * del billete correspondiente.
 *
 * @param monto Monto remanente a descomponer.
 * @param denominacion Valor nominal del billete a evaluar.
 * @return int Cantidad entera de billetes de esa denominación.
 */
int calcular_cantidad_billetes(int monto, int denominacion);

/**
 * @brief Calcula el remanente de monto tras descontar billetes.
 *
 * Obtiene el residuo de la división entera entre el monto y la denominación
 * indicada.
 *
 * @param monto Monto actual antes de descontar los billetes.
 * @param denominacion Valor nominal del billete evaluado.
 * @return int Monto remanente tras descontar los billetes posibles.
 */
int calcular_resto_monto(int monto, int denominacion);

#endif 
