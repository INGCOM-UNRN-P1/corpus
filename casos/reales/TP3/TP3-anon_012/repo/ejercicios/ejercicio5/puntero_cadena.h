#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>



/** 
* @brief Copia la cadena origen en destino utilizando exclusivamente aritmética de punteros. 
* Garantiza siempre que la cadena resultante en 'destino' quede terminada en '\0'. 
* 
* @param destino Búfer de memoria donde se almacenará la copia (salida). 
* @param capacidad Tamaño total en bytes del búfer 'destino'. 
* @param origen Cadena fuente a copiar (lectura exclusivamente).
* 
* @pre Si 'capacidad' > 0 y 'destino' != NULL, 'destino' debe apuntar a un búfer válido. 
* @pre 'origen' debe ser una cadena válida terminada en '\0'. 
* @post 'destino' contendrá la copia terminada en '\0'. 
* 
* @return true si la cadena se copió completa sin ningún truncamiento, 
* false si ocurrió truncamiento, si 'destino' u 'origen' son NULL o si 'capacidad' es 0.
*/
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/** 
* @brief Anexa la cadena origen al final de destino utilizando aritmética de punteros. 
* Avanza un puntero auxiliar hasta el terminador '\0' de 'destino' y a continuación
* concatena los caracteres de 'origen' respetando la capacidad restante del búfer. 
* Garantiza terminación '\0' dentro del espacio seguro. 
* 
* @param destino Búfer con la cadena base a la cual se le anexará 'origen' (lectura y escritura). 
* @param capacidad Tamaño total en bytes del búfer 'destino'. 
* @param origen Cadena a concatenar al final (lectura exclusivamente). 
* 
* @pre 'destino' debe contener una cadena válida terminada en '\0' dentro de 'capacidad'. 
* @post 'destino' contendrá la concatenación terminada en '\0'. 
* 
* @return true si la concatenación se realizó completa sin truncamiento, * false si hubo truncamiento, si algún puntero es NULL o si 'capacidad' es 0.
*/ 
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
