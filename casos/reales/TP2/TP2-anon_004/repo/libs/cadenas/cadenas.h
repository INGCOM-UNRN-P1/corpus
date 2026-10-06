/**
 * @file cadenas.h
 * @brief Biblioteca de manipulación de cadenas seguras (Safe Strings) en C11.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - RECIBE LA CAPACIDAD: Parámetro 'size_t capacidad' con el tamaño total
 *   del búfer destino en memoria física (incluyendo terminador).
 * - GARANTÍA DE TERMINADOR: Si capacidad > 0, el búfer destino siempre
 *   finaliza con el carácter nulo '\0'.
 * - CONTROL DE LÍMITES: Nunca se escribe fuera de [0, capacidad - 1].
 */

#ifndef CADENAS_H
#define CADENAS_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Cuenta cuántos caracteres tiene un texto antes del '\0', sin pasarse del límite. Recorre la memoria buscando el terminador nulo ('\0') hasta un tope fijado por 'capacidad'. Si el texto no tiene '\0' dentro de ese rango, devuelve 'capacidad' para evitar leer memoria que no le pertenece al programa.
 *
 * @pre 'cadena' debe ser un texto legible de al menos 'capacidad' bytes (o NULL si capacidad es 0).
 * @post Devuelve la cantidad de caracteres reales antes del '\0'. Si la cadena es NULL o la capacidad es 0, devuelve 0.
 *
 * @param cadena Texto que se quiere medir (solo lectura).
 * @param capacidad Límite máximo de bytes que la función tiene permitido inspeccionar.
 *
 * @return size_t Cantidad de caracteres encontrados, o 'capacidad' si no encontró el '\0'.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);



/**
 * @brief Copia una cadena de texto en un búfer destino evitando desbordes de memoria. Copia los caracteres desde 'origen' hacia 'destino' hasta toparse con '\0' o hasta alcanzar 'capacidad - 1'. Si 'capacidad > 0', garantiza siempre colocar el '\0' al final. Si no hubo espacio suficiente para copiar todo el origen, trunca el texto y avisa la pérdida devolviendo false.
 *
 * @pre 'destino' debe apuntar a un espacio de memoria con lugar para al menos 'capacidad' bytes.
 * @pre 'origen' debe ser una cadena válida terminada en '\0'.
 * @post Si 'origen' entra completo, lo copia íntegro y devuelve true. Si no entra, copia hasta 'capacidad - 1', pone '\0' al final y devuelve false. Si 'destino' o 'origen' son NULL, o si 'capacidad' es 0, devuelve false sin modificar nada.
 *
 * @param destino Búfer donde se escribirá la copia resultante.
 * @param capacidad Tamaño físico total del búfer destino en bytes.
 * @param origen Texto original que se desea copiar (solo lectura).
 *
 * @return bool true si se copió todo sin truncar; false si se truncó o hubo error.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);



 /**
 * @brief Concatena el texto de una cadena origen al final del texto en destino. Busca el final del texto actual en 'destino' y a partir de allí anexa los caracteres de 'origen'. Garantiza que el resultado final termine en '\0' siempre que 'capacidad > 0' y no sobrepase el límite del búfer. Si el espacio no alcanza para copiar todo el origen, trunca el resultado y devuelve false.
 *
 * @pre 'destino' apunta a un búfer con espacio para al menos 'capacidad' bytes, y 'origen' es una cadena válida terminada en '\0'.
 * @post Si 'origen' entra completo, se anexa y retorna true. Si no entra completo, copia lo que quepa, coloca '\0' al final y retorna false. Si los punteros son NULL, capacidad es 0, o destino carece de '\0', devuelve false.
 *
 * @param destino   Búfer que ya contiene texto inicial y recibirá la concatenación.
 * @param capacidad Capacidad física total del búfer destino en bytes.
 * @param origen    Cadena de texto que se va a anexar al final (solo lectura).
 *
 * @return bool true si se concatenó sin pérdidas; false si se truncó o hubo error.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);



/**
 * @brief Convierte in-place a mayusculas los caracteres minusculas ASCII ('a'-'z') presentes en la cadena sin superar la capacidad.
 *
 * @pre 'cadena' apunta a un bloque de memoria valido de al menos 'capacidad' bytes con terminador nulo o es NULL si capacidad es 0.
 * @post Modifica los caracteres minusculas a mayusculas deteniendose en el primer '\0' o al alcanzar capacidad y retorna la cantidad convertida.
 *
 * @param cadena Cadena de caracteres que sera modificada directamente en memoria.
 * @param capacidad Limite maximo de bytes que la funcion puede inspeccionar y modificar.
 *
 * @return size_t Cantidad total de caracteres convertidos a mayuscula o 0 ante cadena nula o capacidad igual a 0.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);



/**
 * @brief Extrae una porcion de la cadena origen a partir de una posicion inicial y la copia en destino.
 *
 * @pre 'destino' apunta a un bufer con espacio para al menos 'capacidad' bytes, y 'origen' es una cadena terminada en '\0'.
 * @post Copia a lo sumo 'cantidad' caracteres a partir de 'inicio' garantizando terminador nulo si capacidad > 0; si inicio supera la longitud de origen, destino queda vacia.
 *
 * @param destino Bufer de memoria seguro donde se almacenara la subcadena extraida.
 * @param capacidad Capacidad fisica total del bufer destino en bytes incluyendo el byte nulo.
 * @param origen Cadena de caracteres original desde donde se extraera la porcion (solo lectura).
 * @param inicio Indice base de origen a partir del cual comenzara la extraccion de caracteres.
 * @param cantidad Cantidad maxima de caracteres a extraer sin contabilizar el terminador nulo.
 *
 * @return bool true si la extraccion fue exitosa sin truncamiento por capacidad, false en caso contrario.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);



/**
 * @brief Convierte un numero entero con signo a su representacion textual en base 10 dentro de un bufer seguro.
 *
 * @pre 'destino' apunta a un bufer de al menos 'capacidad' bytes, y 'valor' es un entero representable.
 * @post Escribe la cadena decimal garantizando terminador nulo si capacidad > 0; retorna false ante capacidad insuficiente o puntero nulo.
 *
 * @param destino Bufer de memoria seguro donde se escribira la representacion en texto.
 * @param capacidad Capacidad fisica total del bufer destino en bytes incluyendo el byte nulo.
 * @param valor Numero entero con signo a convertir a texto en base decimal.
 *
 * @return bool true si la conversion fue completa sin truncar, false si no hubo espacio o puntero nulo.
 */
bool cadena_de_entero(char destino[], size_t capacidad, int valor);

#endif 
