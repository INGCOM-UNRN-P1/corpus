#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>


/** 
* @brief Calcula el promedio aritmético de los elementos de un arreglo de enteros. 
* 
* Reutiliza la función 'arreglo_sumar' de lib/arreglos para obtener la suma total 
* y realiza la división por la cantidad de elementos. 
* 
* @param arreglo Arreglo de enteros a promediar (lectura exclusivamente). 
* @param cantidad Cantidad de elementos válidos presentes en el arreglo. 
* 
* @pre Si cantidad > 0, el puntero 'arreglo' debe apuntar a un bloque de memoria válido. 
* @post El contenido del arreglo permanece inalterado. 
* 
* @return El promedio aritmético como double, o 0.0 si 'arreglo' es NULL o si 'cantidad' es 0. */ 
double calcular_promedio(const int arreglo[], size_t cantidad);


/** 
* @brief Copia la cadena 'primero' en 'destino' y luego concatena 'separador' y 'segundo' 
* respetando la capacidad total del búfer. La cadena resultante debe
* quedar finalizada en '\0' si todas las operaciones se realizan sin truncamiento. 
* 
* @param destino Búfer donde se almacenará la combinación resultante (salida). 
* @param capacidad Tamaño total en bytes del búfer destino. 
* @param primero Primera cadena a colocar (lectura exclusivamente). 
* @param segundo Segunda cadena a anexar al final (lectura exclusivamente). 
* @param separador Cadena intercalada entre 'primero' y 'segundo' (lectura exclusivamente). *
* @pre Si capacidad > 0 y destino != NULL, 'destino' debe apuntar a un bloque de memoria válido. 
* @pre Los punteros 'primero', 'segundo' y 'separador' deben apuntar a cadenas válidas terminadas en '\0'. 
* @post 'destino' contendrá la secuencia primero + separador + segundo terminada en '\0' si retorna true. 
*
* @return true si la combinación completa de cadenas se realizó sin ningún truncamiento, 
* false si ocurrió truncamiento en alguna etapa, si algún puntero es NULL o si 'capacidad' es 0. 
*/ 
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
