/**
 * @file cadenas.h
 * @brief Biblioteca de manipulacion de cadenas seguras en C11.
 *
 * Trabajo Practico 2 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef CADENAS_H
#define CADENAS_H

#include <stdbool.h>
#include <stddef.h>




/**
 * @brief Calcula la longitud de una cadena de forma segura.
 *
 * @param cadena Cadena que se desea medir.
 * @param capacidad Cantidad maxima de bytes que se pueden inspeccionar.
 *
 * @pre Si cadena no es NULL, debe apuntar a memoria valida.
 * @post La cadena no es modificada.
 *
 * @return Cantidad de caracteres antes de '\0'.
 * @return capacidad si no encuentra '\0' dentro del limite.
 * @return 0 si cadena es NULL o capacidad es 0.
 */
size_t cadena_longitud(
    const char cadena[],
    size_t capacidad
);




/**
 * @brief Copia una cadena dentro de un buffer de capacidad limitada.
 *
 * @param destino Buffer donde se copia el texto.
 * @param capacidad Capacidad total del buffer destino.
 * @param origen Cadena que se desea copiar.
 *
 * @pre destino debe tener espacio para capacidad bytes.
 * @post Si capacidad es mayor que 0, destino termina en '\0'.
 *
 * @return true si la cadena fue copiada completamente.
 * @return false si hubo truncamiento o parametros invalidos.
 */
bool cadena_copiar(
    char destino[],
    size_t capacidad,
    const char origen[]
);




/**
 * @brief Agrega una cadena al final de otra de forma segura.
 *
 * @param destino Cadena donde se agrega el contenido.
 * @param capacidad Capacidad total del buffer destino.
 * @param origen Cadena que se desea agregar.
 *
 * @pre destino debe tener espacio para capacidad bytes.
 * @post Si capacidad es mayor que 0, destino termina en '\0'.
 *
 * @return true si todo el origen pudo ser agregado.
 * @return false si hubo truncamiento o parametros invalidos.
 */
bool cadena_concatenar(
    char destino[],
    size_t capacidad,
    const char origen[]
);




/**
 * @brief Convierte las letras minusculas de una cadena a mayusculas.
 *
 * @param cadena Cadena que se desea modificar.
 * @param capacidad Cantidad maxima de bytes que se pueden recorrer.
 *
 * @pre Si cadena no es NULL, debe apuntar a memoria valida.
 * @post Las letras minusculas encontradas quedan en mayusculas.
 *
 * @return Cantidad de caracteres convertidos.
 * @return 0 si cadena es NULL o capacidad es 0.
 */
size_t cadena_a_mayusculas(
    char cadena[],
    size_t capacidad
);




/**
 * @brief Copia una parte de una cadena en un buffer seguro.
 *
 * Comienza desde la posicion inicio y copia como maximo
 * la cantidad de caracteres indicada.
 *
 * @param destino Buffer donde se guarda la subcadena.
 * @param capacidad Capacidad total del buffer destino.
 * @param origen Cadena de origen.
 * @param inicio Posicion desde donde comienza la copia.
 * @param cantidad Cantidad maxima de caracteres a copiar.
 *
 * @pre destino debe tener espacio para capacidad bytes.
 * @post Si capacidad es mayor que 0, destino termina en '\0'.
 *
 * @return true si la operacion se realizo sin truncamiento.
 * @return false si hubo truncamiento o parametros invalidos.
 */
bool cadena_subcadena(
    char destino[],
    size_t capacidad,
    const char origen[],
    size_t inicio,
    size_t cantidad
);

#endif 
