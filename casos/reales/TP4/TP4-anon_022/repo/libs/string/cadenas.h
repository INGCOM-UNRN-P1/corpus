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
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>

// == TP2 ==

/**
 * @brief Cuenta la cantidad de caracteres de una cadena antes del terminador 
 *        nulo '\0', inspeccionando como máximo la capacidad indicada.
 *
 * @param cadena cuyos caracteres se desean contar.
 * @param capacidad Cantidad máxima de bytes que se pueden inspeccionar.
 *
 * @return Cantidad de caracteres de la cadena antes del terminador nulo.
 *         Retorna 'capacidad' si no se encuentra '\0' dentro del rango.
 *         Retorna 0 si la cadena es nula o la capacidad es 0.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);

/**
 * @brief Copia una cadena de origen en un búfer destino de capacidad limitada.
 *
 * @param destino Búfer donde se copiará la cadena de origen.
 * @param capacidad Cantidad máxima de bytes disponibles en el búfer destino.
 * @param origen Cadena que se desea copiar.
 *
 * @return true si la cadena de origen se copia completamente, incluyendo '\0'.
 *         false si la cadena no cabe completamente y es truncada, o si destino
           es nulo, origen es nulo o capacidad es 0.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Anexa el contenido de origen a continuación del texto existente en
          destino, respetando la capacidad disponible y asegurando el terminador
          nulo.
 *
 * @param destino Búfer que contiene el texto existente y donde se anexará 
                  el contenido de origen.
 * @param capacidad Cantidad máxima de bytes disponibles en el búfer destino.
 * @param origen Cadena que se desea anexar.
 *
 * @return true si todo el texto de origen se concatenó sin truncamiento.
 *         false si hubo truncamiento o alguno de los argumentos es inválido.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Convierte a mayúsculas todos los caracteres ASCII en minúscula de una 
          cadena, respetando el límite de capacidad y deteniéndose en '\0'.
 *
 * @param cadena cuyos caracteres se desean convertir.
 * @param capacidad Cantidad máxima de bytes que se pueden inspeccionar.
 *
 * @return Número total de conversiones efectuadas.
 *         Retorna 0 si la cadena es nula o la capacidad es 0
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);

/**
 * @brief Extrae una subcadena de una cadena origen en un búfer destino seguro.
 *
 * @pre 'destino' y 'origen' deben apuntar a espacios de memoria válidos.
 *      'capacidad' debe ser mayor que 0 para almacenar el resultado.
 *
 * @post Si 'inicio' supera la longitud de 'origen', 'destino' queda vacío.
 *       Si 'capacidad' es mayor que 0 y los argumentos son válidos,
 *       'destino' queda terminado en '\0'.
 *       Se copian como máximo 'cantidad' caracteres y 'capacidad - 1'
 *       caracteres útiles.
 *
 * @param destino Búfer donde se almacenará la subcadena extraída.
 * @param capacidad Cantidad máxima de bytes disponibles en 'destino',
 *                  incluido el terminador '\0'.
 * @param origen Cadena de la que se extraerá la subcadena.
 * @param inicio Posición inicial desde la que comenzará la extracción.
 * @param cantidad Número máximo de caracteres que se intentarán copiar.
 *
 * @return true si la subcadena se extrajo completamente o si 'inicio'
 *         supera la longitud de 'origen'.
 *         false si algún argumento es inválido o no hay capacidad suficiente
 *         para almacenar todos los caracteres solicitados.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);

// ^^^ TP2 ^^^




/**
 * @brief Crea una copia dinámica de una cadena.
 *
 * @post Se reserva en el heap el espacio necesario para almacenar la cadena
 *       y su terminador '\0'. El contenido de 'origen' permanece sin
 *       modificaciones.
 *
 * @param origen Cadena que se desea duplicar.
 * @param capacidad_max Cantidad máxima de bytes que se pueden inspeccionar
 *                      en 'origen'.
 *
 * @return Puntero al nuevo bloque que contiene la copia de 'origen'.
 *         Retorna NULL si 'origen' es NULL, 'capacidad_max' es 0 o falla
 *         la asignación de memoria.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);



/**
 * @brief Crea dinámicamente una cadena concatenando dos cadenas de origen.
 *
 * @post Se reserva en el heap el espacio necesario para contener el contenido
 *       de ambas cadenas y el terminador '\0'. Las cadenas de origen
 *       permanecen sin modificaciones.
 *
 * @param primera Cadena que formará parte del resultado.
 * @param cap_primera Cantidad máxima de bytes que se pueden inspeccionar
 *                    en 'primera'.
 * @param segunda Cadena que se anexará a 'primera'.
 * @param cap_segunda Cantidad máxima de bytes que se pueden inspeccionar
 *                    en 'segunda'.
 *
 * @return Puntero al nuevo bloque que contiene la concatenación de 'primera'
 *         y 'segunda'. Retorna NULL si algún argumento es inválido o falla
 *         la asignación de memoria.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);



/**
 * @brief Libera una cadena reservada dinámicamente y anula su puntero.
 *
 * @post Si 'puntero_cadena' y '*puntero_cadena' son válidos, se libera la
 *       memoria apuntada y '*puntero_cadena' queda establecido en NULL.
 *
 * @param puntero_cadena Dirección del puntero que apunta a la cadena
 *                       reservada dinámicamente.
 */
void cadena_liberar_segura(char **puntero_cadena);



/**
 * @brief Extrae una subcadena y la almacena en un nuevo bloque de memoria
 *        del heap.
 *
 * @param origen Cadena de la que se extraerá la subcadena.
 * @param capacidad_max Cantidad máxima de bytes que se pueden inspeccionar
 *                      en 'origen'.
 * @param inicio Posición desde la que comenzará la extracción.
 * @param cantidad Número máximo de caracteres que se intentarán extraer.
 *
 * @return Puntero a un nuevo bloque de memoria terminado en '\0' que contiene
 *         la subcadena extraída. Si 'inicio' alcanza o supera la longitud de
 *         'origen', retorna una cadena vacía almacenada en el heap. Retorna NULL
 *         si 'origen' es NULL, 'capacidad_max' es 0 o falla la asignación
 *         de memoria.
 */
 char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad);



/**
 * @brief Genera una copia invertida de una cadena en un nuevo bloque de
 *        memoria del heap.
 *
 * @post Se reserva en el heap el espacio necesario para almacenar la cadena
 *       invertida y el terminador '\0'. El contenido de 'origen' permanece
 *       sin modificaciones.
 *
 * @param origen Cadena cuyos caracteres se desean invertir.
 * @param capacidad_max Cantidad máxima de bytes que se pueden inspeccionar
 *                      en 'origen'.
 *
 * @return Puntero a un nuevo bloque de memoria terminado en '\0' que contiene
 *         los caracteres de 'origen' en orden inverso. Retorna NULL si
 *         'origen' es NULL, 'capacidad_max' es 0 o falla la asignación
 *         de memoria.
 */
 char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);
 
#endif 
