#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>



 /**
  * @brief Divide una linea csv en multiples cadenas dinamicas
  * 
  * @param linea Cadena de texto constante a dividir
  * @param delimitador Caracter usado para separar los campos
  * @param cantidad_tokens Puntero donde se almacena la cantidad de recortes
  * 
  * @return char** Arreglo dinamico de punteros a cadenas o NULL si hay error
  */
 char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);

 /**
  * @brief Libera toda la memoria de los tokens y del arreglo principal de forma segura
  * 
  * @param puntero_arreglo Triple puntero para anularlo al final
  * @param cantidad Cantidad de elementos dentro del arreglo
  */
 void liberar_arreglo_cadena(char ***puntero_arreglo, size_t cantidad);

#endif 
