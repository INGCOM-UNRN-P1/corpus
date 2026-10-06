/**
 * @file string.h
 * @brief Biblioteca libstring: manipulación y gestión de cadenas seguras en heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica en heap debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - Sin uso de structs: operaciones sobre char* y dobles punteros char**.
 * 
 * 
 * @brief cadena_duplicar_segura
 *         Duplica una cadena de char de forma segura.
 *         calcula longitud, luego la chequea con capacidad max, 
 *          y reserva el lugar necesario en memoria/
 *           [!] La memoria debe ser libreada con free posterior al uso. [!]
 * 
 * @param origen puntero desde donde se copiara
 * @param capacidad_max del puntero
 * @return punetro a la copia de la cadena.
 *          NULL SI el origen es NULL; si no pudo alojar memoria.
 * 
 *   ---------------------------------------------------------------------
 * @brief cadena_unir_dinamica 
 *        Funcion que toma dos punteros, primera y segunda, analiza su largo,
 *          reserva el espacio en memoria necesario con malloc, y concatena
 *          en un puntero destino.
 * @param primera primer puntero a concatenar..
 * @param segunda segundo puntero a concatenar.
 * @param cap_primera capacidad en bits del primer puntero/
 * @param cap_segunda capacidad en bits del segundo.
 * 
 * @return NULL si: Primera es NULL
 *                  Segunda es NULL
 *                  cap_primera es 0
 *                  cap_segunda es 0
 *                  fallo el malloc.
 * @return *destino puntero concatenado
 * [!]Se debe usar free luego de su uso.[!]
 *
 * 
 *--------------------------------------------------------------------  
 * @brief cadena_liberar_segura
 *        Recibe un puntero y libera su memoria.
 * 
 * @param Puntero_cadena no debe ser nulll ni debe ya estar seteado en null.
 * 
 * @return Si puntero es Null o puntero_cadena es NULL no realiza acciones.
 * 
 * 
 * -------------------------------------------------------------------- 
 *  @brief extrae subcadena de una cadena origen.
 *         copiando un nro determinado de har desde i y 
 *         se aloja mediante malloc
 * @param origen puntero origen
 * @param capacidad_max delm puntero
 * @param inicio de la extraccion
 * @param cantidad de caracteres a extraer
 * 
 * @return null si malloc falla, origen es null, o capacidad es 0
 *          Nueva cadena alojada en puntero. 
 * -------------------------------------------------------------------- 
 * @brief cadena_invertir_dinamica
 *        genera una copia invertida de una cadena en memoria dinamica
 *          no modifica cadena original
 * 
 * @param origen puntero a la cadena de caracteres que se invierte
 * @param capacidad_max  caracteres que se analiza
 * @retunr puntero a nueva cadena invertida
 * @return Null si el origen es null, la cap max es 0 o aloco mal el malloc
 * 
 * 
 * 
 * 
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>


char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);


char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);


void cadena_liberar_segura(char **puntero_cadena);


char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad);

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);
#endif 
